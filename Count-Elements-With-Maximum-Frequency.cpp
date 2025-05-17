class Solution {
public:
    int maxFrequencyElements(vector<int>& v) {
        int count=0;
        int max=*max_element(v.begin(),v.end());
        vector<int> vec(max+1);
        for(int i = 0 ; i<v.size();i++){
            int n = v[i];
            vec[n]++;

        }
        int max_count=*max_element(vec.begin(),vec.end());
        for(int i = 0 ; i<vec.size();i++){
            if(vec[i]==max_count){
                count+=max_count;
            }
        }
        return count;

        
    }
};