class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n/3;
        unordered_set<int> set;

        int i;
        if(n%3!=0){
            for(i=n-1; i>=(n-(n%3)); i--){
                set.insert(nums[i]);
            }
            if(set.size()!=(n%3)){
                return ans+1;
            }
        }else{
            i=n-1;
        }

        while(i>=2){
            int j=i;
            while(j>=i-2){
                set.insert(nums[j]);
                j--;
            }
            // cout<<i<<" ";
            cout<<ans<<" ";
            // cout<<set.size();
            if(set.size()==(n-j-1)){
                ans--;
            }else{
                return ans;
            }
            i-=3;
        }
        return ans;



    }
};