class Solution {
public:
    bool check_symmetric(string str){
        int n = str.size();
        int i=0, e = n-1;
        int left_sum=0, right_sum=0;
        while(i<e){
            left_sum+=str[i++]-'0';
            right_sum+=str[e--]-'0';
        }
        if(left_sum==right_sum){
            return true;
        }else{
            return false;
        }
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low; i<=high; i++){
            int curr = i;
            string curr_str = to_string(curr);
            if(curr_str.size()%2==0){
                // cout<<stoi(curr_str)<<" ";
                if(check_symmetric(curr_str)){
                    // cout<<stoi(curr_str)<<"-ans";
                    ans++;
                }
            }
            else{
                i = pow(10,curr_str.size());
            }
        }
        return ans;
    }
};