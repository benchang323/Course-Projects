import java.util.*;
public class Blackjack
{
    public static void main( String[] args )
    {
        int choice = intro();
        double wallet = 1000;
        
        int cont = 1;
        
        do
        {
            if (choice == 1)
            {
                rules();
                System.exit(0);
            }

            else if (choice == 2)
            {
                double bet = bet(wallet);
                int player = plaplay();
                int dealer;
                
                if (player < 0)
                {
                    System.out.println("\nYou lose :)) !");
                    wallet = (wallet - bet);
                    System.out.println("You now have $" + wallet);
                    System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                    Scanner kb = new Scanner(System.in);
                    while (!kb.hasNextInt()) 
                    {
                        System.out.println("That's not a number! You stupid.");
                        kb.next();
                    }
                    cont = kb.nextInt();
                    cont = inval_cont(cont);
                }

                else if (player > 0)
                {
                    System.out.println("\nDealer's turn!");
                    dealer = deaplay();
                    if (dealer >= player)
                    {
                        System.out.println("\nYou lose :) !");
                        wallet = (wallet - bet);
                        System.out.println("You now have $" + wallet);
                        System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                        Scanner kb = new Scanner(System.in);
                        while (!kb.hasNextInt()) 
                        {
                            System.out.println("That's not a number! You stupid.");
                            System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                            kb.next();
                        }
                        cont = kb.nextInt();
                        cont = inval_cont(cont);
                    }

                    else if (dealer < player && dealer > 0)
                    {
                        System.out.println("\nYou win :((!");
                        wallet = (wallet + bet);
                        System.out.println("You now have $" + wallet);
                        System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                        
                        Scanner kb = new Scanner(System.in);
                        while (!kb.hasNextInt()) 
                        {
                            System.out.println("That's not a number! You stupid.");
                            System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                            kb.next();
                        }
                        cont = kb.nextInt();
                        cont = inval_cont(cont);
                    }

                    else if (dealer < 0)
                    {
                        System.out.println("\nYou win :((!");
                        wallet = (wallet + bet);
                        System.out.println("You now have $" + wallet);
                        System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                        Scanner kb = new Scanner(System.in);
                        while (!kb.hasNextInt()) 
                        {
                            System.out.println("That's not a number! You stupid.");
                            System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                            kb.next();
                        }
                        cont = kb.nextInt();
                        cont = inval_cont(cont);
                    }
                }
            }

            else if (choice == 3)
            {
                System.exit(0);
            }

        } while (wallet > 0 && cont == 1 && choice > 1) ;

        System.out.println("Bye!");
        
    }
    
    public static double bet(double wallet)
    {
        System.out.println("\nHow much money would you like to bet? ");
        System.out.print("Your Amount: ");
        Scanner kb = new Scanner(System.in);
        while (!kb.hasNextInt()) 
        {
            System.out.println("That's not a number! You stupid.");
            System.out.print("Your Amount: ");
            kb.next();
        }
        double bet = kb.nextInt();
        return bet = inval_bet(bet, wallet);
    }

    public static int deaplay()
    {
        int[] arr1 = new int[21];
        
        for (int i = 0; i< arr1.length; i++)
        {
            int random = (int)(Math.random()*(1-1+1)+1);
            arr1[i] = random;
        }

        int deatot = 0;
        System.out.println("\nThe dealer just drew a " + arr1[0] + " and " + arr1[1]);
        deatot = (arr1[0] + arr1[1]);
        deatot = inval_deapara(deatot);
        int i = 2;
        
        while (deatot < 17 && deatot > 0)
        {
            deatot = arr1[i] + deatot;
            System.out.println("The dealer just drew a " + arr1[i] + " and has a total of: " + deatot);
            deatot = inval_deapara(deatot);
            i++;
        }
        System.out.println("The dealer stops!");
        return deatot;
    }

    public static int plaplay()
    {
        int[] arr = new int[21];
        
        for (int i = 0; i< arr.length; i++)
        {
            int random = (int)(Math.random()*(1-1+1)+1);
            arr[i] = random;
        }

        int platot = 0;
        int choice2 = 0;
        System.out.println("\nYou just drew a " + arr[0] + " and " + arr[1]);
        platot = (arr[0] + arr[1]);
        System.out.println("The total is: " + platot);
        platot = inval_plapara(platot);
        
        int i = 2;

        while (platot > 0 && choice2 != 2)
        {
            System.out.println("\nWould you like to 1) draw or 2) stay?");
            System.out.print("Your Choice: ");
            Scanner kb = new Scanner(System.in);
            while (!kb.hasNextInt()) 
            {
                System.out.println("That's not a number! You stupid.");
                System.out.print("Your Choice: ");
                kb.next();
            }
            choice2 = kb.nextInt();
            choice2 = inval_intro(choice2);

            if (choice2 == 1)
            {
                System.out.println("\nYou just draw a: " + arr[i]); //2..3...4
                platot = (platot + arr[i]);
                System.out.println("The total is: " + platot);
                platot = inval_plapara(platot);
                i++;
            }
            
            else if (choice2 == 2)
            {
                return platot = platot;
            }
        }
        return platot;
    }

    public static int intro()
    {
        System.out.println("+---------------------------------------------------------+");
        System.out.println("| Welcome to Benjamin's Casino. This is a Blackjack game! |");
        System.out.println("+---------------------------------------------------------+");
        System.out.println("| You currently have an initial amount of $1000           |");
        System.out.println("+---------------------------------------------------------+");
        System.out.println("| Which mode would you like to enter?                     |");
        System.out.println("| 1) See Rules                                            |");
        System.out.println("| 2) Play                                                 |");
        System.out.println("| 3) Quit                                                 |");
        System.out.println("+---------------------------------------------------------+");

        System.out.print("Your Choice: ");
        Scanner kb = new Scanner(System.in);
        
        while (!kb.hasNextInt()) 
        {
            System.out.println("That's not a number! You stupid.");
            System.out.print("Your Choice: ");
            kb.next();
        }

        int choice = kb.nextInt();
        return choice = inval_intro(choice);
    }

    public static void rules()
    {
        System.out.println("+---------------------------------------------------------------------------------------------+");
        System.out.println("| 1) The goal of blackjack is to beat the dealer's hand without going over 21.                |");
        System.out.println("| 2) Each player starts with two cards, one of the dealer's cards is hidden until the end.    |");
        System.out.println("| 3) To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn. |");
        System.out.println("| 4) If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.         |");
        System.out.println("| 5) If you are dealt 21 from the start (Ace & 10), you got a blackjack.                      |");
        System.out.println("| 6) Blackjack usually means you win 1.5 the amount of your bet.                              |");
        System.out.println("| 7) Dealer will hit until his/her cards total 17 or higher.                                  |");
        System.out.println("| QUIT AND RESTART!                                                                           |");
        System.out.println("+---------------------------------------------------------------------------------------------+");   
    }

    public static int inval_intro(int choice)
    {
        while (choice > 3 || choice < 1) //input validation
        {
            System.out.print("INVALID!");
            System.out.print("\nYour Choice: ");
            Scanner kb = new Scanner(System.in);
            while (!kb.hasNextInt()) 
            {
                System.out.println("That's not a number! You stupid.");
                System.out.print("\nYour Choice: ");
                kb.next();
            }
            choice = kb.nextInt();
        }
        return choice;
    }
    
    public static int inval_cont(int cont)
    {
        while (cont < 1 || cont > 2) //input validation
        {
            System.out.print("INVALID!");
            System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
            Scanner kb = new Scanner(System.in);
            while (!kb.hasNextInt()) 
            {
                System.out.println("That's not a number! You stupid.");
                System.out.print("Would you like 2 1) continue or 2) quit? Choice: ");
                kb.next();
            }
            cont = kb.nextInt();
        }
        return cont;
    }
    
    public static double inval_bet(double bet, double wallet)
    {
        while (bet < 0 || bet > wallet) //input validation
        {
            System.out.print("INVALID!");
            System.out.print("\nYour Amount: ");
            Scanner kb = new Scanner(System.in);
            while (!kb.hasNextInt()) 
            {
                System.out.println("That's not a number! You stupid.");
                System.out.print("\nYour Amount: ");
                kb.next();
            }
            bet = kb.nextInt();
        }
        return bet;
    }

    public static int inval_deapara(int deatot)
    {
        if (deatot > 21)
        {
            System.out.println("The dealer exploded. You are lucky.");
            deatot = -100;
            return deatot;
        }
        return deatot;
    }

    public static int inval_choice2 (int choice2)
    {
        while (choice2 > 2 || choice2 < 1) //input validation
        {
            System.out.print("INVALID!");
            System.out.print("\nYour Choice: ");
            Scanner kb = new Scanner(System.in);
            while (!kb.hasNextInt()) 
            {
                System.out.println("That's not a number! You stupid.");
                System.out.print("\nYour Choice: ");
                kb.next();
            }
            choice2 = kb.nextInt();
        }
        return choice2;
    }

    public static int inval_plapara(int platot)
    {
        if (platot > 21)
        {
            System.out.println("You have exploded! Better luck next time.");
            platot = -100;
            return platot;
        }

        return platot;
    }

}