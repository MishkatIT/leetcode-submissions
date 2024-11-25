class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> target = {1, 2, 3, 4, 5, 0};
        vector<int> start;
        int zeroPos;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start.push_back(board[i][j]);
                if (board[i][j] == 0) {
                    zeroPos = i * 3 + j;
                }
            }
        }
        
        vector<vector<int>> adj = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };
        
        queue<pair<vector<int>, int>> q; // {board state, zero position}
        map<vector<int>, int> dist;     // {board state -> steps to reach}
        q.push({start, zeroPos});
        dist[start] = 0;

        while (!q.empty()) {
            auto [current, zero] = q.front();
            q.pop();

            if (current == target) {
                return dist[current];
            }

            for (int neighbor : adj[zero]) {
                vector<int> next = current;
                swap(next[zero], next[neighbor]);
                
                if (dist.find(next) == dist.end()) {
                    dist[next] = dist[current] + 1;
                    q.push({next, neighbor});
                }
            }
        }

        return -1;
    }
};
