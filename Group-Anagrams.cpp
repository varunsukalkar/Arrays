class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>map;
        for(auto it :strs){
            string s = it;
             sort(s.begin(),s.end());
            map[s].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it :map){
          vector<string>vec = it.second;
                ans.push_back(vec);
          
        }
        return ans;
    }
};