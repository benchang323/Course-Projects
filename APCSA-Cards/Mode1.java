package Cards;
import java.util.*;
public class Mode1 
{
    public static void main(String[] args) 
    {
        Scanner kb = new Scanner(System.in);
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

        for (int i = 0; i < numCards/2; i++) //The game
        {
            System.out.println("\n+--------------------------------------Round " + (count+1) + "--------------------------------------+");

            displayDeck(playDeck); //Player 1
            System.out.println("\n\nPlayer 1, choose a card from the left end (L) or the right end (R) (Choose '0' if none): ");
            String choice1 = kb.next();
            player1 = scoresMode1(choice1, player1, playDeck);
            playDeck = removeDeckMode1(choice1, playDeck);

            displayDeck(playDeck); //Player 2
            System.out.println("\n\nPlayer 2, choose a card from the left end (L) or the right end (R) (Choose '0' if none): ");
            String choice2 = kb.next();
            player2 = scoresMode1(choice2, player2, playDeck);
            playDeck = removeDeckMode1(choice2, playDeck);

            statusUpdate(player1, player2);
            count++;
            System.out.println("\n+-----------------------------------------------------------------------------------+");
        }
        selectWinner(player1, player2);
        
        kb.close();
    }

    public static int scoresMode1(String choice, int playerScore, ArrayList<String> playDeck)
    {
        if (choice.equals("L"))
        {
            playerScore += Integer.parseInt(playDeck.get(0).substring(0,2));
        }
        else if (choice.equals("R"))
        {
            playerScore += Integer.parseInt(playDeck.get(playDeck.size()-1).substring(0,2));
        }
        else if (choice.equals("0"))
        {
            playerScore += 0;
        }
        return playerScore;
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
    
    public static ArrayList<String> removeDeckMode1(String choice1, ArrayList<String> playDeck)
    {
        if (choice1.equals("L"))
        {
            playDeck.remove(playDeck.get(0));
        }
        else if (choice1.equals("R"))
        {
            playDeck.remove(playDeck.get(playDeck.size()-1));
        }
        return playDeck;
    }
}
