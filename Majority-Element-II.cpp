class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {




        int ele1 = INT_MIN,ele2= INT_MIN;
        int count1= 0,count2 = 0;
       int  n = nums.size();
        for(int i = 0; i<n;i++ ){
            if(count1==0 && ele2!=nums[i]){
                ele1=nums[i];
                count1=1;
            }
            else if (count2 == 0 && ele1!=nums[i]){
                ele2=nums[i];
                count2=1;
            }
          else  if(ele1==nums[i]){
                count1++;
            }
           else if(ele2==nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
         vector<int>vec;
        for(int i = 0; i<n; i++){
          if(nums[i]==ele1){
            count1++;
          }
          else if(nums[i]==ele2){
            count2++;
          }
        }
        int mini = int(n/3)+1;
        if(count1>=mini){
            vec.push_back(ele1);
        }
        if(count2>=mini){
             vec.push_back(ele2);
        }

         sort(vec.begin(),vec.end());
         return vec;
    }
};