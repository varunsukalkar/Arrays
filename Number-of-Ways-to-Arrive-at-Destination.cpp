class Solution {
public:
   int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& r : roads) {
        int u = r[0], v = r[1], w = r[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    const int MOD = 1e9 + 7;
    using ll = long long;
    using pli = pair<ll, int>;

    vector<ll> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[0] = 0;
    ways[0] = 1;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                ways[v] = ways[u];
                pq.emplace(dist[v], v);
            } else if (d + w == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }

    return ways[n - 1];
}
};