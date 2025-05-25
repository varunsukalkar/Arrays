class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
         if(grid.size()==1 && grid[0].size()==1 && grid[0][0] == 0) return 1;
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        q.push({1,{0,0}});
        while(!q.empty()){
            int distance = q.front().first;
            int node1 = q.front().second.first;
            int node2 = q.front().second.second;
            q.pop();
            for(int i = -1 ; i<=1 ; i++){
                for(int j = -1 ; j<=1 ; j++){
                    int newr = node1+i;
                    int newc = node2+j;

                    if(newr>=0 && newr <n  && newc>= 0 && newc< m && grid[newr][newc]==0
                     && dist[newr][newc]==0 ){
                                 dist[newr][newc]=1;

                                 if(newr==n-1 && newc == m-1){
                                    return distance+1;

                                 }

                                 q.push({distance+1,{newr,newc}});
                    }
                }
            }

        }
        return -1;
    }
};