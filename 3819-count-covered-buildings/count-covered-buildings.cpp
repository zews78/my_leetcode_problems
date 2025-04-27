class Solution {
    bool checkValidInd(int val, vector<int>& arr){
        int n = arr.size();
        int val_ind = -1;
        int s =0; 
        int e = arr.size()-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==val){
                val_ind = mid;
                break;
            }
            else if(arr[mid]> val){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        if(val_ind == 0 || val_ind ==n-1){
            return false;
        }else{
            return true;
        }
    }
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        vector<vector<int>> building_x(n+1);
        vector<vector<int>> building_y(n+1);

        for(int i=0; i<buildings.size(); i++){
            int u = buildings[i][0];
            int v = buildings[i][1];
            building_x[u].push_back(v);
            building_y[v].push_back(u);
        }
        for(auto &x: building_x){
            sort(x.begin(), x.end());
        }
        for(auto &y: building_y){
            sort(y.begin(), y.end());
        }

        // for(auto x: building_x){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }cout<<endl;
        // }
        // for(auto x: building_y){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }cout<<endl;
        // }
        int result=0;
        for(int i=0; i<buildings.size(); i++){
            int u = buildings[i][0];
            int v = buildings[i][1];
            
            if(checkValidInd(v, building_x[u]) && checkValidInd(u, building_y[v])){
                result++;
            }
        }
        return result;

    }
};