class Solution {
public:

 


    int coinChange(vector<int>& coins, int a) {
        int n = coins.size();
    vector<vector<int>>dp(n+1 , vector<int>(a+1 , 0));
        for(int i = 0 ; i< a+1 ; i++){
            dp[0][i]= INT_MAX-1;
        }
        for(int i = 1 ; i< n+1 ; i++){
            dp[i][0]=0;
        }
        for(int i = 1 ;i< a+1 ; i++ ){
            if(i%coins[0]==0){
               dp[1][i]=i/coins[0];
            }else{
            dp[1][i]=INT_MAX-1;
            }
        }
        for(int i = 2 ; i< n+1 ; i++){
            for(int j = 1; j< a+1 ; j++){
                  if(coins[i-1]<=j){
                    dp[i][j]= min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                  }
                  else{
                    dp[i][j]=dp[i-1][j];
                  }
            }

        }
        if(dp[n][a]!=INT_MAX-1)
        return dp[n][a];
        else
        return -1;



    }



};