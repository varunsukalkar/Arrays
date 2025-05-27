class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i  = 0 ; i< n; i++){
            adj[i][i]=0;
        }
        for(auto it :edges){
            int a = it[0];
            int b = it[1];
            int c = it[2];
            adj[a][b]=c;
            adj[b][a]=c;
        }
        for(int  k = 0 ; k< n; k++){
            for(int i  = 0 ; i< n; i++){
                for(int j = 0 ; j< n ; j++){
                        if(adj[i][k]!=1e9 && adj[k][j]!=1e9){
                            adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                        }
                }
            }
        }
        int city=-1;
        int count = n+1;
        for(int i = 0  ; i< n; i++){
            int q =0;
            for(int j = 0 ; j< n; j++){
                if(adj[i][j]<= distanceThreshold){
                    q++;
                }
            }
            if(q==count){
                city=max(city,i);
            }
            else if(q<count){
                count=q;
                city=i;
            }

        }
        return city;
    }
};