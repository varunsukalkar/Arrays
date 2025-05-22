class Solution {
public:
       








    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>visited(n,0);
        stack<int>st;
        vector<vector<int>>adj(n);
        for(auto it :p){
            int  a = it[0];
            int b = it[1];
            adj[a].push_back(b);
        }
       queue<int>q;
       vector<int>ans;
       vector<int>indegree(n,0);
    
       for(int i = 0 ; i< n; i++){
        for(auto it:adj[i]){
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
           q.pop();
           ans.push_back(node);
           for(auto it :adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
           }



          

            }
            if(ans.size()==n)return true;
            else return false;

    }
};