class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int l = 0;
        int r = n-1;
        int mid = 0;
        while(mid<=r){
            switch(nums[mid]){
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[r]);
                    r--;
                    break;
                case 0:
                    swap(nums[mid], nums[l]);
                    l++;
                    mid++;
                    break;
            }
        }
    }
};