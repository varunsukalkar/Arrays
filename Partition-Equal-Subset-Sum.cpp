class Solution {
public:

    bool f(int index , vector <int> & nums , int target,vector<vector<int>> & dp){
        if(index==0){
            if(nums[0]==target){
                return true;
            }else{
                return false;
            }
        }
        if(target==0){
            return true;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool nottake = f(index-1,nums,target,dp);
        bool take = false;
        if(target>=nums[index]){
            take = f(index-1,nums,target-nums[index],dp);


        }
        return  dp[index][target]= nottake || take;

    }
    bool canPartition(vector<int>& nums) {
       int sum = accumulate(nums.begin(),nums.end(),0);
       if(sum%2!=0){
        return false;
       }
int target = sum/2;
int n = nums.size();



       vector<vector<bool>>vec(n+1, vector<bool>(target+1,false));
       for(int i = 0 ; i< n+1 ; i++){
    vec[i][0]=true;
}
    //    for(int i = 1; i< n+1;i++){
    //        for(int j = 1; j< j+1 ; j++){
    //         if(nums[i-1]<=j){
    //             vec[i][j] = vec[i-1][j-nums[i-1]] || vec[i-1][j]; 
    //         }
    //         else{
    //             vec[i][j]=vec[i-1][j];
    //         }
    //        }
    //    }
    for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= target; j++) {
        if (nums[i - 1] <= j) {
            vec[i][j] = vec[i - 1][j - nums[i - 1]] || vec[i - 1][j];
        } else {
            vec[i][j] = vec[i - 1][j];
        }
    }
}

       return vec[n][target];















    }
};