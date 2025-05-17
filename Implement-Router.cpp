class Solution {
public:
    int minChanges(int n, int k) {
         int bitCheck=-1;
        if(n==k){
            return 0;
        }
        else{
            int xorResult = n ^ k;
   int bitCheck = xorResult & (xorResult - 1);
   return bitCheck;
        }
        
    }

};