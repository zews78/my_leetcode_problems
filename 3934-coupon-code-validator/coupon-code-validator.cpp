class Solution {
public:
    vector<string> businesses;

    Solution() {
        businesses = {"electronics", "grocery", "pharmacy", "restaurant"};
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<vector<string>> output;

        for(int i=0; i<code.size(); i++){
            if(validCode(code[i]) && validBusiness(businessLine[i]) && isActive[i]){
                output.push_back({businessLine[i], code[i]});
            }
        }
        sort(output.begin(), output.end());
        vector<string> ans;
        for(auto x: output){
            ans.push_back(x[1]);
        }
        return ans;
    }
    bool validCode(string code){
        if(code.size()<1) return false;
        for(auto ch: code){
            if(!((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') || (ch=='_'))){
                return false;
            }
        }
        return true;
    }  
    bool validBusiness(string businessVal){
        for(auto x: businesses){
            if(x==businessVal){
                return true;
            }
        }
        return false;
    }
};