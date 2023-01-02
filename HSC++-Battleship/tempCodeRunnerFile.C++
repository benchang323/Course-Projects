//Battleship Benjamin Chang
#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;

//Feature 1 Player vs Player
//Feature 2 Input validation
//Feature 3 Computer vs Player
//Feature 4 Color-Graphics
//Feature 5 Tutorial
//Feature 6 Ship Size (You have to connect them)

int validation(int num, int min, int max);
void printbrd(int **oparr,int size);
void cover();
void AIrand(int **oparr,int size);
void set2(int**oparr,int size);
void attack2(int **oparr, int**arr2, int i, int j,int size, int count);
void attack2ac(int**oparr, int size, int x, int y);
void set(int **oparr,int size);
bool verify(int**oparr, int size);
void attack(int **oparr, int**arr2, int size, string name);

int main()
{
    srand(time(NULL));
    
    int mode;
    cout << "\033[32m" << "*-------------------------------------------------------------------------*" << "\033[0m" << endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl; 
    cout << "\033[32m" << "|                     Welcome to Benjamin's Battleship                    |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;   
    cout << "\033[32m" << "*-------------------------------------------------------------------------*" << "\033[0m" <<endl;
    cout << "\n";
    cout << "\033[32m" << "*-------------------------------------------------------------------------*" << "\033[0m" <<endl;
    cout << "\033[32m" << "| TUTORIAL                                                                |" << "\033[0m" <<endl; 
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;         
    cout << "\033[32m" << "|  - S means ship.                                                        |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - 0 is the ocean.                                                      |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - H means you have hit a target.                                       |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - M indicates you have missed.                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "| HOW TO PLAY?                                                            |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Shoot a location on the board trying to find the enemy's ship        |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Enter the location in the format of: row (space) column              |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Once all the enemy's ships have been sunk, you win.                  |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Have fun!                                                            |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "| SHIP SIZE                                                               |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Customize ship size by connecting them consecutively                 |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Carrier 5                                                            |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Battleship 4                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Cruiser 3                                                            |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Submarine 2                                                          |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Destroyer 2                                                          |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Patrol Boat 1                                                        |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  - Boats will be given in the form of patrol boat                       |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "| MODE                                                                    |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  1) Player vs AI                                                        |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|  2) Player vs Player                                                    |" << "\033[0m" <<endl;
    cout << "\033[32m" << "|                                                                         |" << "\033[0m" <<endl;
    cout << "\033[32m" << "*-------------------------------------------------------------------------*" << "\033[0m" <<endl; 
    cout << "\n";

    cout << "\033[32m" << "Please select mode: " << "\033[0m";
    cin>>mode;

    mode = validation(mode,1,3);


    int vicstat=0; //victory status

    while(true)
    {
        int size;

        cout << "\033[32m" << "Enter the size of the board (nxn): "<< "\033[0m";
        cin >> size;
        size = validation(size,2,100);

        int **playerbrd=new int *[size];

        for(int i=0;i<size;i++)
        { 
            playerbrd[i]= new int [size]; 
        }

        int **brd1= new int *[size];

        for(int i=0;i<size;i++)
        { 
            brd1[i]=new int [size];
    
        }
        
        int **refbrd=new int *[size];

        for(int i=0;i<size;i++)
        {
            refbrd[i]=new int [size];
        }

        int **brd2=new int *[size];

        for(int i=0;i<size;i++)
        {
            brd2[i]=new int [size];
        }

        cout << "\n";
        cout << "\033[32m" << "Player 1's board: "<< "\033[0m";
        set2(playerbrd,size);
        printbrd(playerbrd,size);
        set(playerbrd,size);
        set2(brd2,size);

        if(mode==1)
        {
            set2(brd1,size);
            AIrand(brd1,size);
            set2(refbrd,size);

            cout << "\n";
            cout << "\033[32m" << "Your board: "<< "\033[0m";
            printbrd(playerbrd,size);

            cout << "\n";
            cout << "\033[32m" << "Enemy Reference board: "<< "\033[0m";
            printbrd(refbrd,size);

            for(int count=1;count<=size*size;count++)
            {
                cout << "\n";
                cout << "\033[32m" << "Round " << count<< "\033[0m";

                attack(brd1, refbrd, size, "player");

                if(verify(brd1,size)==false)
                {
                    cout << "\n";
                    cout << "\033[32m" << "You have sunk the AI's ship."<< "\033[0m";
                    vicstat=1;
                    break;
                }

                cout << "\n";
                cout << "\033[32m" << "AI's turn: "<< "\033[0m";

                attack(playerbrd, brd2, size, "com");
                printbrd(playerbrd,size);

                if(verify(playerbrd,size)==false)
                {
                    printbrd(playerbrd,size);
                    cout << "\033[32m" << "AI has sunk your ship."<< "\033[0m";
                    vicstat=2;
                    break;
                }

            }
        }

        if(mode==2)
        {
            cover();

            cout << "\033[32m" << "Player 1's board:"<< "\033[0m";
            set2(brd1,size);
            printbrd(brd1,size);
            set(brd1,size);
            set2(refbrd,size);

            cover();

            for(int count=1;count<=size*size;count++)
            {
                cout << "\n";
                cout << "\033[32m" << "Round " << "\033[0m" << count;
                cout << "\n";
                cout << "\033[32m" << "Player 1's turn: " << "\033[0m";

                attack(brd1,refbrd,size,"player");

                if(verify(brd1,size)==false)
                {
                    cout << "\n";
                    cout << "\033[32m" << "Player 1 has sunk Player 2's ship!" << "\033[0m";
                    vicstat=1;
                    break;
                }

                cout << "\n";
                cout << "\033[32m" << "Player 2's turn: " << "\033[0m";

                attack(playerbrd,brd2,size,"player");

                if(verify(playerbrd,size)==false)
                {
                    cout << "\n";
                    cout << "\033[32m" << "Player 2 has sunk Player 1's ship!" << "\033[0m";
                    vicstat = 2;
                    break;
                }
            }
        }

        if(vicstat == 1)
        {
            cout << "\n";
            cout << "\033[32m" << "Player 1 wins." << "\033[0m";
        }

        if(vicstat == 2)
        {
            cout << "\n";
            cout << "\033[32m" << "Player 2 wins." << "\033[0m";
        }
    }
    return 0;
}

void attack(int **oparr, int**arr2, int size, string name)
{
    if(name=="player")
    {
        int i,j;

        cout << "\n";
        cout << "\033[32m" << "Please enter the location you want to attack: " << "\033[0m";
        cin>>i;
        i=validation(i, 1, size);
        cin>>j;
        i=validation(i, 1, size);
        attack2(oparr,arr2,i-1,j-1,size, 0);
    }

    else if(name=="com")
    {
        int x, y;
        x=rand()%(size-1);
        y=rand()%(size-1);

        while(oparr[x][y]==4||oparr[x][y]==3)
        {
            x=rand()%(size-1);
            y=rand()%(size-1);
        }

        if(oparr[x][y]==1)
        {
            oparr[x][y]=3;
            attack2ac(oparr, size, x, y);
        }

        else if (oparr[x][y]==2)
        {
            oparr[x][y]=4;
        }
  }
}

bool verify(int**oparr, int size)
{
    bool block=false;

    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size; j++)
        {
            if (oparr[i][j]==1)
            {
                block=true;
            }
        }
    }

  return block;
}

void set(int **oparr,int size)
{
    int row;
    int column;

    cout << "\n";
    cout << "\033[32m" << "You have a total of " << "\033[0m" << size << "\033[32m" << " ships." << "\033[0m";
    cout << "\n";

    for(int i=1; i<=size;i++)
    {
        cout << "\n";
        cout << "\033[32m" << "Ship " << "\033[0m" << i << "\033[32m" <<  ": " << "\033[0m";
        cin>>row;
        row=validation(row, 1, size);
        cin>>column;
        column=validation(column, 1, size);

        while(oparr[row-1][column-1]==1)
        {
            cout << "\n";
            cout << "\033[32m" << "Input a valid location!" << "\033[0m";
            cin >> row;
            row=validation(row, 1, size);
            cin >> column;
            column=validation(column, 1, size);
        }

    if(oparr[row-1][column-1]!=1)
    {
        oparr[row-1][column-1]=1;
    }

    printbrd(oparr,size);
  }
}

void attack2ac(int**oparr, int size, int x, int y)
{
    int z=rand()%2+1;

    if(z==2)
    {
        if(x+1<size)
        {
            x++;
        }
        else
        {
            x--;
        }
    }

    if(z==1)
    {
        if(y+1<size)
        {
            y++;
        }
        else
        {
            y--;
        }
    }

    if(oparr[x][y]==1)
    {
        oparr[x][y]=3;
        attack2ac(oparr, size, x, y);
    }

    else if (oparr[x][y]==2)
    {
        oparr[x][y]=4;
    }
}

void attack2(int **oparr, int**arr2, int i, int j,int size, int count)
{
    while(oparr[i][j]==3||oparr[i][j]==4)
    {
        cout << "\033[32m" << "Don't repeat your action!" << "\033[0m";
        cin>>i;
        i=validation(i, 1, size);
        cin>>j;
        i=validation(i, 1, size);
    }

    if (oparr[i][j]==1)
    {
        cout << "\033[32m" << "Hit!" << "\033[0m";
        oparr[i][j]=3;
        arr2[i][j]=3;
        printbrd(arr2,size);

        if(verify(oparr,size)==false)
        {
            return;
        }

        else
        {
            cout << "\n";
            cout << "\033[32m" << "Location: " << "\033[0m";
            cout << "\n";
            cin>> i;
            i=validation(i, 1, size);
            cin>>j;
            j=validation(j, 1, size);
            attack2(oparr, arr2, i-1,j-1,size,count);
            return;
        }
    }

    if (oparr[i][j]==2)
    {
        cout << "\033[32m" << "You missed." << "\033[0m";
        oparr[i][j]=4;
        arr2[i][j]=4;
        printbrd(arr2,size);
        return;
    }
}

void set2(int**oparr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            oparr[i][j]=2;
        }
    }
}

void AIrand(int **oparr,int size)
{
    srand(time(NULL));

    for(int i=0;i<size;i++)
    {

        int x,y;

        x=rand()%4+1;
        y=rand()%4+1;

        while(oparr[x-1][y-1]==1)
        {
            x=rand()%4+1;
            y=rand()%4+1;
        }

    oparr[x-1][y-1]=1;
  }
}

int validation(int num, int min, int max)
{
    while(num > max)
    {
        cout << "\033[32m" << "Please enter a valid choice! " << "\033[0m" << max << endl;
        cin >> num;
        num = validation(num,min,max);
    }

    while(num < min)
    {
        cout << "\033[32m" << "Please enter a valid choice! " << "\033[0m" << min << endl;
        cin >> num;
        num = validation(num,min,max);
    }

    return num;
}

void cover()
{
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
}

void printbrd(int **oparr,int size)
{
    cout << "\n";
    cout << "    ";
    for(int i=1;i<=size;i++)
    {
        if (i < 9)
        {
            cout << i << "  ";
        }

        if (i >= 9)
        {
            cout << i << " ";
        }
    }

    cout<<"\n";

    for(int i=1;i<=size;i++)
    {
        cout<< "\033[32m" << "****" << "\033[0m";
    }

    cout<<"\n";

    for (int i=0; i<size; i++)
    {
        if (i < 9)
        {
            cout << " " << i+1 << "  ";
        }

        if (i >= 9)
        {
            cout << " " << i+1 << " ";
        }

        for(int j=0; j<size; j++)
        {

            if (oparr[i][j]==2)
            {
                cout << "\033[34m" << "0  " << "\033[0m";
            }

            else if (oparr[i][j]==1)
            {
                cout << "\033[31m" << "S  " << "\033[0m";
            }

            else if (oparr[i][j]==3)
            {
                cout << "\033[33m" << "H  " << "\033[0m";
            }

            else if (oparr[i][j]==4)
            {
                cout << "\033[36m" << "M  " << "\033[0m";
            }

        }

    cout << "\n";

    }

    for(int i=1;i<=size;i++)
    {
        cout << "\033[32m" << "****" << "\033[0m";
    }

}