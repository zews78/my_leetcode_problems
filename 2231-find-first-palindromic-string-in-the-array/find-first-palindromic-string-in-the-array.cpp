class Solution {
public:
    bool checkPalindrome(string word){
        int i=0, j=word.size()-1;
        while(i<=j){
            if(word[i]==word[j]){
                i++;j--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            if(checkPalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};