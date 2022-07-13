class Solution
{
public:
    int result = 0;
    void solve(int r, int c, vector<vector<int> > M, int val)
    {
        if (c == M[0].size() - 1)
        {
            result = max(result, val + M[r][c]);
            return;
        }
        if (r != 0)
            solve(r - 1, c + 1, M, val + M[r][c]);
        if (r != M.size() - 1)
            solve(r + 1, c + 1, M, val + M[r][c]);
        solve(r, c + 1, M, val + M[r][c]);
    }

    int maxGold(int n, int m, vector<vector<int> > M)
    {
        // code here
        for (int i = 0; i < n; i++)
            solve(i, 0, M, 0);

        return result;
    }
};

// DYNAMIC PROGRAMMING

class Solution
{
public:
    int solve(int i, int j, int m, int n, vector<vector<int> > &dp, vector<vector<int> > &M)
    {
        if (i < 0 or i >= n or j >= m)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int a = M[i][j] + solve(i - 1, j + 1, m, n, dp, M);
        int b = M[i][j] + solve(i, j + 1, m, n, dp, M);
        int c = M[i][j] + solve(i + 1, j + 1, m, n, dp, M);
        return dp[i][j] = max(a, max(b, c));
    }
    int maxGold(int n, int m, vector<vector<int> > M)
    {
        // code here
        vector<vector<int> > dp(n, vector<int>(m, -1));
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s = max(s, solve(i, 0, m, n, dp, M));
        }
        return s;
    }
};