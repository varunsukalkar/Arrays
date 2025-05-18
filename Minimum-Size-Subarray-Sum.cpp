class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = 0;
        int n=nums.size();
     
        while(j<nums.size()){
                sum+=nums[j];
            while(sum>=target){
                    sum=sum-nums[i];
                    len = min(j-i+1,len);
                    i++;
                }    
                j++;
                
                
        }
        if(len==INT_MAX){
            return 0;
        }
          return len;

    }

     
       
    
};