class Solution {
public:

      

    void permut(vector<int> arr , vector<vector<int>>&ans,vector<int>  & temp,
\tvector<bool>&visited){
\tif(arr.size()==temp.size()){
\t\t// for(int i = 0; i< temp.size(); i++){
\t\t// \tcout<<temp[i]<<\ \;
\t\t// }
\t\t// cout<<endl;
        ans.push_back(temp);
\treturn ;\t
\t}
\tfor(int i = 0; i< arr.size(); i++){
\t\tif(visited[i]==0){
\t\t\tvisited[i]=1;
\t\t\ttemp.push_back(arr[i]);
\t\t\tpermut(arr,ans,temp,visited);
\t\t\tvisited[i]=0;
\t\t\ttemp.pop_back();
\t\t}
\t}
}








    vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> ans;
          vector<int>temp;
          vector<bool>visited(nums.size(),0);
          permut(nums,ans,temp,visited);
          return ans;

    }
};