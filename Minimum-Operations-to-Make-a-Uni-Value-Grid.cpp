class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>vec;
        int k = grid[0][0] % x;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[0].size();  j++){
                if(grid[i][j]%x == k){
                vec.push_back(grid[i][j]);
                }else{
                    return -1;
                }
            }
        }
        int median = vec.size()/2;
        int count=0;
        sort(vec.begin(),vec.end());
        for(int i = 0; i<vec.size(); i++){
         count+= (abs(vec[i]-vec[median]))/x;
        }
        return count;
    }
};