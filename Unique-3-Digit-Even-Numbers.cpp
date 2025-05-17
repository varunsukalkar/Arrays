class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int lastcolor = colors[0];
        int altcolor = 1;
        int altgroup = 0;
        for(int i = 0; i< k-1 ; i++){
            colors.push_back(colors[i]);
        }
        for(int i = 1;i<colors.size(); i++){
            if(colors[i]!=lastcolor){
                altcolor++;
            }
            else{
                altcolor=1;
            }
            if(altcolor >= k){
                altgroup++;
          

            }
            lastcolor = colors[i];

        }
        return altgroup;
    }
};