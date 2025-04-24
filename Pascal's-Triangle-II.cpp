class Solution {
public:
    vector<int> getRow(int n) {
        n=n+1;
      long long   int ans = 1;
        vector<int>ansrow;
        ansrow.push_back(1);
        for(int i = 1; i<n; i++){
            ans = ans*(n-i);
            ans= ans/i;
            ansrow.push_back((int)ans);
        }
        return ansrow;
    }
};