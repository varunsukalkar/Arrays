class Solution {
public:
    int maxOperations(string s) {
           int operations = 0;
    int n = s.length();
    
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            ++operations;
          
            int j = i;
            while (j < n - 1 && s[j + 1] == '0') {
                swap(s[j], s[j + 1]);
                ++j;
            }
            i = j; 
            ++operations;
        }
    }
    
    return operations;
    }
};