class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> us;
        for(auto x: nums){
            us.insert(x);
        }

        int longest_seq = 1;
        for(auto x: us){
            if(!us.count(x-1)){//this ensures that it is the start of the sequence...
                int temp_count =1;
                x = x+1;

                while(us.count(x)){
                    temp_count++;
                    x=x+1;
                }
                longest_seq = max(longest_seq, temp_count);
            }
        }
        return longest_seq;
    }
};