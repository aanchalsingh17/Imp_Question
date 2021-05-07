#include<bits/stdc++.h>
using namespace std;
void deleteEdge(int u,int v,vector<int> adj[]){
   for(int i=0;i<adj[u].size();i++){
       if(adj[u][i] == v){
           adj[u].erase(adj[u].begin() + i);
       }
   }
   for(int i=0;i<adj[v].size();i++){
       if(adj[v][i] == u){
           adj[v].erase(adj[v].begin()+i);
       }
   }
}
void dfs(vector<int> adj[],int curr,vector<bool>& vis){
    vis[curr] = true;
    for(int i=0;i<adj[curr].size();i++){
        int next = adj[curr][i];
        if(!vis[next]){
            dfs(adj,next,vis);
        }
    }
}
vector<vector<int>> criticalConnections(vector<int> adj[],int node,int edges){
    vector<vector<int>> ans;
    for(int i=0;i<edges;i++){
        int u = adj[edges][0];
        int v = adj[edges][1];
        deleteEdge(u,v,adj);
        vector<bool> vis(node,false);
        int cnt = 0;
        for(int j=0;j<node;j++){
            if(vis[j]==false){
                dfs(adj,j,vis);
                cnt++;
                if(cnt>1){
                    ans.push_back({u,v});
                    break;
                }
            }
        }

    }


    return ans;
}
int main(){
    int node;
    cin >> node;
    int edges;
    cin >> edges;
    vector<int> adj[node];
    for(int i=0;i<edges;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> bridge = criticalConnections(adj,node,edges);
    return 0;
}