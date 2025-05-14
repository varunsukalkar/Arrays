class Solution {
public:

  



    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==0 && target==0){
                return 2;
            }
        }
      int sum = accumulate(nums.begin(),nums.end(),0);
       if ((target + sum) % 2 != 0 || abs(target) > sum) return 0;
 
      int n = nums.size();
      int q = (sum+target)/2;
      vector<vector<int>>dp(n+1,vector<int>(q+1,0));
      for(int i = 0 ; i< n+1 ; i++){
        dp[i][0]=1;
      }
      for(int i =1  ; i<n+1 ; i++){
        for(int j = 0 ; j< q+1 ; j++){
            if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }

        }
      }
      return dp[n][q];
        
    }
};