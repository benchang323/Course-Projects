package Cards;
import java.util.*;
public class Mode2 
{
    public static void main(String[] args) 
    {     
        Deck originalArrDeck = new Deck();
        ArrayList<String> playDeck = new ArrayList<String>();
        Collections.addAll(playDeck, originalArrDeck.getShuffle());

        playDeck = playDeck(playDeck);

        int player1 = 0, player2 = 0, count = 0;
        int numCards = playDeck.size();
        if (numCards%2 != 0)
        {
            numCards++;
        }

        for (int i = 0; i < numCards/2; i++)
        {
            System.out.println("\n+--------------------------------------Round " + (count+1) + "--------------------------------------+");

            displayDeck(playDeck); //Player 1
            if (playDeck.size() == 1)
            {
                player1 += Integer.parseInt(playDeck.get(0).substring(0,2));
                System.out.println("\nPlayer 1 chooses " + playDeck.get(0));
                playDeck.remove(playDeck.get(0));
            }
            else if (playDeck.size() == 0)
            {
                player1 += 0;
                System.out.println("\nPlayer 1 chooses 0");
            }
            else if (playDeck.size() > 1)
            {
                int option1 = Integer.parseInt(playDeck.get(0).substring(0,2));
                int option2 = Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                if (option1 > option2)
                {
                    player1 += Integer.parseInt(playDeck.get(0).substring(0,2));
                    System.out.println("\nPlayer 1 chooses " + playDeck.get(0));
                    playDeck.remove(playDeck.get(0));
                }
                else if (option1 < option2)
                {
                    player1 += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 1 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
                else if (option1 == option2)
                {
                    player1 += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 1 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
            }
            
            displayDeck(playDeck); //Player 2
            if (playDeck.size() == 1) 
            {
                player2 += Integer.parseInt(playDeck.get(0).substring(0,2));
                System.out.println("\nPlayer 2 chooses " + playDeck.get(0));
                playDeck.remove(playDeck.get(0));
            }
            else if (playDeck.size() == 0)
            {
                player2 += 0;
                System.out.println("\nPlayer 2 chooses 0");
            }
            else if (playDeck.size() > 1)
            {
                int option1 = Integer.parseInt(playDeck.get(0).substring(0,2));
                int option2 = Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                if (option1 > option2)
                {
                    player2 += Integer.parseInt(playDeck.get(0).substring(0,2));
                    System.out.println("\nPlayer 2 chooses " + playDeck.get(0));
                    playDeck.remove(playDeck.get(0));
                }
                else if (option1 < option2)
                {
                    player2 += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 2 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
                else if (option1 == option2)
                {
                    player2 += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 2 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
            }
            statusUpdate(player1, player2); 
            System.out.println("\n+-----------------------------------------------------------------------------------+");
            count++;
        }
        selectWinner(player1, player2);          
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

    public static void selectWinner(int player1, int player2)
    {
        if (player1 > player2) //Announce winner
        {
            System.out.println("\nPlayer 1 wins!");
            System.out.println("\n+-----------------------------------------------------------------------------------+");
        }
        else if (player1 < player2)
        {
            System.out.println("\nPlayer 2 wins!");
            System.out.println("\n+-----------------------------------------------------------------------------------+");
        }
        else if (player1 == player2)
        {
            System.out.println("\nTie!");
            System.out.println("\n+-----------------------------------------------------------------------------------+");
        } 
    }

    public static void statusUpdate(int player1, int player2)
    {
        System.out.println("\nCurrent points for player 1: " + player1);
        System.out.println("Current points for player 2: " + player2); 
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