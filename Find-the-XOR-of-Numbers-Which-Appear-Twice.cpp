class Solution {
public:
    int duplicateNumbersXOR(vector<int>& n) {
     unordered_map<int,int> map;
     int ans = 0 ; 
     for(int i = 0 ; i< n.size() ; i++){
        int a= n[i];
        map[a]++;
     }   
     vector<int> v;
     for( auto it : map){
        if(it.second==2){
            v.push_back(it.first);

        }
     }

     if(v.size()>0){
     for(int i =0 ; i< v.size() ;i++){
        ans=ans^v[i];
     }

     }else{
        return 0 ;
     }

      return ans;
    }
};