class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
         vector<int>ans;
        if(find(nums.begin(),nums.end(),x)!=nums.end()){
       vector <int> vec;
       for(int i = 0 ; i< nums.size(); i++){
        if(nums[i]==x){
            vec.push_back(i);
        }

       }
    
       for(int i = 0 ; i< q.size(); i++){
         if(q[i]>vec.size()){
            ans.push_back(-1);
         }
         else{
            ans.push_back(vec[q[i]-1]);
         }
       }




        }
        else{
            for(int i = 0 ; i<q.size(); i++){
                ans.push_back(-1);
            }
        }
       
        return ans;
    }
};