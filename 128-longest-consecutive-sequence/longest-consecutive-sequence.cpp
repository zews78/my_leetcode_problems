class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x: nums){
            s.insert(x);
        }
        int max_count =0;

        for(auto x: s){
            if(s.find(x-1)==s.end()){
                int temp = x;
                int count=1;
                while(s.find(temp+1)!=s.end()){
                    temp++;
                    count++;
                }
                max_count = max(max_count, count);
            }

        }

        return max_count;
    }
};