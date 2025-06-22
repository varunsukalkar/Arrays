class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minlen = INT_MAX;
        int startindex= -1;
        int l =0;
        int r = 0 ;
        int count=0;
        vector<int>hash(256,0);
        for(int i  =0; i<t.size(); i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0){
                count++;

            }
            hash[s[r]]--;
            while(count==m){
                 if(r-l+1<minlen){
                    minlen = r-l+1;
                    startindex = l;
                 }
                 hash[s[l]]++;
                 if(hash[s[l]]>0){
                    count--;
                 }
                 l++;
            }
            r=r+1;
        }
        return startindex==-1?"":s.substr(startindex,minlen);
    }
};