class Solution {
public:

      
      void cheack(int index , vector<int>& nums, vector<vector<int>>& v , int n){
        if(n<=index){
            v.push_back(nums);
            return ; 
        }
        for(int i = index ; i< n; i++){
            swap(nums[i],nums[index]);
            cheack(index+1 , nums,v,n);
            swap(nums[i],nums[index]);
        }
      }






    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>v;
       int n = nums.size();
       cheack(0  , nums,v,n);
       return v;

    }
};