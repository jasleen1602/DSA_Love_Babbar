class solution
{
public:
    // Function for dfs
    bool dfs(vector<int> adj[], vector<bool> &visited, int u, vector<bool> &local)
    {
        visited[u] = 1;
        local[u] = 1;
        for (auto it : adj[u])
        {
            if (visited[it] == 0)
            {
                if (dfs(adj, visited, it, local))
                    return 1;
            }
            else if (local[it] == 1)
                return 1;
        }
        local[u] = 0;
        return 0;
    }

    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, 0);
        vector<bool> local(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(adj, visited, i, local))
                    return true;
            }
        }
        return false;
    }
};