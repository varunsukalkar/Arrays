class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>queue;
        for(int  i = 0 ; i< matrix.size(); i++){
            for(int j  = 0 ; j< matrix[0].size(); j++){
                queue.push(matrix[i][j]);
                if(queue.size()>k){
                    queue.pop();
                }
            }
        }
        return queue.top();
    }
};