class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            // Sort by frequency (higher first) and then by value (higher first)
            if (a.second != b.second) {
                return a.second < b.second; // Max-heap based on frequency
            }
            return a.first < b.first; // Max-heap based on value
        }
    };
    vector<int> findXSum(vector<int>& nums, int k, int x) {
             int n = nums.size();
        vector<int> ans;

        for (int left = 0; left <= n - k; left++) {
            unordered_map<int, int> frequencyMap;
            priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

            // Count frequency of elements in the current subarray
            for (int i = left; i < left + k; i++) {
                frequencyMap[nums[i]]++;
            }

            // Insert elements and their frequencies into the priority queue
            for (const auto& entry : frequencyMap) {
                pq.push(entry); 
            }

            int xsum = 0;
            // Calculate the x-sum using the top x frequent elements
            for (int temp = 0; temp < x && !pq.empty(); temp++) {
                auto pair = pq.top();
                xsum += pair.first * pair.second;
                pq.pop();
            }

            ans.push_back(xsum);
        }

        return ans;
    }



    

};