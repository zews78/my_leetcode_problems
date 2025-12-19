class Solution {
public:
    vector<long long> seperateByComma(string str){
        int n = str.size();
        vector<long long> res;
        long long temp = 0;

        for(int i=0; i<n; i++){
            if(str[i]=='.'){
                res.push_back(temp);

                temp = 0;
                continue;
            }
            temp = (long long)temp*10 + str[i]-'0';

        }
        res.push_back(temp);

        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<long long> ver1_arr = seperateByComma(version1);
        vector<long long> ver2_arr = seperateByComma(version2);

        int res =0;
        int n = ver1_arr.size();
        int m = ver2_arr.size();
        int len_diff =abs(n-m);
        while(len_diff){
            if(n<m){
                ver1_arr.push_back(0);
            }else{
                ver2_arr.push_back(0);
            }
            len_diff--;
        }


        // for(auto x: ver1_arr){
        //     cout<<x<<"-a";
        // }cout<<endl;
        // for(auto y: ver2_arr){
        //     cout<<y;
        // }

        int i=0;
        int j=0;
        while(i<ver1_arr.size()){
            if(ver1_arr[i]<ver2_arr[j]){
                return -1;
            }else if(ver1_arr[i]>ver2_arr[j]){
                return 1;
            }
            i++; j++;
        }
        // cout<<"len-";
        // cout<<i<<j<<endl;
        // if(i==n && j==m) return 0;

        // if(i==n) return -1;
        return 0;
    }
};