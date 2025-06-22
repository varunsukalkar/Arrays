class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>stack;
        int n = temp.size();
        vector<int>ans(n,0);

        for(int  i = n-1 ; i>=0 ; i--){
            while(!stack.empty() && temp[stack.top()]<=temp[i]){
                stack.pop();
            }
            if(!stack.empty()){
                ans[i]=(stack.top()-i);
            }

            stack.push(i);
        }
        return ans ;
    }
};