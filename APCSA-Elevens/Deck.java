package Elevens;
public class Deck 
{
    static String[] suit = {"Clubs", "Diamonds", "Hearts", "Spades"};
    static String[] rank = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13"};
    final static int n = suit.length * rank.length;
    static String[] deck = new String[n];

    public Deck()
    {
        for (int i = 0; i < rank.length; i++) 
        {
            for (int j = 0; j < suit.length; j++) 
            {
                deck[suit.length*i + j] = rank[i] + " of " + suit[j];
            }
        }
    }

    public String[] getShuffle()
    {
        for (int i = 0; i < n; i++) 
        {
            String temp = deck[i + (int) (Math.random() * (n-i))];
            deck[i + (int) (Math.random() * (n-i))] = deck[i];
            deck[i] = temp;
        }
        return deck;
    }

    public void getDeck()
    {
        for (int i = 0; i < n; i++) 
        {
            System.out.println(deck[i]);
        }
    }
}