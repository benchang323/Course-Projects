//Final Project-Minesweeper Benjamin Chang
//Feature 4 Color (ND)
/* *-------------------------------------------------READ ME DOCUMENT--------------------------------------------------* 
   |   • To know how to use this program, please refer to the tutorial that is in multiple languages.                  |
   |   • Problems: While I was coding this program, a big problem I'd face was the implementation of pointers in the   |
   |               code. I had a bit of trouble defining a global variable from the user input; however, consulting Mr.|
   |               Ting has solved my problem. Lastly, the problem I've faced is the recursion mode. The internet have |
   |               saved me from multiple errors, and I have learned the esseence of recursion algorithm.              |
   |   •Differently: I would have tried multiple arrays/pointers if I am more familiar with it next time.              |
   |                 Also, I would like to make my code shorter and more concise                                       |
   *-------------------------------------------------READ ME DOCUMENT--------------------------------------------------* */
//fix input val
#include <iostream> 
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std; //replace std::

#define SIDENUMMAX 100 //maximum amount of size that can be created
#define MINENUMMAX 1000//maximum amounts of mines placed in the game
#define MVESIZE 10000 //maximum amounts of movements for this game

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int size, mine; //Global integer of the board size and amount of mine

//The functions of these functions would be defined at the location of the code
void play(); 
bool verify(int row, int col); 
bool verifymine(int row, int col, char board[][SIDENUMMAX]); 
bool playrecur(char playerbrd[][SIDENUMMAX], char ansbrd[][SIDENUMMAX], int mines[][2], int row, int col, int *shiftl); 
int loser(); 
int noob(); 
int beginner(); 
int intermediate(); 
int advanced(); 
int professional(); 
int god();
int customize(); 
int tutorial(); 
void selectmode();
int levelcho(); 
int nearbymine (int row, int col, int mines[][2], char ansbrd[][SIDENUMMAX]); 
void welcome();
void plantmine(int mines[][2], char ansbrd[][SIDENUMMAX]); 
void move(int *x, int *y); 
void disboard(char playerbrd[][SIDENUMMAX]); 
void setup(char ansbrd[][SIDENUMMAX], char playerbrd[][SIDENUMMAX]); 
void chgmine(int row, int col, char board[][SIDENUMMAX]); 
void reveal(char ansbrd[][SIDENUMMAX]);
void answer(char ansbrd[][SIDENUMMAX]);
void disboard2(char flagbrd[][SIDENUMMAX]);


int main() //Program runs here
{
    welcome();
    cout << "\n";
    selectmode();
    cout << "\n";
    levelcho();

    return 0;
}

void disboard2(char flagbrd[][SIDENUMMAX]) //display the flag board
{
    
    cout << "       ";
    
    for (int i=0; i<size; i++) 
    {
        cout << i << "    ";
    }

    cout << "\n";
    cout << "      ";

    for (int i=0; i<size; i++)
    {
        cout << " _   " ;
    }
  
    cout << "\n";
  
    for (int i=0; i<size; i++) 
    { 

        cout << i << "   |  " ;

        for (int j=0; j<size; j++) 
        {
           cout << flagbrd[i][j]<< "    " ;
        } 
        
        cout << "\n";
    }
    return;
} 

void play() //Play Minesweeper
{
    bool endgame = false; //End Game status
  
    char ansbrd[SIDENUMMAX][SIDENUMMAX], playerbrd[SIDENUMMAX][SIDENUMMAX]; //answer and player boards
  
    int shiftl = size * size - mine, x, y; 
    int mines[MINENUMMAX][2]; //coordinates
  
    setup(ansbrd, playerbrd); //setup board
  
    plantmine(mines, ansbrd); //place mines
  
    int go = 0; 
    while (endgame == false) //continue the game
     { 
        cout << "\n";
        cout << GREEN << "Current Game: " << RESET <<endl; 
        cout << "\n";
        disboard(playerbrd); //display the board
        move(&x, &y); //movement
        
        if (go == 0) //first move no mine
        { 
            if (verifymine(x, y, ansbrd) == true) //verify if there is a mine at the selected sell
            {
                chgmine(x, y, ansbrd); //replace the mine
            }
        } 
  
        go ++; 
  
        endgame = playrecur(playerbrd, ansbrd, mines, x, y, &shiftl); //Play using recursion
  
        if ((endgame == false) && (shiftl == 0)) //See status of game
         { 
            answer(ansbrd);
            cout << YELLOW << "Congratulations! You have solved the puzzle." << RESET; //You win
            cout << "\n";
            cout << YELLOW << "Time elapsed: " << RESET << clock() << YELLOW << " clicks." << RESET << endl; //display time
            endgame = true; 
         } 
    } 
    return; 
}

void answer(char ansbrd[][SIDENUMMAX]) //display mines
{ 
    cout << GREEN << "Here are the location of the mines: " << RESET << endl; 
    disboard(ansbrd); //display board
    return; 
}

bool verify(int row, int col) //verify cells
{
    return (row >= 0) && (row < size) && (col >= 0) && (col < size); 
}

bool verifymine(int row, int col, char board[][SIDENUMMAX]) //verify mines
{
    if (board[row][col] == '*') 
    {
        return (true); 
    }
    else
    {
        return (false); 
    }
}

bool playrecur(char playerbrd[][SIDENUMMAX], char ansbrd[][SIDENUMMAX], int mines[][2], int row, int col, int *shiftl) //using recursion to play the game
{

    if (playerbrd[row][col] != '-')
    {
        return (false);
    } 
  
    int i, j; 
  
    if (ansbrd[row][col] == '*') 
    { 
        playerbrd[row][col]='*'; 
  
        for (i=0; i<mine; i++)
        {
            playerbrd[mines[i][0]][mines[i][1]]= '*';
        }
  
        disboard(playerbrd); 

        cout << RED << "You have been bombed by the landmine. Revive and try again!" << RESET; //You lose
        cout << "\n";
        cout << RED << "Time elapsed: " << RESET << clock() << RED << " clicks." << RESET << endl;
        return (true); 
    } 
  
    else //calculate numbers and display (the calculation part)
     { 
        int count = nearbymine(row, col, mines, ansbrd); 
        
        (*shiftl)--; 
  
        playerbrd[row][col] = count + '0'; 
  
        if (!count) 
        { 
            if (verify(row-1, col) == true) //upper
            { 
                if (verifymine(row-1, col, ansbrd) == false) 
                {
                    playrecur(playerbrd, ansbrd, mines, row-1, col, shiftl); 
                }
                   
            } 
  
            if (verify (row+1, col) == true) //lower
            { 
                if (verifymine(row+1, col, ansbrd) == false)
                {
                    playrecur(playerbrd, ansbrd, mines, row+1, col, shiftl);
                }
 
            } 
  
            if (verify (row, col+1) == true) //right
            { 
                if (verifymine(row, col+1, ansbrd) == false) 
                {
                    playrecur(playerbrd, ansbrd, mines, row, col+1, shiftl); 
                }
            } 
 
            if (verify (row, col-1) == true) //left
            { 
                if (verifymine(row, col-1, ansbrd) == false)
                {
                    playrecur(playerbrd, ansbrd, mines, row, col-1, shiftl);
                }
 
            } 
  
            if (verify (row-1, col+1) == true) //up right
            { 
                if (verifymine(row-1, col+1, ansbrd) == false)
                {
                    playrecur(playerbrd, ansbrd, mines, row-1, col+1, shiftl); 
                }
            } 
  
            if (verify (row-1, col-1) == true) //up left
            { 
                if (verifymine (row-1, col-1, ansbrd) == false)
                {
                    playrecur(playerbrd, ansbrd, mines, row-1, col-1, shiftl); 
                }
            } 

            if (verify (row+1, col+1) == true) //down right
            { 
                if (verifymine (row+1, col+1, ansbrd) == false) 
                {
                    playrecur(playerbrd, ansbrd, mines, row+1, col+1, shiftl); 
                }
            } 
  
            if (verify (row+1, col-1) == true) //down left
            { 
                if (verifymine (row+1, col-1, ansbrd) == false)
                {
                    playrecur(playerbrd, ansbrd, mines, row+1, col-1, shiftl); 
                }
            } 
        } 
        return (false); 
    } 
}

int loser() //loser mode
{
    size = 3;
    mine = 1;
    play();
}

int noob() //noob mode
{
    size = 6;
    mine = 3;
    play();
}

int beginner() //beginner mode
{
    size = 9;
    mine = 10;
    play();
}

int intermediate() //intermediate mode
{
    size = 15;
    mine = 40;
    play();
}

int advanced() //advanced mode
{
    int size = 21;
    int mine = 99;
    play();
}

int professional() //professional mode
{
    size = 25;
    mine = 150;
    play();
}

int god() //god mode
{
    size = 51;
    mine = 250;
    play();
}

int customize() //customize mode
{
    int side, minein;
    cout << GREEN << "You have created a big trouble for the programmers by choosing this mode. " << RESET << endl;
    cout << GREEN << "Please enter the side legth or your rectangular mineswepper board: " << RESET;
    
    cin >> side;

    size = side;


    cout << "\n";
    cout << GREEN << "Please enter how many mines you would like to have: " << RESET;
    
    cin >> minein;

    mine = minein;
    
}

int tutorial() //tutorial
{
    string lang; //choose language

    cout << GREEN << "Please choose your language (Powered by Google): " << RESET << endl;
    cout << GREEN << "1) Chinese " << RESET << endl;
    cout << GREEN << "2) English " << RESET << endl;
    cout << GREEN << "3) Spanish " << RESET << endl;
    cout << GREEN << "4) French  " << RESET << endl;
    cout << GREEN << "5) Korean " << RESET << endl;
    cout << GREEN << "6) Japanese  " << RESET << endl;
    cout << GREEN << "7) Russian " << RESET << endl;
    cout << "\n";
    cout << GREEN << "Choice: "<< RESET ;
    cin >> lang;

    while( lang != "1" && lang != "2" && lang != "3" && lang != "4" && lang != "5" && lang != "6" && lang != "7")
    {
        cout << "Enter a valid selection! \n";
        cout << "\n";
        cout << GREEN << "Choice: "<< RESET ;
        cin >> lang;
        cout << "\n";
        
        if( lang == "1" && lang == "2" && lang == "3" && lang == "4" && lang == "5" && lang == "6" && lang == "7")
        {
            if (lang=="1")
            {
                cout << BLUE << "*----------------------------------------------------------------*" << RESET << endl;
                cout << BLUE << "| 規則/教程                                                       " << RESET << endl;
                cout << BLUE << "|                                                                " << RESET << endl;
                cout << BLUE << "| 1. 從任意一個隨機位置開始。                                        " << RESET << endl;
                cout << BLUE << "| 2. 數字是與街區相鄰的地雷                                          " << RESET << endl;
                cout << BLUE << "| 3. 標記所有炸彈並清除所有空白區域                                   " << RESET << endl;
                cout << BLUE << "| 4. 玩得開心!!!                                                  " << RESET << endl;
                cout << BLUE << "|                                                                " << RESET << endl;
                cout << BLUE << "| 輸入                                                            " << RESET << endl;
                cout << BLUE << "|                                                                " << RESET << endl;
                cout << BLUE << "| 1. 程序將要求您輸入行和列（行，列。 請輸入為 行（空格）列。             " << RESET << endl;                                            
                cout << BLUE << "|                                                                " << RESET << endl;
                cout << BLUE << "*----------------------------------------------------------------*" << endl;
                cout << BLUE << "現在請開始享受！";
                cout << endl;
            }   //chinese mode

            else if (lang=="2")
            {
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"| RULES/TUTORIAL                                                " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. Start by clicking at any random place.                     " << RESET << endl;
                cout << BLUE <<"| 2. The number is the mines adjacent to the block.             " << RESET << endl;
                cout << BLUE <<"| 3. Mark all the bombs and clear out all the the empty area.   " << RESET << endl;
                cout << BLUE <<"| 4. Have fun!!!                                                " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| INPUT                                                         " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. The program would ask you to input in terms of rows and    " << RESET << endl;                                            
                cout << BLUE <<"|    columns (row,column). Please input as row (space) column.  " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"*---------------------------------------------------------------*" << endl;
                cout << BLUE <<"Now please start and enjoy!";
                cout << endl;
            } //english mode

            else if (lang=="3")
            {
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"| REGLAS/TUTORIAL                                               " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. Comience haciendo clic en cualquier lugar al azar.         " << RESET << endl;
                cout << BLUE <<"| 2. El número corresponde a las minas adyacentes al bloque.    " << RESET << endl;
                cout << BLUE <<"| 3. Marque todas las bombas y limpie toda el área vacía.       " << RESET << endl;
                cout << BLUE <<"| 4. Diviértete!!!                                              " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| ENTRADA                                                       " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. El programa le pedirá que ingrese en términos de filas y   " << RESET << endl;                                            
                cout << BLUE <<"|    ccolumnas (fila, columna). Ingrese como columna de fila    " << RESET << endl;
                cout << BLUE <<"|    (espacio).                                                 " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"¡Ahora por favor comienza y disfruta!";
                cout << endl;
            }//spanish

            else if (lang=="4")
            {
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"| REGLES/TUTORIEL                                               " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. Commencez par cliquer à n'importe quel endroit au hasard.  " << RESET << endl;
                cout << BLUE <<"| 2. Le nombre correspond aux mines adjacentes au bloc.         " << RESET << endl;
                cout << BLUE <<"| 3. Marquez toutes les bombes et nettoyez toute la zone vide.  " << RESET << endl;
                cout << BLUE <<"| 4. Amusez-vous!!!                                             " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| CONTRIBUTION                                                  " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. Le programme vous demandera d'entrer en termes de lignes   " << RESET << endl;                                            
                cout << BLUE <<"|    et colonnes (ligne, colonne). Veuillez saisir comme        " << RESET << endl;
                cout << BLUE <<"|    colonne ligne (espace).                                    " << RESET << endl;
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"Maintenant, veuillez commencer et profiter!";
                cout << endl;
            }//spanish

            else if (lang=="5")
            {
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"| 규칙/튜토리얼                                                    " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. 임의의 위치를 ​​클릭하여 시작하십시오.                                " << RESET << endl;
                cout << BLUE <<"| 2. 숫자는 블록에 인접한 광산입니다.                                   " << RESET << endl;
                cout << BLUE <<"| 3. 모든 폭탄을 표시하고 빈 공간을 모두 치 웁니다.                        " << RESET << endl;
                cout << BLUE <<"| 4. 즐거운 시간 보내세요 !!!                                        " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 입력                                                           " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. 프로그램은 행과 열 (행, 열). 행 (공백) 열로 입력하십시오.              " << RESET << endl;                                            
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"이제 시작하고 즐기십시오!";
                cout << endl;
            }//korean

            else if (lang=="6")
            {
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"| ルール/チュートリアル                                            " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. 任意の場所をクリックして開始します。                             " << RESET << endl;
                cout << BLUE <<"| 2. 数はブロックに隣接する鉱山です。                                " << RESET << endl;
                cout << BLUE <<"| 3. すべての爆弾にマークを付け、すべての空の領域をクリアします。         " << RESET << endl;
                cout << BLUE <<"| 4. 楽しんでください!!!                                           " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 入力                                                           " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. プログラムは、行と|の観点から入力を要求します                     " << RESET << endl;                                            
                cout << BLUE <<"|    列（行、列）。行（スペース）列として入力してください。              " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"今すぐ始めて楽しんでください！";
                cout << endl;
            }//japanese mode

            else if (lang=="7")
            {
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"| ПРАВИЛА/ОБУЧЕНИЕ                                              " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. Начните с нажатия в любом произвольном месте.                     " << RESET << endl;
                cout << BLUE <<"| 2. Количество мин, прилегающих к блоку.            " << RESET << endl;
                cout << BLUE <<"| 3. Отметьте все бомбы и очистите всю пустую область.   " << RESET << endl;
                cout << BLUE <<"| 4. Веселитесь !!!                                                " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| вход                                                         " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"| 1. Программа попросит вас ввести в виде строк и    " << RESET << endl;                                            
                cout << BLUE <<"|    столбцы (строка, столбец). Пожалуйста, введите в   " << RESET << endl;
                cout << BLUE <<"|    виде строки (пробел) столбец.                              " << RESET << endl;
                cout << BLUE <<"|                                                               " << RESET << endl;
                cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
                cout << BLUE <<"Теперь, пожалуйста, начните и наслаждайтесь!";
                cout << endl;
            }//russian mode

            else
            {
                cout << "\n";
                cout << RED <<"ERROR! Please restart." << RESET ; //input validation
                return 0;
            }
 
        cout << "\n";
        }
    }

        if (lang=="1")
        {
            cout << BLUE << "*----------------------------------------------------------------*" << RESET << endl;
            cout << BLUE << "| 規則/教程                                                       " << RESET << endl;
            cout << BLUE << "|                                                                " << RESET << endl;
            cout << BLUE << "| 1. 從任意一個隨機位置開始。                                        " << RESET << endl;
            cout << BLUE << "| 2. 數字是與街區相鄰的地雷                                          " << RESET << endl;
            cout << BLUE << "| 3. 標記所有炸彈並清除所有空白區域                                   " << RESET << endl;
            cout << BLUE << "| 4. 玩得開心!!!                                                  " << RESET << endl;
            cout << BLUE << "|                                                                " << RESET << endl;
            cout << BLUE << "| 輸入                                                            " << RESET << endl;
            cout << BLUE << "|                                                                " << RESET << endl;
            cout << BLUE << "| 1. 程序將要求您輸入行和列（行，列。 請輸入為 行（空格）列。             " << RESET << endl;                                            
            cout << BLUE << "|                                                                " << RESET << endl;
            cout << BLUE << "*----------------------------------------------------------------*" << endl;
            cout << BLUE << "現在請開始享受！";
            cout << endl;
        }   //chinese mode

        else if (lang=="2")
        {
            cout << BLUE <<"*---------------------------------------------------------------*"<< RESET << endl;
            cout << BLUE <<"| RULES/TUTORIAL                                                " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. Start by clicking at any random place.                     " << RESET << endl;
            cout << BLUE <<"| 2. The number is the mines adjacent to the block.             " << RESET << endl;
            cout << BLUE <<"| 3. Mark all the bombs and clear out all the the empty area.   " << RESET << endl;
            cout << BLUE <<"| 4. Have fun!!!                                                " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| INPUT                                                         " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. The program would ask you to input in terms of rows and    " << RESET << endl;                                            
            cout << BLUE <<"|    columns (row,column). Please input as row (space) column.  " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"*---------------------------------------------------------------*" << endl;
            cout << BLUE <<"Now please start and enjoy!";
            cout << endl;
        } //english mode

        else if (lang=="3")
        {
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"| REGLAS/TUTORIAL                                               " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. Comience haciendo clic en cualquier lugar al azar.         " << RESET << endl;
            cout << BLUE <<"| 2. El número corresponde a las minas adyacentes al bloque.    " << RESET << endl;
            cout << BLUE <<"| 3. Marque todas las bombas y limpie toda el área vacía.       " << RESET << endl;
            cout << BLUE <<"| 4. Diviértete!!!                                              " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| ENTRADA                                                       " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. El programa le pedirá que ingrese en términos de filas y   " << RESET << endl;                                            
            cout << BLUE <<"|    ccolumnas (fila, columna). Ingrese como columna de fila    " << RESET << endl;
            cout << BLUE <<"|    (espacio).                                                 " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"¡Ahora por favor comienza y disfruta!";
            cout << endl;
        }//spanish

        else if (lang=="4")
        {
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"| REGLES/TUTORIEL                                               " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. Commencez par cliquer à n'importe quel endroit au hasard.  " << RESET << endl;
            cout << BLUE <<"| 2. Le nombre correspond aux mines adjacentes au bloc.         " << RESET << endl;
            cout << BLUE <<"| 3. Marquez toutes les bombes et nettoyez toute la zone vide.  " << RESET << endl;
            cout << BLUE <<"| 4. Amusez-vous!!!                                             " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| CONTRIBUTION                                                  " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. Le programme vous demandera d'entrer en termes de lignes   " << RESET << endl;                                            
            cout << BLUE <<"|    et colonnes (ligne, colonne). Veuillez saisir comme        " << RESET << endl;
            cout << BLUE <<"|    colonne ligne (espace).                                    " << RESET << endl;
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"Maintenant, veuillez commencer et profiter!";
            cout << endl;
        }//spanish

        else if (lang=="5")
        {
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"| 규칙/튜토리얼                                                    " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. 임의의 위치를 ​​클릭하여 시작하십시오.                                " << RESET << endl;
            cout << BLUE <<"| 2. 숫자는 블록에 인접한 광산입니다.                                   " << RESET << endl;
            cout << BLUE <<"| 3. 모든 폭탄을 표시하고 빈 공간을 모두 치 웁니다.                        " << RESET << endl;
            cout << BLUE <<"| 4. 즐거운 시간 보내세요 !!!                                        " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 입력                                                           " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. 프로그램은 행과 열 (행, 열). 행 (공백) 열로 입력하십시오.              " << RESET << endl;                                            
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"이제 시작하고 즐기십시오!";
            cout << endl;
        }//korean

        else if (lang=="6")
        {
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"| ルール/チュートリアル                                            " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. 任意の場所をクリックして開始します。                             " << RESET << endl;
            cout << BLUE <<"| 2. 数はブロックに隣接する鉱山です。                                " << RESET << endl;
            cout << BLUE <<"| 3. すべての爆弾にマークを付け、すべての空の領域をクリアします。         " << RESET << endl;
            cout << BLUE <<"| 4. 楽しんでください!!!                                           " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 入力                                                           " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. プログラムは、行と|の観点から入力を要求します                     " << RESET << endl;                                            
            cout << BLUE <<"|    列（行、列）。行（スペース）列として入力してください。              " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"今すぐ始めて楽しんでください！";
            cout << endl;
        }//japanese mode

        else if (lang=="7")
        {
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"| ПРАВИЛА/ОБУЧЕНИЕ                                              " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. Начните с нажатия в любом произвольном месте.                     " << RESET << endl;
            cout << BLUE <<"| 2. Количество мин, прилегающих к блоку.            " << RESET << endl;
            cout << BLUE <<"| 3. Отметьте все бомбы и очистите всю пустую область.   " << RESET << endl;
            cout << BLUE <<"| 4. Веселитесь !!!                                                " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| вход                                                         " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"| 1. Программа попросит вас ввести в виде строк и    " << RESET << endl;                                            
            cout << BLUE <<"|    столбцы (строка, столбец). Пожалуйста, введите в   " << RESET << endl;
            cout << BLUE <<"|    виде строки (пробел) столбец.                              " << RESET << endl;
            cout << BLUE <<"|                                                               " << RESET << endl;
            cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
            cout << BLUE <<"Теперь, пожалуйста, начните и наслаждайтесь!";
            cout << endl;
        }//russian mode
        cout << "\n";
}

void selectmode() //select mode
{
    string mode;

    cout << GREEN <<"Please select mode: " << RESET  << endl;
    cout << GREEN <<"1) Play" << RESET << endl;
    cout << GREEN <<"2) Tutorial" << RESET << endl;
    cout << "\n";
    cout << GREEN <<"Selection: " << RESET ;
    cin >> mode;

    while( mode != "1" && mode != "2")
    {
        cout << "Enter a valid selection! \n";
        cout << "Selection: ";
        cin >> mode;
        cout << "\n";
        
        if( mode == "1" || mode == "2")
        {
            if (mode=="1")
            {

            }

            else if (mode=="2")
            {
                tutorial();
                return;
            }
        }
    cout << "\n";  
    }

    if( mode == "1" || mode == "2")
    {
        if (mode=="1")
        {

        }

        else if (mode=="2")
        {
            tutorial();
            return;
        }
        cout << "\n";
    }
}

int levelcho() 
{
    string level; //select level or mode
    cout << GREEN <<"Please select the following levels of complexity: " << RESET << endl;
    cout << GREEN <<"1) Loser (3x3) (1 Mine) " << RESET << endl;
    cout << GREEN <<"2) Noob (6x6) (3 Mines)" << RESET << endl;
    cout << GREEN <<"3) Beginner (9x9) (10 Mines)" << RESET << endl;
    cout << GREEN <<"4) Intermediate (15x15) (40 Mines)" << RESET << endl;
    cout << GREEN <<"5) Advanced (21x21) (99 Mines)" << RESET << endl;
    cout << GREEN <<"6) Professional (25x25) (150 Mines) " << RESET << endl;
    cout << GREEN <<"7) God (51x51) (250 Mines) " << RESET << endl;
    cout << GREEN <<"8) Customized " << RESET << endl;
    cout << GREEN <<"9) Quit " << RESET << endl;
    cout << "\n";
    
    cout << GREEN <<"Here is a riddle for fun :)" << RESET << endl;
    cout << "\n";
    cout << GREEN <<"There is a three digit number. The second digit is four times as big as the third digit, " << RESET << endl; 
    cout << GREEN <<"while the first digit is three less than the second digit. What is the number? " << RESET << endl;
    cout << "\n";
    cout << GREEN <<"Mode: ";

    cin >> level;//move to respective modes

    while( level != "1" && level != "2" && level != "3" && level != "4" && level != "5" && level != "6" && level != "7" && level != "8" && level != "9")
    {
        cout << "Enter a valid selection! \n";
        cout << "\n";
        cout << GREEN << "Choice: "<< RESET ;
        cin >> level;
        cout << "\n";
        
        if( level == "1" && level == "2" && level == "3" && level == "4" && level == "5" && level == "6" && level == "7" && level == "8" && level == "9")
        {

            if (level=="1")
            {
                cout << "\n";
                loser(); 
            }

            else if (level=="2")
            {
                cout << "\n";
                noob();
            }

            else if (level=="3")
            {
                cout << "\n";
                beginner();
            }

            else if (level=="4")
            {
                cout << "\n";
                intermediate();
            }

            else if (level=="5")
            {
                cout << "\n";
                advanced();
            }

            else if (level=="6")
            {
                cout << "\n";
                professional();
            }

            else if (level=="7")
            {
                cout << "\n";
                god();
            }

            else if (level=="8")
            {
                cout << "\n";
                customize();
            }

            else if (level=="9")
            {
                cout << "\n";
                cout << GREEN <<"Goodbye~!" << RESET ;
            }

            else
            {
                cout << "\n";
                cout << RED <<"ERROR! Please restart." << RESET ; //input validation
                return 0;
            }
        }
    }

    if (level=="1")
    {
        cout << "\n";
        loser(); 
    }

    else if (level=="2")
    {
        cout << "\n";
        noob();
    }

    else if (level=="3")
    {
        cout << "\n";
        beginner();
    }

    else if (level=="4")
    {
        cout << "\n";
        intermediate();
    }

    else if (level=="5")
    {   
        cout << "\n";
        advanced();
    }

    else if (level=="6")
    {
        cout << "\n";
        professional();
    }

    else if (level=="7")
    {
        cout << "\n";
        god();
    }

    else if (level=="8")
    {
        cout << "\n";
        customize();
    }

    else if (level=="9")
    {
        cout << "\n";
        cout << GREEN <<"Goodbye~!" << RESET ;
    }

}

int nearbymine (int row, int col, int mines[][2], char ansbrd[][SIDENUMMAX]) //display the number on the board
{
    int i; 
    int count = 0; 

    if (verify(row-1, col) == true) //upper block
    { 
        if (verifymine(row-1, col, ansbrd) == true)
        {
                count++; 
        }
    } 

    if (verify(row+1, col) == true) //lower block
    { 
        if (verifymine(row+1, col, ansbrd) == true)
        {
            count++; 
        }
    } 

    if (verify(row, col+1) == true) //right block
    { 
        if (verifymine(row, col+1, ansbrd) == true) 
        {
            count++; 
        } 
    } 

    if (verify(row, col-1) == true) //left block
    { 
        if (verifymine(row, col-1, ansbrd) == true) 
        {
            count++; 
        } 
    } 

    if (verify(row-1, col+1) == true)  //upper east block
    { 
        if (verifymine(row-1, col+1, ansbrd) == true) 
        {
            count++; 
        } 
    } 

    if (verify(row-1, col-1) == true) //upper west block
    {  
        if (verifymine(row-1, col-1, ansbrd) == true) 
        {
            count++; 
        }  
    } 

    if (verify(row+1, col+1) == true) //lower east block
    { 
        if (verifymine(row+1, col+1, ansbrd) == true) 
        {
            count++; 
        } 
    } 

    if (verify(row+1, col-1) == true) //lower west block
    { 
        if (verifymine(row+1, col-1, ansbrd) == true) 
        {
            count++; 
        }  
    } 
  
    return (count);
}
  
void welcome() 
{
    cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
    cout << BLUE <<"|                                                               |" << RESET << endl;
    cout << BLUE <<"|            Welcome to Benjamin's Minesweeper Game             |" << RESET << endl;
    cout << BLUE <<"|                                                               |" << RESET << endl;
    cout << BLUE <<"|                    Proudly Programmed @ PAS                   |" << RESET << endl;
    cout << BLUE <<"|                                                               |" << RESET << endl;
    cout << BLUE <<"|                                                               |" << RESET << endl;
    cout << BLUE <<"|                                         © Benjamin Chang 2020 |" << RESET << endl;
    cout << BLUE <<"|                                           All Rights Reserved |" << RESET << endl;
    cout << BLUE <<"*---------------------------------------------------------------*" << RESET << endl;
    return;
}

void plantmine(int mines[][2], char ansbrd[][SIDENUMMAX]) //plant a mine
{
    bool mark[SIDENUMMAX*SIDENUMMAX]; 
  
    memset(mark, false, sizeof (mark)); 
  
    for (int i=0; i<mine; ) 
     { 
        int random = rand() % (size*size); //randomly set mines
        int x = random / size; 
        int y = random % size; 
  
        if (mark[random] == false) //add mine if there are no mines
        { 
            mines[i][0]= x; 
            mines[i][1] = y; 

            ansbrd[mines[i][0]][mines[i][1]] = '*'; //implant mine
            mark[random] = true; 
            i++; 
        } 
    } 
    return; 
}

void move(int *x, int *y) //movement
{
    char location;
    cout << "\n";
    cout << "Would you like to flag a location? (y/n) " << endl;
    cin >> location;
    char flagbrd[SIDENUMMAX][SIDENUMMAX];

    if (location == 'Y' || location == 'y')
    {
        int select;
        cout << "\n";
        cout << "Do you want to clear a flag or input a flag? " << endl;
        cout << "1) Input" << endl;
        cout << "2) Clear" << endl;
        cout << "Choice: ";
        cin >> select;

        if (select==1)
        {
        int a, b;

        cout << "\n";
        cout << GREEN << "Select a block to flag (row): " << RESET ;
        cout << "\n";
        cin >> a;

        cout << "\n";
        cout << GREEN << "Select a block to flag (column): " << RESET ;
        cout << "\n";
        cin >> b;

        flagbrd [a][b] = 'F';
        disboard2(flagbrd);
        }
         
        else if (select==2)
        {
        int a, b;
        
        cout << "\n";
        cout << GREEN << "Select a block to clear flag (row): " << RESET ;
        cout << "\n";
        cin >> a;

        cout << "\n";
        cout << GREEN << "Select a block to clear flag (column): " << RESET ;
        cout << "\n";
        cin >> b;

        flagbrd [a][b] = '-';
        disboard2(flagbrd);
        }
    }

    cout << "\n";
    cout << GREEN << "Select a block to sweep (row): " << RESET ;
    cout << "\n";
    cin >> *x;

    cout << "\n";
    cout << GREEN << "Select a block to sweep (column): " << RESET ;
    cout << "\n";
    cin >> *y; 

    return; 
}

void disboard(char playerbrd[][SIDENUMMAX]) //display the board
{
  
    cout << "       ";
    
    for (int i=0; i<size; i++) 
    {
        if (i<10)
        {
            cout << i << "    ";
        }
        
        else if (i>=10)
        {
            cout << i << "   ";
        }
    }

    cout << "\n";
    cout << "      ";

    for (int i=0; i<size; i++)
    {
        cout << " _  " << " ";
    }
  
    cout << "\n";
  
    for (int i=0; i<size; i++) 
    { 
        
        if (i<10)
        {
            cout << i << "   |  " << RESET ;
        }
        
        else if (i>=10)
        {
            cout << i << "  |  " << RESET ;
        }
        
        for (int j=0; j<size; j++) 
        {
           cout << playerbrd[i][j]<< "    " << RESET ;
        } 
        
        cout << "\n";
    }
    return;
} 

void chgmine(int row, int col, char board[][SIDENUMMAX])//put a mine into a cell
{
    for (int i=0; i<size; i++) 
    { 
        for (int j=0; j<size; j++) 
            { 
                if (board[i][j] != '*') 
                { 
                    board[i][j] = '*'; 
                    board[row][col] = '-'; 
                    return; 
                } 
            } 
    } 
    return; 
}

void reveal(char ansbrd[][SIDENUMMAX]) //answer of the board
{
    cout << GREEN << "Location of the mines are: " << RESET  << endl; 
    disboard(ansbrd); 
    return; 
} 

void setup(char ansbrd[][SIDENUMMAX], char playerbrd[][SIDENUMMAX]) //start game, no mine in cell
{ 
    srand(time (NULL));  //randomize
  
    for (int i=0; i<size; i++) 
    { 
        for (int j=0; j<size; j++) 
        { 
            playerbrd[i][j] = ansbrd[i][j] = '-'; 
        } 
    } 
    return;
}