class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlevel=0;
        for(int i= 0 ; i<nums.size(); i++){
            if(i > maxlevel){
              return false;
            }
            maxlevel =  max(maxlevel , i+nums[i]);
            
        }
        return true;
    }
};