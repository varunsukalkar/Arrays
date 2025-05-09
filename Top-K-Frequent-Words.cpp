class Solution {
 
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>map;
        int n = words.size();
        for(int i  =  0 ; i< n; i++){
            map[words[i]]++;
        }
        typedef pair<int,string> p ;


           
   auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second; // lexicographically smaller first
            return a.first < b.first; // higher frequency first
        };






        priority_queue<p,vector<p>,decltype(comp)>pq(comp);
       for(auto it : map){
        pq.push({it.second,it.first});
        
       }
       vector<string>vec;

       while(k--){
        
       vec.push_back(pq.top().second);
       pq.pop();
       }

return vec;

    }
};