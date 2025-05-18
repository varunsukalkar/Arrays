class Solution {
public:

     int getans(vector<int>&curr, int n ,int ind, int prev_index , vector<vector<int>>& dp){
        if(ind == n){
            return 0;
        }
        if(dp[ind][prev_index+1]!=-1){
            return dp[ind][prev_index+1];
        }
        int nottake = 0+getans(curr,n,ind+1,prev_index,dp);
        int take =0;
        if(prev_index == -1 || curr[ind]>curr[prev_index]){
            take=1+getans(curr,n,ind+1 , ind , dp);
        }
        return dp[ind][prev_index+1]=max(nottake,take);
     }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return getans(nums,nums.size(),0,-1,dp);
        
    }
};