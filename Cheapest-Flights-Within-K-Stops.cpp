class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it  : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int distance = it.second.second;
            if(steps>k){
                continue;
            }
            for(auto it: adj[node]){
                int adjnode = it.first;
                int edw = it.second;
                if(distance+edw<dist[adjnode] && steps <=k){
                    dist[adjnode]=distance+edw;
                    q.push({steps+1,{adjnode,dist[adjnode]}});
                }

            }

        }
      if(dist[dst]==1e9){
        return -1;
      }
      return dist[dst];
    }
};