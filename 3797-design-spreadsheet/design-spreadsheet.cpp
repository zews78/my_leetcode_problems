class Spreadsheet {
// private: int[][]grid;
// private: int rows;

public:
    int decypher(string cell){
        char ch = cell[0];
        if(ch >= '0' && ch <= '9') {
            int int_collect=0;
            for(int i=0; i<cell.size(); i++){
                int_collect = int_collect*10 + cell[i]-'0';
            }
            return int_collect;
        }
        int col = cell[0]-'A';
        int row=0;
        for(int i=1; i<cell.size(); i++){
            row = row*10 + cell[i]-'0';
        }
        return grid[row][col];
    }
    vector<vector<int>> grid; 
    Spreadsheet(int rows) {
        grid.resize(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int row=0;
        for(int i=1; i<cell.size(); i++){
            row = row*10 + cell[i]-'0';
        }
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int row=0;
        for(int i=1; i<cell.size(); i++){
            row = row*10 + cell[i]-'0';
        }
        grid[row][col]=0;
    }
    
    int getValue(string formula) {
        string X= "";
        string Y = "";
        int i=1;
        while(formula[i]!='+'){
            X+=formula[i];
            i++;
        }
        i++;
        while(i<formula.size()){
            Y+=formula[i];
            i++;
        }
        
        return decypher(X)+decypher(Y);
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */