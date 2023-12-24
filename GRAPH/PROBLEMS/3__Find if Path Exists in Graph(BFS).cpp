class Solution {
public:
    void bfs(int source,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
        queue<int>q;
        q.push(source);
        vis[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &v:adj[node]){
                if(vis[v]==false){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
           int u=vec[0];
           int v=vec[1];
           adj[u].push_back(v);
           adj[v].push_back(u) ;
        }

        bfs(source,adj,vis);
        return vis[destination];
    }
};
