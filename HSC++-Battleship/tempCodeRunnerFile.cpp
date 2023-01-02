#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;

int validation(int num, int min, int max)
{
  while(num>max)
  {
    cout<<"Please enter a valid choice! " << max << endl;
    cin>>num;
    num=validation(num,min,max);
  }

  while(num<min)
  {
    cout<<"Please enter a valid choice! "<< min << endl;
    cin>>num;
    num=validation(num,min,max);
  }

  return num;
}
void ranset(int **arr,int size)
{
  srand(time(NULL));
  for(int i=0;i<size;i++)
  {
    int ran1,ran2;
    ran1=rand()%4+1;
    ran2=rand()%4+1;
    while(arr[ran1-1][ran2-1]==1)
    {
      ran1=rand()%4+1;
      ran2=rand()%4+1;
    }
    arr[ran1-1][ran2-1]=1;
  }
}
void print(int **arr,int size)
{
  cout<<"\n\\ ";
  for(int i=1;i<=size;i++)
  {cout<<"|"<<i<<" ";}
  cout<<"\n";
  for(int i=1;i<=size;i++)
  {cout<<"---";}
  cout<<"\n";
  for (int i=0; i<size; i++)
  {
    cout<<i+1<<"| ";
    for(int j=0; j<size; j++)
    {
      if (arr[i][j]==2)
      {
      cout<<"\x1B[34m"<<"██ "<<"\033[0m";
      }
      else if (arr[i][j]==1)
      {
       cout<<"🚢 ";
      }
      else if (arr[i][j]==3)
      {
        cout<<"💥 ";
      }
      else if (arr[i][j]==4)
      {
        cout<<"❌ ";
      }
    }cout<<"\n";
  }
  for(int i=1;i<=size;i++)
  {cout<<"---";}
}
void set(int **arr,int size)
{
  int row;
  int column;
  cout<<"\nYou can put a number of "<<size<<" ships in your ocean.\n";
  for(int i=1; i<=size;i++)
  {
    cout<<"\nship "<<i;
    cout<<"\ninsert location (format: row [space] column): ";
    cin>>row;
    row=validation(row, 1, size);
    cin>>column;
    column=validation(column, 1, size);
      while(arr[row-1][column-1]==1)
      {cout<<"\noops! unable to place ship! Please input a new location!";
      cin>>row;
      row=validation(row, 1, size);
      cin>>column;
      column=validation(column, 1, size);}
    if(arr[row-1][column-1]!=1)
    {arr[row-1][column-1]=1;}
    print(arr,size);
  }
}
void set2(int**arr,int size)
{
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
    {
      arr[i][j]=2;
    }
  }
}
bool check(int**arr, int size)
{
  bool thiss=false;
  for(int i=0; i<size;i++)
  {
    for(int j=0; j<size; j++)
    {
      if (arr[i][j]==1)
      {thiss=true;}
    }
  }
  return thiss;
}
void attack2(int**arr, int size, int ran1, int ran2)
{
  int ran3=rand()%2+1;
  if(ran3==2)
  {
    if(ran1+1<size)
  {ran1++;}
  else
  {ran1--;}
  }
  if(ran3==1)
  {if(ran2+1<size)
  {ran2++;}
else
{ran2--;}}
    if(arr[ran1][ran2]==1)
    {
      arr[ran1][ran2]=3;
      attack2(arr, size, ran1, ran2);
    }
    else if (arr[ran1][ran2]==2)
    {
      arr[ran1][ran2]=4;
    }
}
void attackyou(int **arr, int**arr2, int i, int j,int size, int count)
{
  while(arr[i][j]==3||arr[i][j]==4)
  {
    cout<<"seems like you have already attacked this position! Please enter another lcoation.";
    cin>>i;
    i=validation(i, 1, size);
    cin>>j;
    i=validation(i, 1, size);
  }
  if (arr[i][j]==1)
  {
    cout<<"You hit a ship :)";
    arr[i][j]=3;
    arr2[i][j]=3;
    print(arr2,size);
    if(check(arr,size)==false)
    {return;}
    else
    {
    cout<<"\ninsert another location\n";
    cin>>i;
    i=validation(i, 1, size);
    cin>>j;
    j=validation(j, 1, size);
    attackyou(arr, arr2, i-1,j-1,size,count);
    return;
    }
  }
  if (arr[i][j]==2)
  {
    cout<<"You didn't hit a ship :(";
    arr[i][j]=4;
    arr2[i][j]=4;
    print(arr2,size);
    return;
  }
}
void attack(int **arr, int**arr2, int size, string name)
{
  if(name=="you")
  {
    int i,j;
  cout<<"\nPlease enter the location you want to attack: ";
  cin>>i;
  i=validation(i, 1, size);
  cin>>j;
  i=validation(i, 1, size);
  attackyou(arr,arr2,i-1,j-1,size, 0);
  }
  else if(name=="AI")
  {
    int ran1, ran2;
    ran1=rand()%(size-1);
    ran2=rand()%(size-1);
    while(arr[ran1][ran2]==4||arr[ran1][ran2]==3)
    {
      ran1=rand()%(size-1);
      ran2=rand()%(size-1);
    }
    if(arr[ran1][ran2]==1)
    {
      arr[ran1][ran2]=3;
      attack2(arr, size, ran1, ran2);
    }
    else if (arr[ran1][ran2]==2)
    {
      arr[ran1][ran2]=4;
    }
  }
}



int main()
{
  srand(time(NULL));
  cout<<"-----------------------------------------\n";
  cout<<"✨Wellllcome to cath's battleship game!✨";
  cout<<"\n-----------------------------------------\n";
  cout<<"\"🚢\" is the ships, and the blue blocks are the ocean.\n";
  cout<<"Please enter your mode (1: AI/ 2: multi-player): ";
  int mode;
  cin>>mode;
  mode=validation(mode,1,2);
  int v=0;
  while(true)
  {
  int size=0;
  cout<<"Enter the side length of the game board( min size: 2 ): ";
  cin>>size;
  size=validation(size,2,100);
  int **A=new int*[size];
  for(int i=0;i<size;i++)
  { A[i]= new int [size]; }
  int **B= new int*[size];
  for(int i=0;i<size;i++)
  { B[i]=new int [size];}
  int **C=new int*[size];
  for(int i=0;i<size;i++)
  {C[i]=new int [size];}
  int **D=new int*[size];
  for(int i=0;i<size;i++)
  {D[i]=new int [size];}

  cout<<"\n==========================\n";
  cout<<"\nPlaye#1's turn to set map: ";
  set2(A,size);
  print(A,size);
  set(A,size);
  set2(D,size);
  if(mode==1)
  {
  set2(B,size);
  ranset(B,size);
  set2(C,size);
  cout<<"\nYour ocean map: ";
  print(A,size);
  cout<<"\nYour AI opponent's ocean map: ";
  print(C,size);
  for(int count=1;count<=size*size;count++)
  {
    cout<<"\nRound "<<count;
    attack(B, C, size, "you");
    if(check(B,size)==false)
    {
      cout<<"\nYou hit all the ships!";
      v=1;
      break;
    }
    cout<<"\nIt is the AI's turn.";
    attack(A, D, size, "AI");
    print(A,size);
    if(check(A,size)==false)
    {
      print(A,size);
      cout<<"The AI hit all the ships!";
      v=2;
      break;
    }
  }
  }
  if(mode==2)
  {
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer#2's turn to set map";
    set2(B,size);
    print(B,size);
    set(B,size);
    set2(C,size);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n=========================\nGAME START!";
    for(int count=1;count<=size*size;count++)
    {
      cout<<"\nRound "<<count;
      cout<<"\nPlayer#1's turn";
      attack(B,C,size,"you");
      if(check(B,size)==false)
      {
        cout<<"\nPlayer#1 hit all the ships!";
        v=1;
        break;
      }
      cout<<"\nPlayer#2's turn";
      attack(A,D,size,"you");
      if(check(A,size)==false)
      {
        cout<<"\nPlayer#2 hit all the ships!";
        v=2;
        break;
      }
    }
  }
  if(v==1)
  {
    cout<<"\nPlayer#1 won the game!!!🥳";
  }
  if(v==2)
  {
    cout<<"\nPlayer#2 won the game!!!🥳";
  }
  cout<<"\nOne more round? (y/n)";
  char ans;
  cin>>ans;
  while(ans!='y'&&ans!='n')
  {
    cout<<"Invalid response! please enter your answer again.";
    cin>>ans;
  }
  if(ans=='n')
  {
    cout<<"\n💫✨💫BYE💫✨💫";
    cout<<"\n";
    break;}
  }
  return 0;
}
