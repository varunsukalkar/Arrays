class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
            unordered_map<int,int>color;
            vector<int>ans(q.size());
            unordered_map<int,int>rating;
            for(int i = 0 ; i< q.size(); i++){
                if(rating.find(q[i][0])!=rating.end()){
                    int a = rating[q[i][0]];
                    color[a]--;
                    if(color[a]==0){
                        color.erase(a);
                    }
                    
                }
                
                rating[q[i][0]]=q[i][1];
                color[q[i][1]]++;
                ans[i]=color.size();
                
            }
            return ans;
    }
};