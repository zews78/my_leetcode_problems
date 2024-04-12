class Solution {
public:
    int trap(vector<int>& height) {
        int i=0, j=height.size()-1;
        int lmax=height[0], rmax=height[j];
        int volume=0;
        while(i<j){
            if(height[i]<height[j]){
                if(height[i]>lmax){
                    lmax = height[i];
                }
                else{
                    volume+= lmax-height[i];
                }
                i++;
            }
            else{
                if(height[j]>rmax){
                    rmax= height[j];
                }
                else{
                    volume += rmax-height[j];
                }
                j--;
            }
        }
        return volume;
    }
};