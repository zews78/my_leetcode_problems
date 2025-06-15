class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                char val = board[i][j];
                if(val!='.'){
                    if(row[i].count(val) || col[j].count(val) || box[3*(i/3) + j/3].count(val)){
                        return false;
                    }else{
                        row[i].insert(val);
                        col[j].insert(val);
                        box[3*(i/3) + j/3].insert(val);                        
                    }
                }
            }
        }
        return true;
    }
};