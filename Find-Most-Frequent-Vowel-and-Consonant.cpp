class Solution {
public:
    int maxFreqSum(string s) {
     unordered_map<char , int>cmap;
        
        priority_queue<pair<int,char>>cpq;
        for(int i = 0 ; i< s.size(); i++){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
            cmap[s[i]]++;
            }
        }
        for(auto it : cmap){
             cpq.push({it.second,it.first});
        }









        
         unordered_map<char , int>map;
        
        priority_queue<pair<int,char>>pq;
        for(int i = 0 ; i< s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||s[i]=='o' || s[i]=='u'){
                
            
            map[s[i]]++;
            }
        }
        for(auto it : map){
             pq.push({it.second,it.first});
        }
         

    int vcount = pq.empty() ? 0 : pq.top().first;
int ccount = cpq.empty() ? 0 : cpq.top().first;
        return vcount+ccount;
    }
};