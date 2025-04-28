class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int k = nums.size();
        int maxi= INT_MIN;
        for(int i =0; i< k; i++){
            int minval = nums[i][0];
            pq.push({minval,i,0});
            maxi=max(maxi,minval);
        }
        vector<int>minrange={0,INT_MAX};
        while(true){



              
              vector<int>top=(pq.top());
              pq.pop();
              int minelement=top[0];
              int listindex=top[1];
              int elementindex = top[2];

              if(maxi-minelement<minrange[1]-minrange[0]){
                minrange[0]=minelement;
                minrange[1]=maxi;

              }

              if(elementindex==nums[listindex].size()-1){
                break;
              }
              int next = nums[listindex][elementindex+1];
              maxi=max(maxi,next);
              pq.push({next,listindex,elementindex+1});



              








        }
        
        
        
        
        
        
        
        
        
        
        
        return minrange;
        
        
            }
};