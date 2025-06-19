class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=1;
        int mini = nums[0];
        int n = nums.size();
        for(int i = 1 ; i< n; i++){
            if(nums[i]-mini>k){
                mini=nums[i];
                count++;
            }
            
        }
        return count;
    }
};