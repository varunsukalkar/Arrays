class Solution {
public:
    int lengthAfterTransformations(string s, int t) {

        const int M = 1e9 + 7;
        vector<long long> vec(26, 0);

        // Initialize the vector with the count of each character
        for (int i = 0; i < s.size(); i++) {
            vec[s[i] - 'a']++;
        }

        // Perform transformations
        while (t--) {
            vector<long long> newVec(26, 0);

            for (int i = 0; i < 26; i++) {
                if (i == 25) { // If 'z'
                    newVec[0] = (newVec[0] + vec[i]) % M; // 'z' becomes 'a'
                    newVec[1] = (newVec[1] + vec[i]) % M; // 'z' becomes 'b'
                } else { // Any other character
                    newVec[i + 1] = (newVec[i + 1] + vec[i]) % M; // Increment character
                }
            }

            vec = newVec; // Update vec to the transformed vector
        }

        // Calculate the total count of characters
        long long count = 0;
        for (int i = 0; i < 26; i++) {
            count = (count + vec[i]) % M;
        }

        return count;
    }
};

