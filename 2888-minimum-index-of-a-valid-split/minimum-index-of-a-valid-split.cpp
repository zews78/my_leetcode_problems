class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dom_ele;
        int dom_ele_cnt =1;
        for(int i=0; i<nums.size(); i++){
            if(dom_ele_cnt==0){
                dom_ele = nums[i];
                dom_ele_cnt=1;
            }else if(nums[i]==dom_ele){
                dom_ele_cnt++;
            }else{
                dom_ele_cnt--;
            }
        }
        cout<<dom_ele<<endl;
        int split_ind =0;
        int count_first_dom=0;
        int i=0;
        for(; i<n-1; i++){
            if(nums[i]==dom_ele){
                count_first_dom++;
            }
            if(count_first_dom > (i+1)/2){
                split_ind= i;
                break;
            }
        }
        cout<<split_ind<<endl;
        i++;
        int count_second_dom=0;
        while(i<n){
            if(nums[i]==dom_ele){
                count_second_dom++;
            }
            i++;
        }
        cout<<count_first_dom<<" "<<count_second_dom;
        
        if(count_second_dom > (n-split_ind-1)/2){
            return split_ind;
        }
        return -1;

    }
};