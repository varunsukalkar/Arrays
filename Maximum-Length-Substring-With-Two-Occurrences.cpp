class Solution {
public:    
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        int ans=1;
        while(i<n && j<n){
            mp[s[j]]++;
            for(auto a:mp){
                while(i<n && mp[a.first]>=3){
                    mp[s[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    
};