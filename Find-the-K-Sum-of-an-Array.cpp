class Solution {
public:
 


    long long kSum(vector<int>& nums, int k) {
       typedef pair<long long , int> p
       ;
       int n = nums.size();
       long long max_sum = 0;
       for(int i = 0 ; i< n; i++){
        max_sum+=(long long)max(0,nums[i]);
        nums[i]= abs(nums[i]);
       }
        sort(nums.begin(),nums.end());
       
        vector<long long >vts = {0};
        priority_queue<p , vector<p>,greater<p>>min_heap;
        min_heap.push({nums[0],0});
       
        while(vts.size()<k){
            auto top = min_heap.top();
            long long value = top.first;
            int index = top.second;
            min_heap.pop();
            vts.push_back(value);
            if(index<n-1){
                min_heap.push({value+nums[index+1],index+1});
                min_heap.push({value+nums[index+1 ]-nums[index],index+1});
            }
        }
        return max_sum-vts[k-1];
    }
};