
class disjointset
{
    public:
    vector<int>size,parent;
    
    disjointset(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i = 0 ; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=  findparent(parent[node]);
    }
     
    void unionbysize(int u , int v)
    {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if(ulp_u == ulp_v){
            return ;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
    
};

class Solution {
  public:
   int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointset ds(n*n);
        vector<int>drow={-1 ,0,1,0};
        vector<int>dcol={0,1,0,-1};
        
        for(int i = 0 ; i< n; i++){
            for(int j = 0 ; j< n; j++){
                
                if(grid[i][j]==0){
                    continue;
                }
                
                for(int k = 0 ; k<4;k++){
                    int adjrow  = i+drow[k];
                    int adjcol = j + dcol[k];
                    
                    
                    if(adjrow>=0 && adjrow<n  && adjcol>=0 && adjcol<n && grid[adjrow][adjcol]==1){
                      
                      int node1 = n*i +j;
                      int node2 = adjrow * n +adjcol;
                      
                        ds.unionbysize(node1,node2);
                    }
                }

                
            }
        }
        
        
        int maxians = 0;
            for(int i = 0 ; i< n; i++){
            for(int j = 0 ; j< n; j++){
                
                if(grid[i][j]==1){
                    continue;
                }
                set<int>set;
                for(int k = 0 ; k<4;k++){
                    int adjrow  = i+drow[k];
                    int adjcol = j + dcol[k];
                    
                    
                    if(adjrow>=0 && adjrow<n  && adjcol>=0 && adjcol<n && grid[adjrow][adjcol]==1){
                      int node = adjrow * n + adjcol;
                    set.insert(ds.findparent(node));
                    }
                }
                
                int sum = 1;
                for(auto it : set){
                    sum+=ds.size[it];
                    
                }
           maxians = max(maxians,sum);
                
            }
        }
        
        for(int i = 0 ; i<n*n ; i++){
            maxians = max(maxians,  ds.size[ds.findparent(i)]);
        }
        
        
        return maxians;
        
        
        
        
        
        
    }
};