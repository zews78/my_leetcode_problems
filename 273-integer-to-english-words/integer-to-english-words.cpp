class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        int rank =0;
        string output = "";
        vector<string> rankWords({"", " Thousand", " Million", " Billion"});
        while(num){
            int last_three_digits = num%1000;
            string last_three_digit_eng = constructEnglish(last_three_digits);
            if(!last_three_digits){
                output = output;
            }else{
                if(output.size()>0){
                    output = last_three_digit_eng + rankWords[rank] + " " + output;
                }else{
                    output = last_three_digit_eng + rankWords[rank] + output;
                }
            }
            // output = last_three_digit_eng + output;
            num = num/1000;
            rank++;
        }

        return output;
    }
    string constructEnglish(int num){
    unordered_map<int, string> um;
    um[1]="One"; um[2]="Two"; um[3]="Three"; um[4]="Four"; um[5]="Five";
    um[6]="Six"; um[7]="Seven"; um[8]="Eight"; um[9]="Nine"; um[10]="Ten";
    um[11]="Eleven"; um[12]="Twelve"; um[13]="Thirteen"; um[14]="Fourteen"; um[15]="Fifteen";
    um[16]="Sixteen"; um[17]="Seventeen"; um[18]="Eighteen"; um[19]="Nineteen";
    um[20]="Twenty"; um[30]="Thirty"; um[40]="Forty"; um[50]="Fifty";
    um[60]="Sixty"; um[70]="Seventy"; um[80]="Eighty"; um[90]="Ninety";

    string output = "";

    if(num == 0) return "";

    if(num >= 100){
        int hundreds = num / 100;
        output += um[hundreds] + " Hundred";
        num %= 100;
        if(num) output += " ";
    }

    if(num >= 20){
        int tens = (num / 10) * 10;
        output += um[tens];
        num %= 10;
        if(num) output += " " + um[num];
    }
    else if(num > 0){
        output += um[num];
    }

    return output;
}

};