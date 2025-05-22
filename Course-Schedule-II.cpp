class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
            vector<vector<int>>adj(n);
        for(auto it :p){
            int a = it[1];
            int b = it[0];
            adj[a].push_back(b);
        }
        vector<int>ans;
        queue<int>q;
        vector<int>indegree(n,0);
        for(int i = 0 ; i<n; i++){
            for(auto it :adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i = 0 ; i< n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it :adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==n)return ans;
        else return {};
    }
};