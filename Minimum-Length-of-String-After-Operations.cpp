class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int , int>map;
        int n = s.size();
        int totallength =0;
        for(int i =0 ; i<=n; i++){
            map[s[i]-'a']++;
        }
         for(auto it:map){
            if(it.second ==0){
                continue;
            }
            else if(it.second%2==0){
              totallength+=2;
            }
            else{
                totallength+=1;
            }
         }
         return totallength-1;


    }
};