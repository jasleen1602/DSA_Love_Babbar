/*
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.
*/

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int> > result;
    void solve(vector<int> &arr, int pos, int sum, int key, vector<int> &comb)
    {

        if (sum == key)
        {
            result.push_back(comb);
            return;
        }
        if (sum > key || pos == arr.size())
            return;

        for (int i = pos; i < arr.size(); i++)
        {
            if (i > pos && arr[i] == arr[i - 1])
                continue;
            int x = arr[i];
            comb.push_back(x);
            solve(arr, i, sum + x, key, comb);
            comb.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &arr, int key)
    {
        vector<int> comb;
        sort(arr.begin(), arr.end());
        solve(arr, 0, 0, key, comb);
        return result;
    }
};