class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        solve(0, n, board, res);
        return res;
    }

    void solve(int i, int n, vector<string> &board, vector<vector<string>> &res){
        if(i==n){
            res.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(feasible(i, j, board)){
                board[i][j]='Q';
                solve(i+1, n, board, res);
                board[i][j]='.';
            }
        }
    }

    bool feasible(int i, int j, vector<string> &board){
        // return true;
        int n=board.size();
        int x=i;
        int y=j;
        while(x>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
        }

        x=i;
        y=j;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }

        x=i;
        y=j;
        while(x>=0 && y<n){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y++;
        }

        return true;
    }
};