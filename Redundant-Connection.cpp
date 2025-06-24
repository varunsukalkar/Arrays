class disjointset {
public :
vector<int>rank;
vector<int>parent;

disjointset(int n ){
rank.resize(n+1,0);
parent.resize(n+1,0);
for(int i  = 0 ; i<=n; i++){
    parent[i]=i;
}
}

int findupar(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]= findupar(parent[node]);
}


void unionbyrank(int u ,int v){
  int ulp_u = findupar(u);
  int ulp_v = findupar(v);
  if(ulp_u==ulp_v){
    return ;
  }
  if(rank[ulp_u]<rank[ulp_v]){
    parent[ulp_u]=ulp_v;
  }
  else if(rank[ulp_v]=rank[ulp_u]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disjointset ds(n);
        vector<int>ans;
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            if(ds.findupar(a)==ds.findupar(b)){
                ans.push_back(a);
                ans.push_back(b);
                return  ans;
            }
            else{
                   ds.unionbyrank(a,b);
            }
        }
        return ans;
    }
};