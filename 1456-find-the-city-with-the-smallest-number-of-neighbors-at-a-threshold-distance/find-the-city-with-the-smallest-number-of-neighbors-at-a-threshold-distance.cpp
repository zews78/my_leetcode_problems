class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e8));
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for(int i = 0; i < n; i++) {
            mat[i][i] = 0;  // Correctly setting diagonal to zero
        }

        // for(int j=0; j<n; j++){
        //     for(int i=0; i<n; i++){
        //         cout<<mat[i][j]<<" ";
        //     }cout<<endl;
        // }

        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][via]+mat[via][j]);
                }
            }
        }

        int greatest_city;
        int min_count;
        
        for(int i=0; i<n; i++){
            int count =0;
            for(int j=0; j<n; j++){
                if(mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(i==0){
                min_count = count;
                greatest_city = i;
            }else{
                if(count<=min_count){
                    min_count = count;
                    greatest_city = i;
                }
            }
        }
        return greatest_city;
    }
};