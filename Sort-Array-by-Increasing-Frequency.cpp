class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>map;
        typedef pair<int,int> p ; 
        priority_queue<p , vector<p> , greater<p>>q ; 
        for(int i  = 0 ; i< nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto it : map){
            q.push({it.second,-it.first});

        }
        vector<int>vec;
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            for(int i = 0 ; i< it.first ; i++){
                vec.push_back(-it.second);
            }
            

        }
        return vec;
    }
};