
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void player1board(vector<vector<int> > &vec, int x, int y, int a, int b, string hv, int size)
{
    if (hv == "v")
    {
        cout << "🚢   ";
        for (int i = 0; i < y; i++)
        {
            if (i + 1 >= 10)
            {
                cout << " " << i + 1;
            }
            else if (i + 1 <= 10)
            {
                cout << "  " << i + 1;
            }
        }
        cout << endl;
        cout << "    +";
        for (int i = 0; i < (y * 3); i++)
        {
            cout << "-";
        }
        cout << "-";
        cout << endl;
        for (int k = 0; k < size ; k++)
        {
            vec[a - 1 + k][b - 1] = 1;
        }
        for (int i = 0; i < x; i++)
        {
            if (i > 8)
            {
                cout << "  " << i + 1 << "| ";
            }
            else if (i <= 8)
            {
                cout << "   " << i + 1 << "| ";
            }
            for (int j = 0; j < y; j++)
            {
                cout << " " << vec[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (hv == "h")
    {
        cout << "🚢   ";
        for (int i = 0; i < y; i++)
        {
            if (i + 1 >= 10)
            {
                cout << " " << i + 1;
            }
            else if (i + 1 <= 10)
            {
                cout << "  " << i + 1;
            }
        }
        cout << endl;
        cout << "    +";
        for (int i = 0; i < (y * 3); i++)
        {
            cout << "-";
        }
        cout << "-";
        cout << endl;
        for (int k = 0; k < size; k++)
        {
            vec[a - 1][b - 1 + k] = 1;
        }
        for (int i = 0; i < x; i++)
        {
            if (i > 8)
            {
                cout << "  " << i + 1 << "| ";
            }
            else if (i <= 8)
            {
                cout << "   " << i + 1 << "| ";
            }
            for (int j = 0; j < y; j++)
            {
                cout << " " << vec[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "🚢   ";
        for (int i = 0; i < y; i++)
        {
            if (i + 1 >= 10)
            {
                cout << " " << i + 1;
            }
            else if (i + 1 <= 10)
            {
                cout << "  " << i + 1;
            }
        }
        cout << endl;
        cout << "    +";
        for (int i = 0; i < (y * 3); i++)
        {
            cout << "-";
        }
        cout << "-";
        cout << endl;
        for (int i = 0; i < x; i++)
        {
            if (i >8)
            {
                cout << "  " << i + 1 << "| ";
            }
            else if (i <= 8)
            {
                cout << "   " << i + 1 << "| ";
            }

            for (int j = 0; j < y; j++)
            {
                vec[i][j] = 0;
                cout << " " << vec[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void player2board(vector<vector<int> > &vec2, int x, int y, int a1, int b1, string hv1, int size)// player2
{
    if (hv1 == "v")
    {
        cout << "🚢   ";
        for (int i = 0; i < y; i++)
        {
            if (i + 1 >= 10)
            {
                cout << " " << i + 1;
            }
            else if (i + 1 <= 10)
            {
                cout << "  " << i + 1;
            }
        }
        cout << endl;
        cout << "    +";
        for (int i = 0; i < (y * 3); i++)
        {
            cout << "-";
        }
        cout << "-";
        cout << endl;
        for (int k = 0; k < size ; k++)
        {
            vec2[a1 - 1 + k][b1 - 1] = 1;
        }
        for (int i = 0; i < x; i++)
        {
            if (i > 8)
            {
                cout << "  " << i + 1 << "| ";
            }
            else if (i <= 8)
            {
                cout << "   " << i + 1 << "| ";
            }
            for (int j = 0; j < y; j++)
            {
                cout << " " << vec2[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (hv1 == "h")
    {
        cout << "🚢   ";
        for (int i = 0; i < y; i++)
        {
            if (i + 1 >= 10)
            {
                cout << " " << i + 1;
            }
            else if (i + 1 <= 10)
            {
                cout << "  " << i + 1;
            }
        }
        cout << endl;
        cout << "    +";
        for (int i = 0; i < (y * 3); i++)
        {
            cout << "-";
        }
        cout << "-";
        cout << endl;
        for (int k = 0; k < size; k++)
        {
            vec2[a1 - 1][b1 - 1 + k] = 1;
        }
        for (int i = 0; i < x; i++)
        {
            if (i > 8)
            {
                cout << "  " << i + 1 << "| ";
            }
            else if (i <= 8)
            {
                cout << "   " << i + 1 << "| ";
            }
            for (int j = 0; j < y; j++)
            {
                cout << " " << vec2[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "🚢   ";
        for (int i = 0; i < y; i++)
        {
            if (i + 1 >= 10)
            {
                cout << " " << i + 1;
            }
            else if (i + 1 <= 10)
            {
                cout << "  " << i + 1;
            }
        }
        cout << endl;
        cout << "    +";
        for (int i = 0; i < (y * 3); i++)
        {
            cout << "-";
        }
        cout << "-";
        cout << endl;
        for (int i = 0; i < x; i++)
        {
            if (i > 8)
            {
                cout << "  " << i + 1 << "| ";
            }
            else if (i <= 8)
            {
                cout << "   " << i + 1 << "| ";
            }

            for (int j = 0; j < y; j++)
            {
                vec2[i][j] = 0;
                cout << " " << vec2[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void player1hit(vector<vector<int> > &vec, int x, int y, int c1, int d1, int count1)
{
    cout << "player1's player1board" << endl;
    cout << "🚢   ";
    for (int i = 0; i < y; i++)
    {
        if (i + 1 >= 10)
        {
            cout << " " << i + 1;
        }
        else if (i + 1 <= 10)
        {
            cout << "  " << i + 1;
        }
    }
    cout << endl;
    cout << "    +";
    for (int i = 0; i < (y * 3); i++)
    {
        cout << "-";
    }
    cout << "-";
    cout << endl;

    if (vec[c1 - 1][d1 - 1] == 1)
    {
        vec[c1 - 1][d1 - 1] = 3;
        count1++;
    }
    else if (vec[c1 - 1][d1 - 1] == 0)
    {
        vec[c1 - 1][d1 - 1] = 2;
    }
    for (int i = 0; i < x; i++)
    {
        if (i > 8)
        {
            cout << "  " << i + 1 << "| ";
        }
        else if (i <= 8)
        {
            cout << "   " << i + 1 << "| ";
        }
        for (int j = 0; j < y; j++)
        {
            if (vec[i][j] == 1)
            {
                cout << " 0" << " ";
            }
            else
            {
                cout << " " << vec[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void player2hit(vector<vector<int> > &vec2, int x, int y, int c, int d, int count) // 
{
    cout << "player2's player1board" << endl;
    cout << "🚢   ";
    for (int i = 0; i < y; i++)
    {
        if (i + 1 >= 10)
        {
            cout << " " << i + 1;
        }
        else if (i + 1 <= 10)
        {
            cout << "  " << i + 1;
        }
    }
    cout << endl;
    cout << "    +";
    for (int i = 0; i < (y * 3); i++)
    {
        cout << "-";
    }
    cout << "-";
    cout << endl;

    if (vec2[c - 1][d - 1] == 1)
    {
        vec2[c - 1][d - 1] = 3;
        count++;
    }
    else if (vec2[c - 1][d - 1] == 0)
    {
        vec2[c - 1][d - 1] = 2;
    }
    for (int i = 0; i < x; i++)
    {
        if (i > 8)
        {
            cout << "  " << i + 1 << "| ";
        }
        else if (i <= 8)
        {
            cout << "   " << i + 1 << "| ";
        }
        for (int j = 0; j < y; j++)
        {
            if (vec2[i][j] == 1)
            {
                cout << " 0" << " ";
            }
            else
            {
                cout << " " << vec2[i][j] << " ";
            }
        }
        cout << endl;
    }
}

