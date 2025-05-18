class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      int count=0;
      int emp=0;
      while(numBottles!=0){
      count+=numBottles;
      emp+=numBottles;
      numBottles=emp/numExchange;
      emp%=numExchange;
     }
      return count;
    }
};