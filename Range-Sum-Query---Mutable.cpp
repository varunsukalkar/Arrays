class NumArray {
public:
vector<int>segmenttree;
    int n;
      void buildsegmnettree(int i , int l , int r , vector<int> & nums){
        if(l==r){
            segmenttree[i]=nums[l];
            return; 
     }
             int mid = (l+r)/2;
             buildsegmnettree(2*i+1,l,mid,nums);
             buildsegmnettree(2*i+2 , mid+1,r,nums);

             segmenttree[i] = segmenttree[2*i + 1] + segmenttree[2*i + 2];
    }

     void update_segement_tree(int index , int val , int i , int l , int r){
        if(l==r){
            segmenttree[i]=val;
return ;
        }
        int mid=l+(r-l)/2;
        if(index<=mid){
         update_segement_tree(index , val, 2*i+1 , l,mid);
        }else{
update_segement_tree(index, val , 2*i+2, mid+1,r);


        }
        segmenttree[i]=segmenttree[2*i+1]+segmenttree[2*i+2];
     }

    int query_segment_tree(int left , int right , int i , int l, int r){
   
        if(l>right || r<left){
            return 0;

        }
        if(l>=left && r<=right){
            return segmenttree[i];
        }
        int mid = l+(r-l)/2;
        return query_segment_tree(left,right,2*i+1,l,mid)+
        query_segment_tree(left,right,2*i+2,mid+1,r);

    }












    NumArray(vector<int>& nums) {
     n = nums.size();
        segmenttree.resize(4*n);
        buildsegmnettree(0,0,n-1,nums);
    }

    
    void update(int index, int val) {
        update_segement_tree(index , val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query_segment_tree(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */