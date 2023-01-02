package Elevens;
import java.util.*;
public class Main 
{
    public static void main(String[] args)
    {
        Scanner kb = new Scanner(System.in);
        ArrayList<String> playDeck = new ArrayList<String>();
        ArrayList<String> fullDeck = new ArrayList<String>();
        ArrayList<String> removedDeck = new ArrayList<String>();
        ArrayList<ArrayList<String>> data = new ArrayList<ArrayList<String>>();
        Deck a = new Deck();
        int round = 0;
        int status = 1;

        Collections.addAll(fullDeck, a.getShuffle());
        data.add(playDeck);
        data.add(fullDeck);
        data.add(removedDeck);
        
        System.out.println("\n+-----------------------Welcome to Elevens!-----------------------+");

        while (data.get(1).size() > 0 && status != 0)
        {
            System.out.println("\n+-----------------------------Round " + (round+1) + "-----------------------------+");
            data = fillDeck(data);

            System.out.println("\nHere is the current deck:");
            displayDeck(data);
            
            System.out.println("\n\nHere is the current deck after removing J, Q, and K:");
            data = findJQK(data);
            displayDeck(data);

            System.out.println("\n\nHere is the current deck after removing sums:");
            data = findSum(data);
            displayDeck(data);

            round++;
            System.out.println("\n\n+-----------------------------------------------------------------+");
            status = statusCheck(data);
        }

        System.out.println("\nYour score is: " + getScore(data));
        System.out.println("\n+----------------------Thanks for playing!------------------------+");
        kb.close();
    }

    public static int statusCheck(ArrayList<ArrayList<String>> data)
    {
        data = findJQK(data);
        data = findSum(data);
        
        if (data.get(0).size() == 9)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    public static int getScore(ArrayList<ArrayList<String>> data)
    {
        int sum = 0;

        for (int i = 0; i < data.get(2).size(); i++)
        {
            sum += Integer.parseInt(data.get(2).get(i).substring(0, 2));
        }

        return sum;
    }

    public static ArrayList<ArrayList<String>> findSum(ArrayList<ArrayList<String>> data) 
    {
        for (int i = 0; i < data.get(0).size(); i++)
        {
            for (int j = 0; j < data.get(0).size(); j++)
            {
                int num1 = Integer.parseInt(data.get(0).get(i).substring(0, 2));
                int num2 = Integer.parseInt(data.get(0).get(j).substring(0, 2));

                if ((num1 + num2) == 11)
                {
                    data.get(2).add(data.get(0).get(i));
                    data.get(2).add(data.get(0).get(j));

                    data.get(0).remove(j);
                    data.get(0).remove(i);
                }
            }
        }
        return data;
    }

    public static ArrayList<ArrayList<String>> findJQK(ArrayList<ArrayList<String>> data)
    {
        int[] store = new int[6];
        
        for (int i = 0; i < data.size(); i++)
        {
            int getNumber = Integer.parseInt(data.get(0).get(i).substring(0, 2));

            if (store[0] != 11)
            {   
                if (getNumber == 11)
                {
                    store[0] = getNumber;
                    data.get(2).add(data.get(0).get(i));
                    store[3] = i;
                }
            }

            if (store[1] != 12)
            {
                if (getNumber == 12)
                {
                    store[1] = getNumber;
                    data.get(2).add(data.get(0).get(i));
                    store[4] = i;
                }
            }

            if (store[2] != 13)
            {
                if (getNumber == 13)
                {
                    store[2] = getNumber;
                    data.get(2).add(data.get(0).get(i));
                    store[5] = i;
                }
            }
        }
        System.out.println(store[0] + " " + store[1] + " " + store[2]);

        if (store[0] == 11 && store[1] == 12 && store[2] == 13)
        {
            data.get(0).remove(store[3]);
            data.get(0).remove(store[4]);
            data.get(0).remove(store[5]);
        }
        
        for (int i = 0; i < store.length; i++)
        {
            store[i] = 0;
        }

        return data;

        /*
        for (int i = 0; i < data.get(0).size()-1; i++)
        {
            for (int j = 0; j < data.get(0).size(); j++)
            {
                int getNumber = Integer.parseInt(data.get(0).get(j).substring(0, 2));

                if (getNumber == 11 || getNumber == 12 || getNumber == 13)
                {
                    data.get(2).add(data.get(0).get(j));
                    data.get(0).remove(j);
                }
            }
        }
        return data;
        */
    } 

    public static ArrayList<ArrayList<String>> fillDeck(ArrayList<ArrayList<String>> data)
    {
        for (int i = data.get(0).size(); i < 9; i++)
        {
            data.get(0).add(data.get(1).get(i)); //ERROR
            data.get(1).remove(i);
            if (data.get(1).size() == 0)
            {
                System.out.println("No more cards!");
            }
        }
        return data;
    }   

    public static void displayDeck(ArrayList<ArrayList<String>> data)
    {
        System.out.print("| ");
        for (int j = 0; j < data.get(0).size(); j++)
        {
            System.out.print(data.get(0).get(j) + " | ");
        }
    }
}