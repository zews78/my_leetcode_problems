class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //toggle rows to maximise the leading one
        for(int i=0; i<n; i++){
            int val_normal=0;
            int val_swap=0;
            for(int j=0; j<m; j++){
                // val_normal = val_normal*10 + grid[i][j];
                val_normal <<= 1;
                val_normal += grid[i][j];
                if(grid[i][j]){
                    val_swap <<= 1;
                    val_swap += 0;
                }
                else{
                    val_swap <<= 1;
                    val_swap += 1;
                }
            }
            // cout<<val_normal<<" "<<val_swap<<endl;
            if(val_normal<val_swap){
                //swap the row
                for(int j=0; j<m; j++){
                    if(grid[i][j]){
                        grid[i][j]=0;
                    }else{
                        grid[i][j]=1;
                    }
                }
            }
        }
        // toggle cols to max count of ones overall

        for(int j=0; j<m; j++){
            int count_normal=0;
            int count_swap=0;
            for(int i=0; i<n; i++){
                if(grid[i][j]){
                    count_normal++;
                }else{
                    count_swap++;
                }
            }
            // cout<<count_normal<<" "<<count_swap<<endl;
            if(count_normal< count_swap){
                for(int i=0; i<n; i++){
                    if(grid[i][j]){
                        grid[i][j]=0;
                    }else{
                        grid[i][j]=1;
                    }
                }
            }
        }

        int result_val=0;
        for(int i=0; i<n; i++){
            int decimal_val = 0;
            for(int j=0; j<m; j++){
                decimal_val <<= 1;
                decimal_val += grid[i][j];
                // cout<<grid[i][j]<<" ";
            }
            result_val+=decimal_val;
            // cout<<endl;
        }
        return result_val;
    }
};