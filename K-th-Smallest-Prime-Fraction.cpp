class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if(arr.size()==2 && k==1){
            return arr;
        }
        typedef pair<double,pair<int,int>> p;
        priority_queue<p>pq;
        for(int i = 0 ; i< arr.size()-1; i++){
            for(int j = i+1 ; j< arr.size(); j++){
                double  kk = (double)arr[i]/arr[j];
                  pq.push({kk,{arr[i],arr[j]}});
                  if(pq.size()>k){
                    pq.pop();
                  }
            }
        }
        vector<int>vec;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        
        vec.push_back(a);
vec.push_back(b);
        return vec;

    }
};