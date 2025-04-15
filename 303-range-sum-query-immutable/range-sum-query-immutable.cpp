class NumArray {
public:
    vector<int> sumArr;
    NumArray(vector<int>& nums) {
        int sum =0;
        for(auto x: nums){
            sum+=x;
            sumArr.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int left_sum = (left==0)?0:sumArr[left-1];
        return sumArr[right]-left_sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */