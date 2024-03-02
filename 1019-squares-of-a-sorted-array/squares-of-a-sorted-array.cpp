class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        vector<int> arr(n);
        int k= n-1;
        while(i<=j && k>=0){
            int left = nums[i]*nums[i];
            int right = nums[j]*nums[j];
            if(left>=right){
                arr[k]=left;
                k--;
                i++;
            }
            else{
                arr[k]=right;
                k--;
                j--;
            }
        }
        return arr;
    }
};