#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vector<int>>

using namespace std;
void display(vii &boxe)
{
    for (vi ar : boxe)
    {
        for (int i : ar)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafeToPlaceNumber(vii &boxe, int r, int c, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (boxe[i][c] == val)
        {
            return false;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (boxe[r][j] == val)
        {
            return false;
        }
    }
    int nr = (r / 3) * 3;
    int nc = (c / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (boxe[nr + i][nc + j] == val)
                return false;
        }
    }
    return true;
}

/* sudoku using TRUE FLASE  method */

int sudoku_01(vii &boxe, int vidx)
{
    if (vidx == 81)
    {
        display(boxe);
        return 1;
    }

    int count = 0;
    int r = vidx / 9;
    int c = vidx % 9;

    if (boxe[r][c] == 0)
    {
        for (int val = 1; val <= 9; val++)
        {
            if (isSafeToPlaceNumber(boxe, r, c, val))
            {
                boxe[r][c] = val;
                count += sudoku_01(boxe, vidx + 1);
                boxe[r][c] = 0;
            }
        }
    }
    else
    {
        count += sudoku_01(boxe, vidx + 1);
    }
    return count;
}

/* sudoku using BIT MASS method */

int sudoku_02(vii &boxe, int vidx, vi &row, vi &col, vii &mat)
{
    if (vidx == 81)
    {
        display(boxe);
        return 1;
    }

    int count = 0;
    int r = vidx / 9;
    int c = vidx % 9;

    if (boxe[r][c] != 0)
    {
        count += sudoku_02(boxe, vidx + 1, row, col, mat);
    }
    else
    {
        for (int val = 1; val <= 9; val++)
        {
            int mask = (1 << val);
            if (((row[r] & mask) == 0) && ((col[c] & mask) == 0) && ((mat[r / 3][c / 3] & mask) == 0))
            {
                boxe[r][c] = val;
                row[r] |= mask;
                col[c] |= mask;
                mat[r / 3][c / 3] |= mask;

                count += sudoku_02(boxe, vidx + 1, row, col, mat);

                boxe[r][c] = 0;
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
            }
        }
    }
    return count;
}

void sudoku_populate(vii &boxe, vi &row, vi &col, vii &mat)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int mask = (1 << boxe[i][j]);
            row[i] |= mask;
            col[j] |= mask;
            mat[i / 3][j / 3] |= mask;
        }
    }
}
void sudokuTrueFalse()
{

    vector<vector<int>> arr = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };
    cout << sudoku_01(arr, 0) << endl;
}
void sudokuBitMass()
{
    vector<vector<int>> arr = {
        {8, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 8},
        {0, 0, 1, 0, 8, 0, 0, 3, 4},
        {0, 2, 3, 0, 9, 6, 0, 0, 0},
        {0, 7, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 3, 2, 0, 6, 9, 0},
        {9, 3, 0, 0, 6, 0, 4, 0, 0},
        {5, 0, 7, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 9},
    };
    vi row(9, 0);
    vi col(9, 0);
    vii mat(3, vi(3, 0));
    sudoku_populate(arr, row, col, mat);
    cout << sudoku_02(arr, 0, row, col, mat) << endl;
}
void solve()
{
    // sudokuTrueFalse();                    /* sudoku problem using TRUE FALSE METHOD */
    sudokuBitMass(); /* sudoku problem  using BIT MASS METHOD*/
}
int main(int args, char **argv)
{
    solve();
    return 0;
}