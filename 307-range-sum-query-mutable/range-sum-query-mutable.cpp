class NumArray {
public:
    vector<int> sumArr, arr;
    int n;
    NumArray(vector<int>& nums) {
        int sum=0;
        arr=nums;
        n = nums.size();
        for(auto x: nums){
            sumArr.push_back(sum);
            sum+=x;
        }
        sumArr.push_back(sum);
        // for(auto x: sumArr){
        //     cout<<x<<" ";
        // }cout<<endl;
    }
    
    void update(int index, int val) {
        int num_val = val-arr[index];
        arr[index] =val;
        int i = index+1;
        while(i<=n){
            sumArr[i] += num_val;
            i++;
        }
    }
    
    int sumRange(int left, int right) {
        return sumArr[right+1]-sumArr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */