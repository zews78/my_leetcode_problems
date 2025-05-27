class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> output;
        vector<vector<int>> pacific(n, vector<int>(m, false));
        vector<vector<int>> atlantic(n, vector<int>(m, false));
        for(int i=0; i<n; i++){
            solve(i, 0, heights, pacific);
            solve(i, m-1, heights, atlantic);
        }
        for(int j=0; j<m; j++){
            solve(0, j, heights, pacific);
            solve(n-1, j, heights, atlantic);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    output.push_back({i, j});
                }
            }
        }

        return output;
    }

    void solve(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& visited){
        visited[i][j] = true;
        vector<vector<int>> dir({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
        for(int p=0; p<dir.size(); p++){
            int dx = dir[p][0];
            int dy = dir[p][1];
            if(i+dx<heights.size() && j+dy<heights[0].size() && i+dx>=0 && j+dy>=0 && !visited[i+dx][j+dy] && heights[i+dx][j+dy]>= heights[i][j]){
                solve(i+dx, j+dy, heights, visited);
            }
        }
    }
};