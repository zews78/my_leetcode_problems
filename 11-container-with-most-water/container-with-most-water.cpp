class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; 
        int j= height.size()-1;
        int max_cap=0;
        while(i<j){
            int vol;
            if(height[i]<= height[j]){
                vol = (j-i)*height[i];
                i++;
            }else{
                vol = (j-i)*height[j];
                j--;
            }
            max_cap = max(max_cap, vol);
        }
        return max_cap;
    }
};