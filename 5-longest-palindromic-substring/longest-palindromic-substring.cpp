class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        pair<int, int> output_ind;
        int max_palindromic=0;
        for(int k=0; k<n; k++){
            int i=k, j=k;
            while(i>=0 && j<n && s[i]==s[j]){
                if(max_palindromic<(j-i+1)){
                    max_palindromic = j-i+1;
                    output_ind.first = i;
                    output_ind.second =j;
                }
                i--; j++;
            }

            i=k, j=k+1;
            while(i>=0 && j<n && s[i]==s[j]){
                if(max_palindromic<(j-i+1)){
                    max_palindromic = j-i+1;
                    output_ind.first = i;
                    output_ind.second =j;
                }
                i--; j++;
            }

        }
        // cout<<output_ind.first<<output_ind.second;
        string output_ans ="";
        for(int k=output_ind.first; k<=output_ind.second; k++){
            output_ans+=s[k];
        }

        return output_ans;
    }
};