class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int a = accumulate(gas.begin(),gas.end(),0);
        int b  = accumulate(cost.begin(),cost.end(),0);

int n = gas.size();
        if(b>a){
            return -1;
        }

        int startindex = 0 ;
        int sum=0;
        for(int i = 0  ; i< n; i++){
            sum+=gas[i]-cost[i];
            if(sum<0){
                sum=0;
                startindex=i+1;
            }

        }
   return startindex;

    }
};