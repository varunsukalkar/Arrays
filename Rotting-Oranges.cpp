class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         typedef pair<int,pair<int,int>>p;
        queue<p>q;
        int count=0;
        int onecount=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0 ; i<  n; i++){
            for(int j  = 0 ; j< m ; j++){
                if(grid[i][j]==2){
                q.push({1,{i,j}});
                 visited[i][j]=2;
                }
                if(grid[i][j]==1){
                    onecount++;
                }

            }
        }
        if(onecount==0){
            return 0;
        }
        while(!q.empty()){
            int row =q.front().second.first;

            int column = q.front().second.second;
            int time = q.front().first;
            count=max(count,time);
           
            q.pop();
            vector<int>drow={-1,0,1,0};
            vector<int>dcol ={0,1,0,-1};
            for(int i = 0 ; i<4; i++){
                int first = row+drow[i];
                int second = column+dcol[i];
                if(first>=0 && first<n && second>=0 && second<m && visited[first][second]!=2 && grid[first][second]==1 ){
                    q.push({time+1,{first,second}});
                    visited[first][second]=2;
                }
            }
        }
        for(int i =0 ; i< n; i++){
            for(int j = 0  ; j< m ;j++){
                if(visited[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count-1;
    }
};