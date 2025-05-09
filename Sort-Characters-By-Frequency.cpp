class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int>map;
        
        priority_queue<pair<int,char>>pq;
        for(int i = 0 ; i< s.size(); i++){
            map[s[i]]++;
        }
        for(auto it : map){
             pq.push({it.second,it.first});
        }
          string k=\\;
        while(!pq.empty()){
            
           int l =pq.top().first;
           for(int i =0 ; i< l ;i++){
            k+=pq.top().second;
           }
           pq.pop();
        }

return k;

    }
};