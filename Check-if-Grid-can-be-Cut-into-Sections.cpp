class Solution {
public:

 vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        
        sort(begin(arr),end(arr));
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        for(int i = 1; i<n; i++){
            if(arr[i][0]<ans.back()[1]){
                ans.back()[1]= max(ans.back()[1],arr[i][1]);

            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans ;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>hor;
        vector<vector<int>>vert;
        for(auto &coord : rectangles){
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];
            hor.push_back({x1,x2});
            vert.push_back({y1,y2});
        }
        vector<vector<int>> result1 = merge(hor);
        vector<vector<int>> result2 = merge(vert);
        return result1.size()>=3 || result2.size()>=3;
    }
};