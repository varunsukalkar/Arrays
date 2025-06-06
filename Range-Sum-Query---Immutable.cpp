class NumArray {
public:
vector<int>arr;
vector<int>prefix;
    NumArray(vector<int>& nums) {
        arr= nums;
        prefix.resize(nums.size());
        prefixsum(prefix);
    }
    
    void prefixsum(vector<int>&prefix){
        prefix[0]=arr[0];
        for(int i = 1 ; i< prefix.size(); i++){
            prefix[i]=arr[i]+prefix[i-1];
        }
    }

    int sumRange(int left, int right) {
        if(left==0){
            return prefix[right];
        }
        else{
            return prefix[right]-prefix[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */