class Solution {
public:

    int f(int i , int j , int n ,vector<vector<int>>& triangle ,vector<vector<int>>& dp ){
      if(i == n-1){
        return triangle[n-1][j];

      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
      int d = triangle[i][j] + f(i+1, j, n, triangle,dp);
      int dg = triangle[i][j]+f(i+1, j+1, n , triangle,dp);
      return dp[i][j]= min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0)); 
        vector<int>front(n,0);
        vector<int>curr(n,0);
        for(int j =0 ; j<n  ; j++){
        front[j]= triangle[n-1][j];
        }
        

            for(int i = n-2; i>=0; i--){
                for(int j =i ; j>=0 ; j--){
                  int d = triangle[i][j] + front[j];
                   int dy = triangle[i][j] + front[j+1];
                   curr[j]=min(d,dy);
                }
                front = curr;
            }

        




         return front[0];
    }
};