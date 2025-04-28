class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n= matrix.size();
        int m = matrix[0].size();

        vector<bool> zero_cols(m, false);
        vector<int> zero_rows(n, false);

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(matrix[i][j]==0){
                    zero_cols[j]=true;
                    zero_rows[i]= true;
                }
            }
        }
        // sort(zero_rows.begin(), zero_rows.end());

        // for(auto x: zero_cols){
        //     cout<<x<<" ";
        // }cout<<endl;
        // for(auto x: zero_rows){
        //     cout<<x<<" ";
        // }
        
        // int ind_col =0;
        for(int j=0; j<m; j++){
            if(zero_cols[j]){
                for(int i=0; i<n; i++){
                    matrix[i][j]=0;
                }
            }
        }
        
        // int ind_row= 0;
        for(int i=0; i<n; i++){
            if(zero_rows[i]){
                for(int j=0; j<m; j++){
                    matrix[i][j] = 0;
                }
                // ind_row++;
            }
        }
    }
};