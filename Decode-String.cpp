class Solution {
public:
    string decodeString(string s) {
      stack<string>stack;
      int num=0;
      string exp="";
      for(int i = 0 ; i<s.size(); i++){
        if(isdigit(s[i])){
            num = num*10+(s[i]-'0');

        }
       else if(s[i]=='['){
            stack.push(exp);
            stack.push(to_string(num));
            exp="";
            num=0;
        }
       else if(s[i]==']'){
            string temp = exp;
            int number  = stoi(stack.top());
            stack.pop();
            string prevs = stack.top();
            stack.pop();
            exp = prevs;
            while(number--){
                exp+=temp;
            }
            

        }
        else{
            exp+=s[i];
        }

      }
      return exp;
    }
};