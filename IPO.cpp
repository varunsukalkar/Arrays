class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        typedef pair<int,int>p;
        priority_queue<p,vector<p>,greater<p>>price;
        priority_queue<int>profit;
         int finalprofit = 0;
         int n = profits.size();
         for(int i = 0 ; i< n; i++){
            price.push({capital[i],profits[i]});

         }
       while(k--){
       while (!price.empty() && price.top().first <= w){
            int s = price.top().first;
            int p = price.top().second;
            price.pop();
            profit.push({p});
        }
          if (profit.empty()) break;
      
       finalprofit +=  profit.top();
        w=w+profit.top();
       profit.pop();
        
      
       }
       return w;
    }
};