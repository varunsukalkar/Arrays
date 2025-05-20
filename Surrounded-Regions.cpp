class Solution {
public:
vector<int>drow = {-1,0,1,0};
vector<int>dcol={0,1,0,-1};


void dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int n ,int  m,int row, int col){
    visited[row][col]=1;
    for(int i = 0 ; i< 4; i++){
        int nrow = row+drow[i];
        int ncol = col+dcol[i];
        if(nrow>=0 && nrow<n && ncol >=0 && ncol<m
        && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
            dfs(board,visited,n,m,nrow,ncol);
        }
    }

}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i = 0 ; i< m; i++){
          if(!visited[0][i] && board[0][i]=='O'){
            dfs(board,visited,n,m,0,i);
          }
           if(!visited[n-1][i] && board[n-1][i]=='O'){
            dfs(board,visited,n,m,n-1,i);
          }
        }
        for(int i = 0 ; i< n; i++){
        if(!visited[i][0] && board[i][0]=='O'){
            dfs(board,visited,n,m,i,0);
          }
           if(!visited[i][m-1] && board[i][m-1]=='O'){
            dfs(board,visited,n,m,i,m-1);
          }
        }


        for(int i = 0 ; i< n; i++){
            for(int j =0  ; j< m; j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
   
    }
};