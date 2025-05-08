class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int>m;
        priority_queue<m>q;
        unordered_map<int,int>map;
        for(int i = 0 ; i< nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto it :map){
            q.push({it.second,it.first});
        }
        vector<int>vec;
        while(k-- && !q.empty()){
            vec.push_back(q.top().second);
            q.pop();
        }
        return vec;

    }
};