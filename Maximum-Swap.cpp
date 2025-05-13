class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> maxright(n);


        maxright[n-1] = n-1;
        for(int i = n-2 ; i>=0; i--){
            int maxindex = maxright[i+1];
            int maxelement = s[maxindex];
            if(s[i]>maxelement){
              maxright[i]=i;
            }
            else{
                maxright[i]=maxindex;
            }
        }
        for(int i =0 ; i<n ; i++){
            int maxrightid = maxright[i];
            int maxrightelement = s[maxrightid];
            if(s[i]<maxrightelement){
                swap(s[i],s[maxrightid]);
                   return stoi(s);
                
            }




        }
        return num;
    }
};