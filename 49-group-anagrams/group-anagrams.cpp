class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for(auto x: strs){
            string key = x;
            sort(key.begin(), key.end());
            um[key].push_back(x);
        }

        vector<vector<string>> output;

        for(auto x: um){
            output.push_back(x.second);
        }
        return output;

    }
};