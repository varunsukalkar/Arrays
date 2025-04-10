class Solution {
public:
    int maxArea(vector<int>& a) {
     int profit ;
     int start = 0 ;
     int end = a.size()-1;
     int height;
     int answer = -1;
     int width;

     while(start<end){
        width= end-start;
        height= min(a[start],a[end]);
        if(a[start]<=a[end]){
            profit=width*height;
            start++;
        }
        else{
            profit = width * height;
            end--;
        }
        answer=max(answer,profit);
     }
     return answer;
    }
};