class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest=1000000;
        sort(nums.begin(),nums.end());

        for(int k =0;k< n-2; k++){
            int i =k+1;
            int j = n-1;
            while(i<j){
                int sum = nums[k]+nums[i]+nums[j];
                if( abs(target-sum)< abs(target-closest)){
                closest=sum;
                }
                if(sum<target){
                    i++;
                }
                else if(sum>target){
                    j--;
                }
                else{
                    return sum;
                }

            }
        }
        return closest;
    }
};