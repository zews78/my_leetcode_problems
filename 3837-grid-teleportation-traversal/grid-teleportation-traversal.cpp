class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<pair<int, int>>> portal(26);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char ch = matrix[i][j];
                if(ch >= 'A' && ch <= 'Z'){
                    portal[ch - 'A'].emplace_back(i, j);
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<bool> usedPortal(26, false);

        // Min-heap: {cost, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0); // cost, row, col

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || matrix[x][y] == '#')
                continue;

            if (x == n - 1 && y == m - 1)
                return cost;

            visited[x][y] = true;

            // Check portals
            char ch = matrix[x][y];
            if (ch >= 'A' && ch <= 'Z') {
                int idx = ch - 'A';
                if (!usedPortal[idx]) {
                    usedPortal[idx] = true;
                    for (auto& [nx, ny] : portal[idx]) {
                        if (!visited[nx][ny]) {
                            pq.emplace(cost, nx, ny); // teleport: same cost
                        }
                    }
                }
            }

            // Check 4 directions
            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                    pq.emplace(cost + 1, nx, ny);
                }
            }
        }

        return -1; // if unreachable
    }
};
