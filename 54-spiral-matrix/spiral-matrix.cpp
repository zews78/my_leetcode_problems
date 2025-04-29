class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        int sr=0, er=n-1, sc=0, ec= m-1;
        vector<int> output;

        int count =0;
        while(count< m*n){
            for(int j=sc; j<=ec; j++){
                output.push_back(matrix[sr][j]);
                count++;
            }
            // cout<<count<<endl;
            sr++;
            if(count==m*n){
                return output;
            }
            for(int i=sr; i<=er; i++){
                output.push_back(matrix[i][ec]);
                count++;
            }
            // cout<<count<<endl;
            ec--;
            if(count==m*n){
                return output;
            }
            for(int j=ec; j>=sc; j--){
                output.push_back(matrix[er][j]);
                count++;
            }
            // cout<<count<<endl;
            er--;
            if(count==m*n){
                return output;
            }
            for(int i=er; i>=sr; i--){
                output.push_back(matrix[i][sc]);
                count++;
            }
            // cout<<count<<endl;
            sc++;
            // if(count==m*n){
            //     return output;
            // }
            // cout<<count<<endl;
        }
        return output;

        
    }
};