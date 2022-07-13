//Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

class Solution
{
public:

    void dfs(vector<int> adj[], vector<bool> &visited, int u, stack<int> &st)
    {

        visited[u] = 1;

        for (auto it : adj[u])
        {
            if (visited[it] == 0)
                dfs(adj, visited, it, st);
        }
        st.push(u);
    }

    //Function to traverse the transpose of gaph in dfs
    void dfs_reverse(int x, vector<bool> &visited, vector<int> adj[])
    {

        visited[x] = 1;

        for (auto it : adj[x])
        {
            if (visited[it] == 0)
                dfs_reverse(it, visited, adj);
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        // Function to find number of strongly connected components in the graph.
        int ct = 0;
        stack<int> st;
        vector<bool> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
                dfs(adj, visited, i, st);
        }

        vector<int> reverse_adj[V];
        vector<bool> reverse_visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                reverse_adj[j].push_back(i);
            }
        }

        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (reverse_visited[x] == 0)
            {
                ct++;
                dfs_reverse(x, reverse_visited, reverse_adj);
            }
        }

        return ct;
    }
};