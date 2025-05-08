class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        vector<vector<int>>vec;
        typedef pair<int,pair<int,int>> p ;
        priority_queue<p > q;
        for(int i = 0 ; i< arr.size() ; i++){
            int a = arr[i][0];
            int b = arr[i][1];
            int c = (a*a)+(b*b);
         q.push({c,{a,b}});      
         if(q.size()>k){
            q.pop();
         }  


        }
        while(!q.empty()){
            auto it =q.top();
            q.pop();
            int a = it.second.first;
            int b = it.second.second;
            vector <int> k;
            k.push_back(a);
            k.push_back(b);
            vec.push_back(k);

        }
        return vec;
    }
};