class Solution {
public:
    string longestPrefix(string s) {
        int m = s.size();
        vector<int>lps(m,0);
        int len = 0;
        int i = 1;
        while(i<m){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return s.substr(0,len);
    }
};