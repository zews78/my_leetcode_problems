class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // vector<vector<stirng>> board(n, vector<string>(".", n));
        vector<vector<string>> mat;
        vector<string> board;
        string temp(n, '.');

        for(int i=0; i<n; i++){
            board.push_back(temp);
        }
        solve(0, n, board, mat);
        return mat;
    }

    void solve(int i, int n, vector<string> &board, vector<vector<string>> &mat){
        if(i==n){
            mat.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(checkPossible(i, j, board, n)){
                board[i][j] = 'Q';
                solve(i+1, n, board, mat);
                board[i][j] = '.';
            }
        }
    }

    bool checkPossible(int i, int j, vector<string> &board, int n){
        int i1 =i, j1=j;
        while(i1>=0 && j1>=0){
            if(board[i1][j1]=='Q') return false;
            i1--;j1--;
        }

        int i2=i;
        while(i2>=0){
            if(board[i2][j]=='Q') return false;
            i2--;
        }

        int i3=i, j3=j;
        while(i3>=0 && j3<n){
            if(board[i3][j3]=='Q') return false;
            i3--;j3++;
        }

        return true;
    }
    
};