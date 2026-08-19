class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        vector<bool> col_vis(n, false);
        vector<bool> d1_vis(2*n-1, false);
        vector<bool> d2_vis(2*n-1, false);

        solve(0, 0, n, col_vis, d1_vis, d2_vis, res, board);

        return res;

    }

    void solve(int i, int j, int n, vector<bool> &col_vis, vector<bool> &d1_vis, vector<bool> &d2_vis, vector<vector<string>> &res, vector<string> &board){
        if(i==n){
            res.push_back(board);
        }

        for(int j=0; j<n; j++){
            if(col_vis[j] || d1_vis[i+j] || d2_vis[(n-1)+i-j]){
                continue;
            }
            board[i][j]='Q';
            col_vis[j]=true;
            d1_vis[i+j]=true;
            d2_vis[(n-1)+i-j]=true;
            solve(i+1, j, n, col_vis, d1_vis, d2_vis, res, board);
            board[i][j]='.';
            col_vis[j]=false;
            d1_vis[i+j]=false;
            d2_vis[(n-1)+i-j]=false;
        }
    }

    // bool checkFeasible(int i, int col, int n, vector<string> &board){
    //     for(int i=0; i<col; i++){

    //     }
    // }


};