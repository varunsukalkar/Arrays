class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
         
    vector<unordered_map<int, int>> player_picks(n);
    
   
    for (const auto& p : pick) {
        int player = p[0];
        int color = p[1];
        player_picks[player][color]++;
    }
    
  
    int winning_count = 0;
    for (int i = 0; i < n; ++i) {
       
        for (const auto& entry : player_picks[i]) {
            if (entry.second > i) {
                winning_count++;
                break;  
            }
        }
    }
    
    return winning_count;
    }
};