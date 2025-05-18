class Solution {
public:
    int reversePairs(vector<int>& nums) {
       return  mergesort(nums,0,nums.size()-1);
    }
    int countpair(vector<int>& arr ,int low , int mid, int high){
        int cnt = 0;
        int right = mid+1;
        for(int i = low ; i<= mid ; i++){
            while(right<=high && arr[i]>(long long )2*arr[right]){
               right++;
            }
            cnt+=right-(mid+1);
        }
        return cnt;
    }
    int mergesort(vector<int>& arr , int low ,int high){
        int mid = (low+high)/2;
        int cnt = 0 ;
        if(low>=high)return cnt;
       cnt+= mergesort(arr,low ,mid );
       cnt+=mergesort(arr, mid+1 , high);
       cnt+= countpair(arr,low, mid ,high);
       merge(arr, low , mid, high);
       return cnt;

    }
    void merge(vector<int> & arr , int low , int mid , int high ){
      vector<int>temp;
      int left = low ; 
      int right = mid+1;
      int cnt = 0;
      while(left <= mid  && right <=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }

      
      }
      while(left<=mid){
        temp.push_back(arr[left]);
        left++;
      }
      while(right<=high){
        temp.push_back(arr[right]);
        right++;
      }
      for(int i = low ; i<=high ; i++){
        arr[i] = temp[i-low];
      }
    }
};