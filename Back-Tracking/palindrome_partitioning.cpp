/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.
*/

class Solution
{
public:

    vector<vector<string>> ans;

    bool isPalin(string s)
    {
        if (s.size() == 1)
            return true;
        else if (s.size() == 2)
            return s[0] == s[1];

        int l = 0, h = s.size() - 1;
        while (l <= h)
        {
            if (s[l] != s[h])
                return false;
            l++;
            h--;
        }

        return true;
    }

    void solve(string s, vector<string> &palindrome)
    {
        for (int i = 0; i < s.size(); i++)
        {
            string temp = s.substr(0, i + 1);
            if (isPalin(temp))
            {
                palindrome.push_back(temp);
                if (i == s.size() - 1)
                    ans.push_back(palindrome);
                    
                solve(s.substr(i + 1), palindrome);
                palindrome.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s)
    {
        vector<string> palindrome;
        solve(s, palindrome);
        return ans;
    }
};