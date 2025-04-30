class Solution {
public:
    int majority_ele(unordered_map<char, int> &um){
        int maxx = 0;
        for(auto x: um){
            maxx = max(maxx, x.second);
        }
        return maxx;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0;
        int j=0;
        int max_output=0;
        
        unordered_map<char, int> um;


        while(j<n){
            um[s[j]]++;

            while((j-i+1)-majority_ele(um)>k){
                um[s[i]]--;
                if(um[s[i]]==0){
                    um.erase(s[i]);
                }
                i++;
            }
            max_output= max(max_output, j-i+1);

            j++;
        }
        return max_output;
    }
};