class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        typedef pair<int,int> p ; 
        priority_queue<p,vector<p>,greater<p>>q;
        for(int i = 0 ; i< arr.size(); i++){
            q.push({abs(x-arr[i]),arr[i]});
        }
        vector<int>ans;
        while(k--){
             ans.push_back(q.top().second);
             q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};