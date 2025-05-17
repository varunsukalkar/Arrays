class Solution {
public:
   
    int maxWeightVal = -1;
    unordered_map<string, bool> dp;

    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int, int>>> graph(n);

       
        for (auto& e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
        }

        for (int i = 0; i < n; ++i) {
            find(graph, k, t, 0, i);
        }

        return maxWeightVal;
    }

private:
    void find(vector<vector<pair<int, int>>>& graph, int k, int t, int sum, int x) {
        if (k <= 0) {
            if (sum < t) {
                maxWeightVal = max(maxWeightVal, sum);
            }
            return;
        }

        if (sum >= t) return;

        string key = to_string(k) + "#" + to_string(sum) + "#" + to_string(x);
        if (dp.count(key)) return;

        for (auto& node : graph[x]) {
            find(graph, k - 1, t, sum + node.second, node.first);
        }

        dp[key] = true;
    }

};