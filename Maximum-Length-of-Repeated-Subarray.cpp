class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0; i<= n ; i++){
            dp[i][0]=0;
        }
        for(int j = 0 ; j<= m ; j++){
            dp[0][j]=0;
        }
    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<=m ; j++){
            if(nums1[i-1]==nums2[j-1]){
             
               int val = 1+dp[i-1][j-1];
                dp[i][j]= val;
                ans = max(ans,val );
            }
            else{
                dp[i][j]=0;
            }

        }

    }
    return ans;
    }
};