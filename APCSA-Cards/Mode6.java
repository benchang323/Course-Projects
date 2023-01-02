package Cards;
import java.util.*;
public class Mode6 //+50% There are n computer players that both will select to win
{
    public static void main(String[] args) 
    {
        Deck originalArrDeck = new Deck();
        ArrayList<String> playDeck = new ArrayList<String>();
        Collections.addAll(playDeck, originalArrDeck.getShuffle());

        System.out.println("Enter number of computer players: ");
        Scanner input = new Scanner(System.in);
        int choice = input.nextInt();
        input.close();
        int[] scores = new int[choice];

        playDeck = playDeck(playDeck); 
        scores = play(getLoops(playDeck.size(), playDeck), playDeck, scores);
        selectWinner(scores);
    }

    public static int dumbAI(int option1, int option2, int option3, int option4)
    {
        int choice = 0;
        if (option3 > option4)
        {
            if (option2 > option1)
            {
                choice = 2;
            }
            else if (option1 > option2)
            {
                choice = 2;
            }
            else
            {
                choice = 1;
            }
        }
        else if (option3 < option4)
        {
            if (option2 > option1)
            {
                choice = 1;
            }
            else if (option1 > option2)
            {
                choice = 1;
            }
            else
            {
                choice = 2;
            }
        }
        else if (option3 == option4)
        {
            if (option2 > option1)
            {
                choice = 2;
            }
            else if (option1 > option2)
            {
                choice = 1;
            }
            else if(option1 == option2)
            {
                choice = 1;
            }
        }  
        else
        {
            choice = 1;
        }
        return choice;
    }

    public static int[] play(int loops, ArrayList<String> playDeck, int[] scores)
    {
        

        while (loops > 0 && playDeck.size() > 0)
        {
            System.out.println("\n+--------------------------------------Round " + (loops-2) + "--------------------------------------+");
            
            for (int i = 1; i < scores.length+1; i++)
            {
                displayDeck(playDeck);
                if (playDeck.size() == 1)
                {
                    scores[i-1] += Integer.parseInt(playDeck.get(0).substring(0,2));
                    System.out.println("\nPlayer 1 chooses " + playDeck.get(0));
                    playDeck.remove(playDeck.get(0));
                }
                else if (playDeck.size() == 0)
                {   
                    scores[i-1] += 0;
                    System.out.println("\nPlayer " + i + " chooses 0");
                }
                else if (playDeck.size() > 1)
                {
                    int option1 = Integer.parseInt(playDeck.get(0).substring(0,2));
                    int option3 = Integer.parseInt(playDeck.get(1).substring(0,2));
                    int option2 = Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    int option4 = Integer.parseInt(playDeck.get(playDeck.size()-2).substring(0,2));
                    int choice = dumbAI(option1, option2, option3, option4);
                    if (choice == 1)
                    {
                        scores[i-1] += Integer.parseInt(playDeck.get(0).substring(0,2));
                        System.out.println("\nPlayer " + i + " chooses " + playDeck.get(0));
                        playDeck.remove(playDeck.get(0));
                    }
                    else if (choice == 2)
                    {
                        scores[i-1] += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                        System.out.println("\nPlayer " + i + " chooses " + playDeck.get(playDeck.size()-1));
                        playDeck.remove(playDeck.get(playDeck.size()-1));
                    }
                    else if (choice == 3)
                    {
                        scores[i-1] += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                        System.out.println("\nPlayer " + i + " chooses " + playDeck.get(playDeck.size()-1));
                        playDeck.remove(playDeck.get(playDeck.size()-1));
                    }
                }
            }
            statusUpdate(scores);
            System.out.println("\n+-----------------------------------------------------------------------------------+");
            loops--;
            play(loops, playDeck, scores);
        }
        return scores;
    }

    public static int getLoops(int numCards, ArrayList<String> playDeck)
    {
        numCards = playDeck.size();
        if (playDeck.size()%2 != 0)
        {
            numCards = playDeck.size()+1;
        }
        numCards /= 2;

        return numCards;
    }

    public static ArrayList<String> playDeck(ArrayList<String> oldPlayDeck)
    {
        Scanner kb = new Scanner(System.in);
        ArrayList<String> newPlayDeck = new ArrayList<String>();

        System.out.print("\nEnter the amount of cards to play: ");
        int numCards = kb.nextInt();

        for (int i = 0; i < numCards; i++) //Calculates amount of cards to store
        {
            newPlayDeck.add(oldPlayDeck.get(i));
        }
        kb.close();
        return newPlayDeck;
    }       

    public static void selectWinner(int[] scores)
    {
        int player = largest(scores);
        System.out.println("\nPlayer " + (player+1) + " wins!");
        System.out.println("\n+-----------------------------------------------------------------------------------+");
    }

    public static int largest(int[] arr)
    {
        int i;
        int max = arr[0];
        int index = 0;
        for (i = 1; i < arr.length; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                index = i;
            }
        }
        return index;
    }

    public static void statusUpdate(int[] scores)
    {
        System.out.println("\n");
        for (int i = 0; i < scores.length; i++)
        {
            System.out.println("Current points for player " + (i+1) + " : " + scores[i]);
        }
    }

    public static void displayDeck(ArrayList<String> deck)
    {
        System.out.println("\nHere is the curret deck: ");
        for (int j = 0; j < deck.size(); j++)
        {
            System.out.print(deck.get(j) + " | ");
        }
    }
}
