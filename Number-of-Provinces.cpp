class Solution {
public:  void dfs(int node,vector<vector<int>>&adj , vector<int>& visited){
      visited[node]=1;
      for(auto it : adj[node]){
          if(visited[it]==0)
          dfs(it,adj,visited);
      }
  }
  
  
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        int  V= n;
        vector<vector<int>>vec(V);
        vector<int>visited(V,0);
        for(int i = 0; i< adj.size(); i++){
            for(int j= 0; j< n; j++){
                if(adj[i][j]==1){
                vec[i].push_back(j);
                vec[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i = 0 ; i<V; i++){
            if(visited[i]==0){
                count++;
                dfs(i,vec,visited);
            }
        }
        return count;
    }
};