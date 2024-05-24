class Solution {
public:
    bool checkPalindrome(string &s, int i, int ind){
        int start=i, end=ind;
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    // void solve(int i, int N, string &s, vector<string> &arr, vector<vector<string>> &res){
    //     if(i==N){
    //         res.push_back(arr);
    //         return;
    //     }
        
    //     for(int ind=i; ind<N; ++ind){
    //         if(checkPalindrome(s,i,ind)){
    //             arr.push_back(s.substr(i, ind-i+1));
    //             solve(ind+1, N, s, arr, res);
    //             arr.pop_back();
                
    //         }
    //     }
    // }












    void solve(int i, int N, string &s, vector<string> &arr, vector<vector<string>> &res){
        if(i==N){
            res.push_back(arr);
            return;
        }

        for(int ind=i; ind<N; ind++){
            if(checkPalindrome(s,i,ind)){
                arr.push_back(s.substr(i, ind-i+1));
                solve(ind+1, N, s, arr, res);
                arr.pop_back();
            }
        }
    }



    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> arr;
        int N = s.size();
        solve(0,N,s, arr, res);
        return res;
    }
};