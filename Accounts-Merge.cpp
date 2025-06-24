

class disjointset{
    public :
    vector<int>rank;
    vector<int>parent;
     
    disjointset(int n ){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        
        for(int i  = 0 ; i<= n;   i++){
            parent[i]=i;
        }
    }
    
    int parentupar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=parentupar(parent[node]);
    }
    
    void unionbyrank(int u , int v){
        int ulp_u = parentupar(u);
        int ulp_v = parentupar(v);
        if(ulp_u==ulp_v){
            return ;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
         parent[ulp_v]=ulp_u;   
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    
};

class Solution {
  public:
      vector<vector<string>> accountsMerge(vector<vector<string>>& details) {

        // code here
        int n = details.size();
        disjointset ds(n);
        unordered_map<string,int>map;
        for(int i = 0 ; i< n; i++){
            int m = details[i].size();
            for(int j = 1; j<m ; j++ ){
                string temp = details[i][j];
                if(map.find(temp)==map.end()){
                    map[temp]=i;
                }
                else{
                    ds.unionbyrank(i,map[temp]);
                }
            }
        }
        
        vector<vector<string>>temp(n);
        for(auto it : map){
            string str = it.first;
            int node = ds.parentupar(it.second);
            temp[node].push_back(str);
        }
        
        vector<vector<string>>ans;
        for(int i = 0; i<n; i++){
            if(temp[i].size()==0){
                continue;
            }
            sort(temp[i].begin(),temp[i].end());
            vector<string>vec;
            vec.push_back(details[i][0]);
            for(auto it :temp[i]){
                vec.push_back(it);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
