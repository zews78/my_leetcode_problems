class Solution {
public:
    char to_lowerCase(char ch){
        if(ch>= 'A' && ch<='Z'){
            return ch+32;
        }
        return ch;
    }
    char to_upperCase(char ch){
        if(ch>= 'a' && ch<='z'){
            return ch-32;
        }
        return ch;
    }
    string generateTag(string caption) {
        int n = caption.size();
        int max_limit = 100;
        string output = "#";
        vector<string> arr;
        string temp = "";
        for(int i=0; i<n; i++){
            if(caption[i]==' '){
                if(temp.size()>0){
                    arr.push_back(temp);
                }
                temp= "";
            }else{
                temp+=caption[i];
            }
        }
        if(temp.size()>0){
            arr.push_back(temp);
        }

        for(int i=0; i<arr.size(); i++){
            string temper = "";
            if(i==0){
                for(int j=0; j<arr[i].size(); j++){
                    temper+= to_lowerCase(arr[i][j]);
                }
            }else{
                for(int j=0; j<arr[i].size(); j++){
                    if(j==0){
                        temper+= to_upperCase(arr[i][j]);
                        continue;
                    }
                    temper+= to_lowerCase(arr[i][j]);
                }
            }
            output+= temper;
        }
        string output2 = "#";

        for(int i=1; i<output.size() && i<max_limit; i++){
            char ch = output[i];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                output2 += ch;
            }else{
                max_limit++;
            }
        }

        return output2;
    }
};