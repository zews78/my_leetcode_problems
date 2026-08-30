class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        // if(n1<n2){
        //     return findMedianSortedArrays(nums2, nums1);
        // }

        int curr=-1;
        int prev=-1;

        int n=n1+n2;
        int half = n/2;

        int i=0;
        int j=0;

        for(int k=0; k<=half; k++){
            prev = curr;
            if(i >= n1 || (j<n2) && (nums1[i]>nums2[j])){
                curr=nums2[j++];
            }else{
                curr=nums1[i++];
            }
        }



        if(n%2==0){
            return (prev+curr)/2.0;
        }
        return curr;
    }
};