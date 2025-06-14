class Solution {
public:

   int MAXWIDTH;
    
    string find_line(int i , int j , int eachgaddhespace, int extraspacegaddhe , vector<string>&words){
        string line ;
        for(int k = i ; k<j; k++){
            line+=words[k];
            if(k==j-1){
                continue;
            }
            for(int z = 1; z<=eachgaddhespace; z++){
                line+=\ \;
            }
            if(extraspacegaddhe >0){
                line+=\ \;
                extraspacegaddhe--;
            }

        }
        while(line.length()<MAXWIDTH){
            line+=\ \;

        }
        return line;
    }









    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        MAXWIDTH = maxWidth;
        vector<string>ans;
        int n= words.size();
        int i = 0 ; 
        while(i<n){
            int lengthcount = words[i].length();
             int  j = i+1;
             int gaddhe = 0 ; 
             while( j < n && lengthcount+words[j].length()+1+gaddhe<=maxWidth ){
                lengthcount+=words[j].size();
            
                  gaddhe+=1;
                        j++;
             }
             int remaininggaddhe = maxWidth-lengthcount;
             int eachgaddhespace = gaddhe==0?0:remaininggaddhe/gaddhe;
             int extraspacegaddhe  = gaddhe==0?0:remaininggaddhe % gaddhe;
             if(j==n){
              eachgaddhespace = 1;
              extraspacegaddhe=0;

             }
             ans.push_back(
                find_line(i,j,eachgaddhespace,extraspacegaddhe,words)
             );
             i = j;
        }
        return ans;
    }
};