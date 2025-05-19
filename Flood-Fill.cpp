class Solution {
public:
    void bfs(vector<vector<int>>& image,vector<vector<int>>& visited, int sr, int sc,int n,int m, int color){
      vector<int>drow={-1,0,1,0};
      vector<int>dcol = {0,1,0,-1};
        int originalcolor = image[sr][sc];
      queue<pair<int,int>>q;
      q.push({sr,sc});
      while(!q.empty()){
        int first = q.front().first;
        int second = q.front().second;
        visited[first][second]=1;
       q.pop();
       image[first][second]=color;

        for(int i = 0 ; i< 4 ; i++){
            int row = first+drow[i];
            int col = second+dcol[i];
            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==originalcolor && visited[row][col]==0
            ){

                q.push({row,col});
            }
        }
      }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
           bfs(image,visited,sr,sc,n,m,color);
             return image;
    }
};