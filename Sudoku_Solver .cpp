#include<bits/stdc++.h>

using namespace std;

int sudoku[9][9], solution[9][9];

int row[9][10], col[9][10];
map<pair<int, int>, map<int, int>> sub_grid;

bool helper(int i, int j)
{
    //cout << "i | " << i << " || j | " << j << endl;
    if(i == 8   &&   j == 9)
        return true;
    if(j == 9)
    {
        return helper(i+1, 0);
    }
    if(sudoku[i][j] != 0)
    {
        return helper(i, j+1);
    }
    int a, b, k;
    a = i/3;    b = j/3;
    pair<int, int> x;
    x.first = a;    x.second = b;
    for(k=1;  k<=9;  k++)
    {
        //cout << "check | " << k << endl;
        if(row[i][k]==0  &&  (col[j][k]==0  &&  sub_grid[x][k]==0))
        {
            //cout << row[i][k] << " " << col[j][k] << " " << sub_grid[x][k] << endl;
            row[i][k] = col[j][k] = sub_grid[x][k] = 1;
            solution[i][j] = sudoku[i][j] = k;
            if(helper(i, j+1))
            {
                return true;
            }
            row[i][k] = col[j][k] = sub_grid[x][k] = solution[i][j] = sudoku[i][j] = 0;
        }
    }
    return false;
}


void Solver()
{
    int i, j;
    for(i=0;  i<9;  i++)
    {
        for(j=0;  j<9;  j++)
        {
            if(sudoku[i][j] != 0)
            {
                col[j][sudoku[i][j]] = 1;
                row[i][sudoku[i][j]] = 1;
                pair<int, int> x;
                x.first = i/3;
                x.second = j/3;
                sub_grid[x][sudoku[i][j]] = 1;
                solution[i][j] = sudoku[i][j];
            }
            else
            {
                col[j][sudoku[i][j]] = 0;
                row[i][sudoku[i][j]] = 0;
                pair<int, int> x;
                x.first = i/3;
                x.second = j/3;
                sub_grid[x][sudoku[i][j]] = 0;
                solution[i][j] = 0;
            }
        }
    }
    if(helper(0, 0))
        cout << "\n\n\nSolution found \n\n\n";
}

int main()
{
    int i, j;
    /*
    cout << "\n\n\t\t\t\t\t\tSUDOKU SOLVER\n\n\n\n\n";
    cout << "Enter your 9x9 grid(Sudoku Problem) \n\n";
    */
    for(i=0;  i<9;  i++)
        for(j=0;  j<9;  j++)
            cin >> sudoku[i][j];

    Solver();

    for(i=0;  i<9;  i++)
    {
        for(j=0;  j<9;  j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }
    /*
    for(i=1;  i<=9;  i++)
    {
        cout << sub_grid[{2,2}][i] << " ";
    }
    */
    return 0;
}
