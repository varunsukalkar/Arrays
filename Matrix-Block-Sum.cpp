class Solution {
public:
     vector<vector<int>>psum;
     void initialize(vector<vector<int>> & mat){
        psum=mat;
         int n = mat.size();
          int m = mat[0].size();
        for(int i = 0 ; i< n; i++){
            for(int j = 1 ; j< m ; j++){
                psum[i][j]+=psum[i][j-1];
            }
        }
        for(int i = 0 ; i< m; i++){
            for(int j = 1 ; j< n; j++){
            psum[j][i]+=psum[j-1][i];
            }
        }
     }
     int sumregion(int row1,int col1,int row2 , int col2){
        int ans = psum[row2][col2];
        if(row1>0)ans-=psum[row1-1][col2];
        if(col1>0)ans-=psum[row2][col1-1];
        if(row1>0 && col1> 0)ans+=psum[row1-1][col1-1];
        return ans ;
     }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        psum.clear();
         initialize(mat);
          int n = mat.size();
          int m = mat[0].size();
          vector<vector<int>>matt(n,vector<int>(m,0));
         for(int i  = 0 ; i< n; i++){
            for(int j = 0 ; j< m; j++){

          
         int r1 = max(0,i-k);

         int c1 = max(0,j-k);
         int r2  = min(int(n-1),i+k);

         int c2 = min(m-1,j+k);
         matt[i][j]=sumregion(r1,c1,r2,c2);
            }}
            return matt;
    }
};