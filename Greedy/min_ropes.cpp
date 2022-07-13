//There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

class solution
{
public:
    // Function to return the minimum cost of connecting the ropes.

    long long minCost(long long arr[], long long n)
    {
        if (n == 1)
            return 0;

        priority_queue<long long, vector<long long>, greater<long long> > q;
        long long cost = 0;

        for (long long i = 0; i < n; i++)
            q.push(arr[i]);

        while (q.size() != 1)
        {
            long long temp = 0;
            temp += q.top();
            q.pop();
            temp += q.top();
            q.pop();
            q.push(temp);
            cost += temp;
        }
        return cost;
    }
};