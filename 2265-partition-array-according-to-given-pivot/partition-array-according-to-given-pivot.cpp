class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> output(n);
        int output_lPtr =0;
        int output_rPtr =n-1;
        int i =0, j= n-1;
        while(i<n && j>=0){
            if(nums[i]<pivot){
                output[output_lPtr] = nums[i];
                output_lPtr++;
            }
            if(nums[j]>pivot){
                output[output_rPtr] = nums[j];
                output_rPtr--;
            }
            i++; j--;
        }
        while(output_lPtr<=output_rPtr){
            output[output_lPtr]=pivot;
            output_lPtr++;
        }
        return output;

    }
};