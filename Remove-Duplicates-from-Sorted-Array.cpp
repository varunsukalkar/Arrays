class Solution {
public:
    int removeDuplicates(vector<int>& arr) {

      int j = 0;
      for(int i = 0 ; i< arr.size(); i++){
                if(arr[j]!=arr[i]){
                    arr[j+1]=arr[i];
                    j++;
                }
      }
  return j+1;



    }
};