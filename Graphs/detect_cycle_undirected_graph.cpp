void dfs(int root, vector<int> adj[], vector<bool> &vis, int parent, bool &f)
{
    vis[root] = true;
    for (auto i : adj[root])
    {
        if (!vis[i])
            dfs(i, adj, vis, root, f);
        else if (vis[i] && i != parent)
        {
            f = true;
            return;
        }
    }
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> vis(V);
    bool f = false;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, -1, f);
        if (f)
            break;
    }
    return f;
}