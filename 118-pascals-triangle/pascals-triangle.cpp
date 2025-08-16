class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        output.push_back({1});
        for(int i=0; i<numRows-1; i++){
            vector<int> temp;
            int lastIndex = output.size()-1;
            cout<<lastIndex<<"-"<<output[lastIndex].size()<<endl;
            temp.push_back(1);
            for(int j=1; j<output[lastIndex].size(); j++){
                int last_sum = output[lastIndex][j]+output[lastIndex][j-1];
                cout<<last_sum<<" ";
                temp.push_back(last_sum);
            }
            temp.push_back(1);
            output.push_back(temp);
            temp = {};
        }

        return output;
    }
};