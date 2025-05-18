class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(left<right){
            int q = numbers[left]+numbers[right];
            if(q==target){
                return {left+1,right+1};
            }
            else if (q>target){
                right-=1;
            }
            else{
                left++;
            }
        }
       return {-1,-1};
    }
};