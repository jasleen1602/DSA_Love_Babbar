/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/


class Solution
{
public:
    vector<vector<string> > ans;

    bool isValid(int row, int col, vector<string> board)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return 0;
        }
        for (int i = row - 1, ct = 1; i >= 0; i--, ct++)
        {
            if (col - ct >= 0 && board[i][col - ct] == 'Q')
                return 0;
            if (col + ct < board.size() && board[i][col + ct] == 'Q')
                return 0;
        }
        return 1;
    }

    void solve(vector<string> &board, int row, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
            if (isValid(row, col, board))
            {
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.';
            }
    }

    vector<vector<string> > solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return ans;
    }
};