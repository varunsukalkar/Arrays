# include <bits/stdc++.h>
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int index = 0 ;
        while(s[index]=='9'){
            index++;
        }
        char c = s[index];
        for(int i = 0 ; i< s.size(); i++){
           if(s[i]==c){
            s[i]='9';
           }
        }
        int maxi = stoi(s);
        string numm = to_string(num);
        char q = numm[0];
        for(int i = 0 ; i<numm.size(); i++ ){
            if(numm[i]==q){
                numm[i]='0';
            }
        }
        int mini = stoi(numm);
        return maxi - mini;

    }
};