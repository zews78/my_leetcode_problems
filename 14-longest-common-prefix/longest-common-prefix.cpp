class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size_of_arr = strs.size();
        int length_of_first_ele = strs[0].size();
        string output = "";
        for(int ind=0; ind<length_of_first_ele; ind++){
            char letter = strs[0][ind];
            int ele;
            for(ele=0; ele< size_of_arr; ele++){
                if(strs[ele][ind]!=letter){
                    break;
                }
            }
            if(ele == size_of_arr) output+=letter;
            else return output;
        }
        return output;
    }
};