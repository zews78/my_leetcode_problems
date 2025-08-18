class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output(numRows);
        for(int i=0; i<numRows; i++){
            output[i].resize(i+1);
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    output[i][j] = 1;
                }else{
                    output[i][j] = output[i-1][j] + output[i-1][j-1];
                }
            }
        }
        return output;
    }
};