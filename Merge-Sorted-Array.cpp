class Solution {

public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        
           int i = m-1 ;
           int j = n-1;
           int k = m+n-1;

           while(j>=0){
            if(i>=0 && v1[i]>v2[j]){
                v1[k--]=v1[i--];
            }
            else{
                v1[k--]=v2[j--];
            }
           }
       
       
    }
};