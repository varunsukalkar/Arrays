class Solution {
public:
     vector<vector<int>>vec;
    void  solve(int index,vector<int>& ds,vector <int>arr,int n ){
     if(index==n){
        vec.push_back(ds);
        return;

     }
     solve(index+1,ds,arr,n);
     ds.push_back(arr[index]);
     solve(index+1,ds,arr,n);
     ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>temp;
    int n = nums.size();
    solve(0,temp,nums,n);
    return vec;
    }
};