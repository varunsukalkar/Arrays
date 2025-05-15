class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int j = 0; j<=m; j++){
            dp[0][j]=0;
        }
        for(int i=1 ; i<=n; i++){
            for(int j =1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       
       int len = dp[n][m];
       int i = n;
       int j = m;
       string ans="" ;
       while(i>0 && j>0){
         if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
         }
         else if(dp[i-1][j]>dp[i][j-1]){
               ans+=s1[i-1];
               i--;
         }
         else{
            ans+=s2[j-1];
            j--;
         }
       }

       while(i>0){
        ans+=s1[i-1];
        i--;
       }
       while(j>0){
        ans+=s2[j-1];
        j--;
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};