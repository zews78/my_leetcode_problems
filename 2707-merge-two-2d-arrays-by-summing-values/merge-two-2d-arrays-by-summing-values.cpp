class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0, j=0;
        int n1= nums1.size();
        int n2= nums2.size();
        vector<vector<int>> output;
        while(i<n1 && j<n2){
            if(nums1[i][0] == nums2[j][0]){
                output.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
                i++;j++;
            }
            else if(nums1[i][0] < nums2[j][0]){
                output.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }else{
                output.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while(i<n1){
            output.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while(j<n2){
            output.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return output;

    }
};