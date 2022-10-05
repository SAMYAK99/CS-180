#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    // check each row
    for (int i = 0; i < board.size(); i++)
    {
        map<char, bool> isf;
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
                continue;
            if (isf.find(board[i][j]) == isf.end())
            {
                isf.insert({board[i][j], true});
            }
            else
            {
                // cout<<'row'<<board[i][j];
                return false;
            }
        }
    }
    // check each column
    for (int j = 0; j < board[0].size(); j++)
    {
        map<char, bool> isf;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][j] == '.')
                continue;
            if (isf.find(board[i][j]) == isf.end())
            {
                isf.insert({board[i][j], true});
            }
            else
            {
                // cout<<'column';
                return false;
            }
        }
    }
    // check each 3x3 grid
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            for (int j = 0; j < 9; j++)
            {
                if (j % 3 == 0)
                {
                    map<char, bool> isf;
                    for (int p = 0; p < 3; p++)
                    {
                        for (int q = 0; q < 3; q++)
                        {
                            // board[i+p][j+q]
                            if (board[i + p][j + q] == '.')
                                continue;
                            if (isf.find(board[i + p][j + q]) == isf.end())
                            {
                                isf.insert({board[i + p][j + q], true});
                            }
                            else
                            {
                                // cout<<i<<' '<<j<<' th grid';
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSudoku(board) << "\n"; // 1 if it is valid and 0 if not
    return 0;
}