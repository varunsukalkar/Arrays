class Solution {
public:
   int moore(vector<int> & nums){
    int freq=0;
    int freq_element =nums[0];
    for(int i = 0; i< nums.size(); i++){
        if(nums[i]==freq_element){
            freq++;
        }
        else{
            freq--;
        }
        if(freq ==0 ){
            freq_element = nums[i];
            freq=1;
        }

    }
       return freq_element;
   }



    int minimumIndex(vector<int>& nums) {
        int freq_element = moore(nums);
        int freq=0;
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i]==freq_element){
            
            freq++;
            }
        }
        int prefix_count = 0;
        for(int i = 0; i< nums.size()-1; i++){
             if(nums[i]==freq_element){
               prefix_count++;
            freq--;
             }


             if((prefix_count>(i+1)/2 and (freq > (nums.size()-i-1)/2)))
             return i;
        }
        return -1;
    }
};