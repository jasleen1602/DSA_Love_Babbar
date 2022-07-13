// Function to return Breadth First Traversal of given graph.

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it:adj[curr]){
                if(visited[it])
                    continue;
                q.push(it);
                visited[it]=true;
            }
        }
        return ans;
    }