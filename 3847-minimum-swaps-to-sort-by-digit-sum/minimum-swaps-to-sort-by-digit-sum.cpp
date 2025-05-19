class Solution {
public:
    int digitSum(int val){
        int sum=0;
        while(val){
            sum += val%10;
            val = val/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> um;
        for(int i=0; i<n; i++){
            um[nums[i]] = i;
        }
        
        sort(nums.begin(), nums.end(), [&](int i, int j){
            int a = digitSum(i);
            int b = digitSum(j);
            if(a==b){
                return (i<j);
            }
            return a<b;
        });

        // for(int i=0; i<n; i++){
        //     cout<<nums[i]<<","<<um[nums[i]]<<","<<digitSum(nums[i])<<" ";
        // }

        vector<bool> visited(n);
        int cnt =0;
        for(int i=0; i<n; i++){
            if(visited[i] || um[nums[i]]==i) continue;
            
            int k =i;
            int cycle =0;
            while(!visited[k]){
                visited[k] = true;
                k = um[nums[k]];
                cycle++;
            }
            if(cycle > 1){
                cnt += cycle-1;
            }
        }
        return cnt;
    }
};