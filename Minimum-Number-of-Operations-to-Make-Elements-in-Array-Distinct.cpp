class Solution {
public:
bool hasDuplicate(vector<int>& nums) {
    size_t count = nums.size();
    if (!count)
        return false;
    std::unordered_map<int, int> tbl;
    //std::set<int> tbl;
    for (size_t i = 0; i < count; i++) {
        if (tbl.find(nums[i]) != tbl.end())
            return true;
        tbl[nums[i]] = 1;
        //tbl.insert(nums[i]);
    }
    return false;
}
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        if(n<=3){
           if(hasDuplicate(nums)){
               return 1;
           }
        }
        while(hasDuplicate(nums)){
                if(nums.size()>3){
                nums.erase(nums.begin(),nums.begin() + 3);
                
                count++;
                }else{
                    if(hasDuplicate(nums)){
                        count++;
                        return count;
                    }
                }

        }
        return count;
    }
};