package CheapestPath;
import java.util.*;
public class Program
{
    public static void main(String[] args) throws InterruptedException
    {
        ArrayList<ArrayList<Integer>> board = new ArrayList<ArrayList<Integer>>();
        Scanner sc = new Scanner(System.in);

        System.out.println("\n--------------------Welcome to Shortest Path--------------------");
        System.out.println("Please select the row size");
        System.out.print("> ");
        int row = sc.nextInt();
        System.out.println("\nPlease select the column size");
        System.out.print("> ");
        int col = sc.nextInt();
        System.out.println("----------------------------------------------------------------");
        System.out.println("This is your board:");
        board = setUpBoard(board, row, col);
        System.out.println("----------------------------------------------------------------");
        shortestPath(board);
        sc.close();
    }

    public static int[] findLocation(ArrayList<ArrayList<Integer>> board, int row, int col)
    {
        int[] newLocation = new int[2];

        if (row == board.size()-2 && col == board.get(row).size()-2) //Last step
        {
            newLocation[0] = board.size();
            newLocation[1] = board.get(row).size();
        }

        if (row == 0 && col == 0) //First Step
        {
            int right = board.get(row).get(col+1);
            int bottom = board.get(row+1).get(col); 
            if (right > bottom)
            {
                newLocation[0] = row + 1;
                newLocation[1] = col;
            }
            else if (right < bottom)
            {
                newLocation[0] = row;
                newLocation[1] = col + 1;
            }
        }

        if (col == board.get(row).size()-1 && row == 0) //UpRight
        {
            newLocation[0] = row + 1;
            newLocation[1] = col;
            return newLocation;
        }

        if(col == 0 && row == board.size()-1) //BottomLeft
        {
            newLocation[0] = row;
            newLocation[1] = col + 1;
            return newLocation;
        }

        if(col == 0) //StuckLeft
        {
            int right = board.get(row).get(col+1);
            int bottom = board.get(row+1).get(col); 
            if (right > bottom)
            {
                newLocation[0] = row + 1;
                newLocation[1] = col;
            }
            else if (right < bottom)
            {
                newLocation[0] = row;
                newLocation[1] = col + 1;
            }
            return newLocation;
        }
        else if(col == board.get(row).size()-1) //StuckRight
        {
            int bottom = board.get(row+1).get(col); 
            int left = board.get(row).get(col-1);
            if (left > bottom)
            {
                newLocation[0] = row + 1;
                newLocation[1] = col;
            }
            else if (left < bottom)
            {
                newLocation[0] = row;
                newLocation[1] = col-1;
            }
            return newLocation;
        }
        else if(row == 0) //StuckTop
        {
            int right = board.get(row).get(col+1);
            int bottom = board.get(row+1).get(col); 
            if (right > bottom)
            {
                newLocation[0] = row + 1;
                newLocation[1] = col;
            }
            else if (right < bottom)
            {
                newLocation[0] = row;
                newLocation[1] = col + 1;
            }
            return newLocation;
        }
        else if(row == board.size()-1) //StuckBottom
        {
            int right = board.get(row).get(col+1);
            int top = board.get(row-1).get(col);
            if (right > top)
            {
                newLocation[0] = row-1;
                newLocation[1] = col;
            }
            else if (right < top)
            {
                newLocation[0] = row;
                newLocation[1] = col + 1;
            }
            return newLocation;
        }   
        else //Not stuck
        {
            int right = board.get(row).get(col+1);
            int bottom = board.get(row+1).get(col); 
            if (right > bottom)
            {
                newLocation[0] = row + 1;
                newLocation[1] = col;
            }
            else if (right < bottom)
            {
                newLocation[0] = row;
                newLocation[1] = col + 1;
            }
            return newLocation;
        }
    }

    public static void shortestPath(ArrayList<ArrayList<Integer>> board) throws InterruptedException
    {
        int[] newLocation = new int[2];
        int row = 0;
        int col = 0;
        int count = 1;
        while (newLocation[0] != board.size() && newLocation[1] != board.get(newLocation[0]).size())
        {
            newLocation = findLocation(board, row, col);
            row = newLocation[0];
            col = newLocation[1];
            System.out.println("Next location (" + row + ", " + col + ") is " + board.get(row).get(col));
            Thread.sleep(500);
            if (row == board.size()-1 && col == board.get(row).size()-1)
            {
                break;
            }
            count++;
        }
        System.out.println("----------------------------------------------------------------");
        System.out.println("The shortest path is in " + count + " steps.");
        System.out.println("----------------------------Goodbye-----------------------------");
        System.exit(0);
    }

    public static ArrayList<ArrayList<Integer>> setUpBoard(ArrayList<ArrayList<Integer>> board, int row, int col) 
    {
        for (int i = 0; i < row; i++)
        {
            board.add(new ArrayList<Integer>());
            for (int j = 0; j < col; j++)
            {
                board.get(i).add((int)(Math.random()*(100-(-100)+1))+(-100));
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.get(i).size(); j++)
            {
                System.out.print(board.get(i).get(j) + "\t");
            }
            System.out.println();
        }
        return board;
    }
}