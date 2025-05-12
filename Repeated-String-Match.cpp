class Solution {
public:

   vector<int>computelps(string pattern){
    int m = pattern.size();
    vector<int>lps(m,0);
    int len = 0;
    int i = 1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];

            }
            else{
                lps[i]=0;
                i++;
            }
        }
        
    }
    return lps;
   }

   int  kpm(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    vector<int>lps = computelps(pattern);
    int i = 0;
    int j = 0 ;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            return 1;
            j=lps[j-1];
        }
        else if(i< n && text[i]!=pattern[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return 0;
   }

















    int repeatedStringMatch(string a, string b) {
         int m=a.size();
        int n=b.size();
        
        int ans=1;
        string tmp=a;
        while(a.size() < b.size()){
            a += tmp;
            ans++;
        }
        
        if(kpm(a,b)){
            return ans;
        }
        a += tmp;
        if(kpm(a,b)){
            return ans+1;
        }
        return -1;
    }
};