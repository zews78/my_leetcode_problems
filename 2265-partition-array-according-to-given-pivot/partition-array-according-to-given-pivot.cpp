class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l1;
        vector<int> r1;
        vector<int> c1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot){
                l1.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                r1.push_back(nums[i]);
            }else{
                c1.push_back(nums[i]);
            }
        }
        vector<int> output;
        for(int i=0; i<l1.size(); i++){
            output.push_back(l1[i]);
        }
        for(int i=0; i<c1.size(); i++){
            output.push_back(c1[i]);
        }
        for(int i=0; i<r1.size(); i++){
            output.push_back(r1[i]);
        }
        return output;
    }
};