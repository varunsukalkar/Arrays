class NumMatrix {
public:
vector<vector<int>>psum;
    NumMatrix(vector<vector<int>>& matrix) {
        psum=matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ;i< n; i++){
            for(int  j = 1 ; j< m; j++){
                psum[i][j]+=psum[i][j-1];
            }
        }
        for(int i = 0; i< m; i++){
            for(int j = 1 ; j< n; j++){
                psum[j][i]+=psum[j-1][i];
            }
        }
    }

    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = psum[row2][col2];
        if(row1>0 )ans-=psum[row1-1][col2];
        if(col1>0)ans-=psum[row2][col1-1];
        if(row1>0 && col1>0)ans+=psum[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */