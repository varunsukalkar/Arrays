class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
            int count = 0;
        for (int num = low; num <= high; ++num) {
            string s = to_string(num);
            if (s.size() % 2 == 0) {
                int mid = s.size() / 2;
                int leftSum = 0, rightSum = 0;
                for (int i = 0; i < mid; ++i) leftSum += s[i] - '0';
                for (int i = mid; i < s.size(); ++i) rightSum += s[i] - '0';
                if (leftSum == rightSum) count++;
            }
        }
        return count;
    
    }
};