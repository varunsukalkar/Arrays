class Solution {
public:
   bool possible(vector<int>& h, vector<int>& heat,int mid){
  int n = h.size();
  int m = heat.size();
  int i = 0 ; 
  int j = 0;
   
  while(i<n){
    if(j==m){
        return false;
    }
    int l = heat[j]-mid;
    int r = heat[j]+mid;
    if(h[i]<l || h[i]>r){
        j++;
    }else{
        i++;
    }
  }
  return true;
   }



    int findRadius(vector<int>& h, vector<int>& heat) {
        sort(h.begin(),h.end());
        sort(heat.begin(),heat.end());
        int low =0;
        int h1 = *max_element(h.begin(),h.end() );
        int h2 = *max_element(heat.begin(),heat.end());
        int high = max(h1,h2);

        int ans =0;
        while(low<=high){
         int mid =(low+high)/2;
         if(possible(h,heat,mid)==true){
            ans=mid;
            high = mid-1;

         }
         else{
            low=mid+1;
         }
        }
        return ans;
    }
};