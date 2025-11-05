class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int st=0;
        int end=n-1;
        int max_lh = height[st];
        int max_rh = height[end];

        int water_cap =0;

        while(st<=end){
            if(max_lh<=max_rh){
                int lh = height[st];
                if(lh<=max_lh){
                    water_cap += max_lh-lh;
                }else{
                    max_lh = max(max_lh, lh);
                }
                st++;
            }else{
                int rh = height[end];
                if(rh<=max_rh){
                    water_cap += max_rh-rh;
                }else{
                    max_rh = max(max_rh, rh);
                }
                end--;
            }
        }
        return water_cap;
    }
};