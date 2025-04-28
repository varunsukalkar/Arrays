class Solution {
public:

    int f(int index , int buy ,int n , vector<int> & prices , int fee,vector<vector<int>>& dp ){
       if(index>=n){
        return 0;
       }
       if(dp[index][buy]!=-1){
        return dp[index][buy];
       }
       if(buy==0){
        return dp[index][buy]= max(-prices[index]+f(index+1,1,n,prices,fee,dp) , 0+f(index+1,0,n,prices,fee,dp));
       }
       return dp[index][buy]= max(prices[index]-fee+f(index+1,0,n,prices,fee,dp),0+f(index+1,1,n,prices,fee,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1 , vector<int>(3 , 0));
           for(int index = n-1 ; index>=0 ; index--){
            for(int buy = 0 ; buy <=1; buy++){
                  if(buy==0){
        dp[index][buy]= max(-prices[index]+dp[index+1][1] , 0+dp[index+1][0]);
       }else{
        dp[index][buy]= max(prices[index]-fee+dp[index+1][0],0+dp[index+1][1]);
       }
    }
            }
            return dp[0][0];
           }
        
};