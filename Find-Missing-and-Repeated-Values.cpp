class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       long long  int n = grid.size();
      long long   int tn = n*n;
        long long sum = (tn * (tn + 1)) / 2;
        long long square= 0;
        long long adding =0;
        long long squaresum = (long long )(tn * (tn + 1) * (2 * tn + 1)) / 6;
        for(int i = 0; i<n;i++){
             for(int j=0;j<n;j++){
                adding+=grid[i][j];
                square+= (long long )grid[i][j] * (long long )grid[i][j];
             }
        } 
        int val1 = adding-sum;
        int val2 = square-squaresum;
        val2 = val2/val1;

         long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};


    }
};