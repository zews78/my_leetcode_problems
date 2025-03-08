class Solution {
public:
    bool checkVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowel_count=0;
        int i=0;
        int j=0;
        for(; j<k; j++){
            if(checkVowel(s[j])){
                vowel_count++;
            }
        }
        int max_vowel_count=vowel_count;
        // cout<<vowel_count<<endl;

        while(j<n){
            if(checkVowel(s[j])){
                vowel_count++;
            }
            if(checkVowel(s[i])){
                vowel_count--;
            }
            // cout<<i<<j<<vowel_count<<max_vowel_count<<" ";
            max_vowel_count = max(vowel_count, max_vowel_count);
            i++;
            j++;
        }
        return max_vowel_count;
    }
};