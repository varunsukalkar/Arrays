class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end());
        int count=0;
        while(k-- ){
            int b = pq.top();
           int a =floor(pq.top()/2);
           pq.pop();
           pq.push(b-a);
           

        }
        while(!pq.empty()){
            count+=pq.top();
            pq.pop();
        }
        return count;
          


    }
};