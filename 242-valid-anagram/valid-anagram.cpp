class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(t==s) return true;
        return false;
        // if(s.size()!=t.size()){
        //     return false;
        // }

        // vector<int> s_hash(26, 0);
        // vector<int> t_hash(26, 0);

        // for(auto x: s){
        //     s_hash[x-'a']++;
        // }

        // for(auto x: t){
        //     t_hash[x-'a']++;
        // }

        // for(int i=0; i<26; i++){
        //     if(s_hash[i]!=t_hash[i]){
        //         return false;
        //     }
        // }
        // return true;


    }
};