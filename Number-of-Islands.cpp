class Solution {
public:
   
void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});

    // Only 4 directions: up, right, down, left
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                visited[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}
   
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int count =0;

        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m; j++){
               if(!visited[i][j] && grid[i][j]=='1'){
                count++;
                bfs(grid,visited,i,j);
               }
            }
        }
        return count;
    }
};