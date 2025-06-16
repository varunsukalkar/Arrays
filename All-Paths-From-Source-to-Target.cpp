class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stack<pair<int,vector<int>>>stack;
        vector<vector<int>>ans;
        stack.push({0,{0}});
        while(!stack.empty()){
             auto[node,vec]=stack.top();
             stack.pop();
             if(node==graph.size()-1){
                ans.push_back(vec);
             }
             for(auto it : graph[node]){
                vec.push_back(it);
                stack.push({it,vec});
                vec.pop_back();
             }
        }
       return  ans;
    }
};