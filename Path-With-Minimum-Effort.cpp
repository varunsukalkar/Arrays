class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const unsigned int M = 1000000007;
     int evencount = 1;
     long long  int sum = 0;
     int oddcount = 0;
     int ans = 0 ;
     for(int i = 0; i<arr.size(); i++){
         sum+=arr[i];
        
         if(sum%2==1){
            //odd hai 
             ans+=evencount;
             ans=ans%M;
             oddcount++;
         }
         else{
            ans+=oddcount;
            ans=ans%M;
            evencount++;
         }
     }
     return ans ;

    }
};