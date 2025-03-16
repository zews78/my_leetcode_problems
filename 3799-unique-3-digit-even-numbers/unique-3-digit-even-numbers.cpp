class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n= digits.size();
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i!=j && j!=k && i!=k){
                        int ones = digits[k];
                        int tens = digits[j];
                        int hundreds = digits[i];
                        int number=ones+10*tens+100*hundreds;
                        if(number%2==0 && number>=100){
                            s.insert(number);
                        }
                    }
                }
            }
        }
        return s.size();

    }
};