class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, int ind, string word, vector<vector<bool>> &visited){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()|| word[ind]!=board[i][j] || visited[i][j]){
            return false;
        }
        if(ind==word.size()-1){
            return true;
        }

        visited[i][j] = true;
        
        bool left = dfs(i, j-1, board, ind+1, word, visited);
        if(left) return true;
        bool right = dfs(i+1, j, board, ind+1, word, visited);
        if(right) return true;
        bool up = dfs(i, j+1, board, ind+1, word, visited);
        if(up) return true;
        bool down = dfs(i-1, j, board, ind+1, word, visited);
        if(down) return true;

        visited[i][j] = false;
        return left || right || up || down;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                
                if(board[i][j]==word[0]){
                    if(dfs(i, j, board, 0, word, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};