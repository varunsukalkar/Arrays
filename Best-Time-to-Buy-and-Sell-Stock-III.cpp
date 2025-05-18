class Solution {
public:
int f(int index , int buy , int cap , int n , vector<int>&prices , vector<vector<vector<int>>>& dp)
{
    if(index == n || cap ==0 ){
        return 0;
    }
    if(dp[index][buy][cap]!=-1){
        return dp[index][buy][cap];
    }
    int profit ;
    if(buy==1){
        profit = max(
                -prices[index] + f(index+1 , 0 , cap , n , prices , dp) , 
                0              + f( index+1 , 1 , cap , n , prices , dp)
        );
    }
   if(buy==0)
    { 
         profit=max(
            prices[index]+f (index+1 , 1, cap-1 ,n, prices , dp),
            0+ f( index+1 , 0 , cap ,n, prices , dp)
         );

    }
   return dp[index][buy][cap]=profit ;
}




    int maxProfit(vector<int>& prices) {
 int n = prices.size();
 vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
 return f(0 , 1,2,n, prices,dp );
    }
};