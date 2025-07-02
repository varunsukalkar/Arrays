class Solution {
public:

  void solve(int index , string & digits,string & temp,unordered_map<char,string>& map,vector<string> & result ){
         if(index>=digits.size()){
            result.push_back(temp);
         }

         char ch = digits[index];
         string str = map[ch];

         for(int  i = 0; i< str.length();i++){
                temp.push_back(str[i]);
                solve(index+1,digits,temp,map,result);
                temp.pop_back();
         }
    
   }
    vector<string> letterCombinations(string digits) {
 
  if(digits.length()==0){
    return {};
  }
     int index=0;
  unordered_map<char, string> map1;
    map1['2'] = "abc";
    map1['3'] = "def";
    map1['4'] = "ghi";
    map1['5'] = "jkl";
    map1['6'] = "mno";
    map1['7'] = "pqrs";
    map1['8'] = "tuv";
    map1['9'] = "wxyz";
  
vector<string>result;
    string temp ="";
    solve(0,digits,temp,map1,result);
    return result;
    }
};