class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(), 0);
        int left = 0;
        for(int i = 0 ; i< nums.size(); i++){
            int val = nums[i];
            sum-=val;
            if(sum==left){
                return i;
            }
            left +=val;
        }
        return -1;
    }
};