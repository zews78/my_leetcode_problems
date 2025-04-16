class Solution {
public:
    // int checkPairs(unordered_map<int, int>& freqMap){
    //     int count_pairs=0;
    //     for(auto x: freqMap){
    //         int freq = x.second;
    //         count_pairs += (freq * (freq-1))/2;
    //     }
    //     return count_pairs;
    // }
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int n = nums.size();
        int i=0, j=0;
        long long count =0;
        int count_pairs =0;
        while(j<n){
            int prev_freq= freqMap[nums[j]];
            freqMap[nums[j]]++;
            count_pairs += prev_freq;
            //shrink

            while(count_pairs>=k){
                count+=(n-j-1);
                count_pairs -= (freqMap[nums[i]] * (freqMap[nums[i]]-1))/2;
                freqMap[nums[i]]--;
                if(freqMap[nums[i]]==0){
                    freqMap.erase(nums[i]);
                }
                count_pairs += (freqMap[nums[i]] * (freqMap[nums[i]]-1))/2;

                count++;
                i++;
            }
            j++;
        }
        return count;




    }
};