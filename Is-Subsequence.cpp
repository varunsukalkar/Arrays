class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        
        int m = t.size();
        if(n==0 && m==0){
            return true;
        }
        if(n!=0 && m==0){
            return false;
        }
        if(n==0 && m!=0){
            return true;
        }

        vector<vector<int>>dp(n+1 , vector<int>(m+1,0));
        for(int i =1 ; i<=n; i++){
            for(int j = 1  ; j<= m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int k = dp[n][m];
        return (k==n);
    }
};