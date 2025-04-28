class Solution {
public:
   
    int hIndex(vector<int>& cit) {
      
      int n = cit.size();
        int low = 0;
    int high = n-1;
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            if(cit[mid]>=n-mid){
                ans=n-mid;
                high =mid-1;

            }else{
                  low=mid+1;
            }

        }
        return ans;
    }
};