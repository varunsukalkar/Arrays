class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        map<int,int>m;
        for(int i =n-1 ; i>=0; i-- ){
              if(st.empty()){
               m[nums2[i]]=-1;
               st.push(nums2[i]);
              }
              else if(st.top()<nums2[i]){
                while(!(st.empty()) && st.top()<nums2[i]){
                    
                        st.pop();
                    }

                
                if(st.empty()){
                    m[nums2[i]]=-1;
                    st.push(nums2[i]);
                }
                else{
                   m[nums2[i]]= st.top();
                   st.push(nums2[i]);
                }
              }
              else{
                m[nums2[i]]=st.top();
                st.push(nums2[i]);
              }
        }
        vector<int>vec(nums1.size());
        for(int i = 0 ; i<nums1.size(); i++){
            vec[i]=m[nums1[i]];
        }
        return vec;
    }

    
};