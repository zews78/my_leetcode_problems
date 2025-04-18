class Solution {
public:
    string solve(int n, string &output){
        if(n==1){
            return output;
        }
        int count =1;
        string temp ="";
        int i=0;
        // for(auto x: output){
        //     cout<<x;
        // }cout<<" ";
        for(; i<output.size()-1; i++){
            if(output[i]==output[i+1]){
                count++;
            }else{
                temp+=to_string(count);
                temp+=output[i];
                count =1;
            }
        }
        temp+=to_string(count);
        temp+=output[i];
        // cout<<temp<<" ";
        return solve(n-1, temp);
    }
    string countAndSay(int n) {
        string output ="1";
        return solve(n, output);

    }
};