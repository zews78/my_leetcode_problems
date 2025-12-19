class Solution {
public:
    string solve(int i, int n, string &temp){
        if(i==n-1){
            return temp;
        }

        //cal temp
        string curr_temp = "";
        int freq_count=1;
        for(int k=0; k<temp.size(); k++){
            if(k<temp.size()-1 && temp[k]==temp[k+1]){
                freq_count+=1;
            }else{
                curr_temp+=freq_count+'0';
                curr_temp+=temp[k];
                
                freq_count=1;
            }
        }
        // cout<<curr_temp<<endl;
        

        return solve(i+1, n, curr_temp);

    }
    string countAndSay(int n) {
        string temp = "1";
        return solve(0, n, temp);
        return temp;
    }
};