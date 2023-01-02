package Cards;
import java.util.*;
public class Mode3 //20% There are two computer players, both will select to create the highest score. (recursion)
{
    public static void main(String[] args) 
    {
        Deck originalArrDeck = new Deck();
        ArrayList<String> playDeck = new ArrayList<String>();
        Collections.addAll(playDeck, originalArrDeck.getShuffle());
    
        int[] scores = {0, 0};
        playDeck = playDeck(playDeck); 
        scores = play(getLoops(playDeck.size(), playDeck), playDeck, scores);
        selectWinner(scores[0], scores[1]);
    }

    public static int[] play(int loops, ArrayList<String> playDeck, int[] scores)
    {
        while (loops > 0 && playDeck.size() > 0)
        {
            System.out.println("\n+--------------------------------------Round " + loops + "--------------------------------------+");
            displayDeck(playDeck); //Player 1
            if (playDeck.size() == 1)
            {
                scores[0] += Integer.parseInt(playDeck.get(0).substring(0,2));
                System.out.println("\nPlayer 1 chooses " + playDeck.get(0));
                playDeck.remove(playDeck.get(0));
            }
            else if (playDeck.size() == 0)
            {
                scores[0] += 0;
                System.out.println("\nPlayer 1 chooses 0");
            }
            else if (playDeck.size() > 1)
            {
                int option1 = Integer.parseInt(playDeck.get(0).substring(0,2));
                int option2 = Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                if (option1 > option2)
                {
                    scores[0] += Integer.parseInt(playDeck.get(0).substring(0,2));
                    System.out.println("\nPlayer 1 chooses " + playDeck.get(0));
                    playDeck.remove(playDeck.get(0));
                }
                else if (option1 < option2)
                {
                    scores[0] += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 1 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
                else if (option1 == option2)
                {
                    scores[0] += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 1 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
            }

            displayDeck(playDeck); //Player 2
            if (playDeck.size() == 1)
            {
                scores[1] += Integer.parseInt(playDeck.get(0).substring(0,2));
                System.out.println("\nPlayer 2 chooses " + playDeck.get(0));
                playDeck.remove(playDeck.get(0));
            }
            else if (playDeck.size() == 0)
            {
                scores[1] += 0;
                System.out.println("\nPlayer 2 chooses 0");
            }
            else if (playDeck.size() > 1)
            {
                int option1 = Integer.parseInt(playDeck.get(0).substring(0,2));
                int option2 = Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                if (option1 > option2)
                {
                    scores[1] += Integer.parseInt(playDeck.get(0).substring(0,2));
                    System.out.println("\nPlayer 2 chooses " + playDeck.get(0));
                    playDeck.remove(playDeck.get(0));
                }
                else if (option1 < option2)
                {
                    scores[1] += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 2 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
                else if (option1 == option2)
                {
                    scores[1] += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
                    System.out.println("\nPlayer 2 chooses " + playDeck.get(playDeck.size()-1));
                    playDeck.remove(playDeck.get(playDeck.size()-1));
                }
            }
            statusUpdate(scores[0], scores[1]);
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
        System.out.println("\n\nCurrent points for player 1: " + player1);
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
