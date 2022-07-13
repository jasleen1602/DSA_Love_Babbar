class solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], int u, vector<bool> &visited, vector<int> &v)
    {
        v.push_back(u);
        visited[u] = 1;
        for (auto it : adj[u])
        {
            if (visited[it] == 0)
                dfs(adj, it, visited, v);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> v;
        vector<bool> visited(V, 0);
        dfs(adj, 0, visited, v);
        return v;
    }
};