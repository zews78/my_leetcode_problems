class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int live_cnt=0;
                int curr_cell = board[i][j];

                for(auto dir: dirs){
                    int dx = i+dir[0];
                    int dy = j+dir[1];

                    if(dx<0 || dy<0 || dx>=n || dy>=m) continue;

                    if(board[dx][dy]==1 || board[dx][dy]==2){
                        live_cnt++;
                    }
                }

                if(curr_cell == 1){
                    if(live_cnt < 2 || live_cnt > 3){
                        board[i][j] = 2;
                    }
                }else{
                    if(live_cnt == 3){
                        board[i][j]= 3;
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }else if(board[i][j]==3){
                    board[i][j]=1;
                }
            }
        }

    }
};