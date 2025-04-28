class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x =0;
        for(int i  =0 ; i< n+1; i++ ){
            x=x^i;
        }
        for(int i = 0 ; i<n;i++){
            x=x^nums[i];
        }
        return x;
    }
};