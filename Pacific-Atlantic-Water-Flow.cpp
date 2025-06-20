class Solution {
public:
    // Directions for 4 possible moves (up, right, down, left)
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int m, n;

    // Depth-first search (DFS) to explore reachable cells

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col){
        vis[row][col] = true;

        for(int i = 0; i < 4; i++){
            int adjR = row + dr[i];
            int adjC = col + dc[i];
          	
            // Check if the move is valid and not visited, and if the current height allows flow

            if(adjR >= 0 && adjR < m && adjC >= 0 && adjC < n && !vis[adjR][adjC] && 
                 heights[adjR][adjC] >= heights[row][col]){
                dfs(heights, vis, adjR, adjC);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        // visited array for cells reachable from Pacific Ocean (top and left borders)
        vector<vector<bool>> pac(m, vector<bool>(n, false));

        // visited array for cells reachable from Atlantic Ocean (bottom and right borders)
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            dfs(heights, pac, i, 0);        // first column (Pacific)
            dfs(heights, atl, i, n-1);       // last column (Atlantic)
        }
        for(int j = 0; j < n; j++){
            dfs(heights, pac, 0, j);         // first row (Pacific)
            dfs(heights, atl, m-1, j);       // last row (Atlantic)
        }
        
        vector<vector<int>> result;
	  
        // Collect the cells where water can flow to both oceans

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};


