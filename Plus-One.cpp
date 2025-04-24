class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      int idx= n-1;
      while(idx>=0){
        if(digits[idx]==9){
            digits[idx]=0;
            idx--;

        }
        else{
            digits[idx]+=1;
            return digits;
        }


      }
      digits.insert(digits.begin(),1);
      return digits;
    }
};