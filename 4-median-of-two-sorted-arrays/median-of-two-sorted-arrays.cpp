class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int prev=-1;
        int curr=-1;

        int n1=nums1.size();
        int n2=nums2.size();

        int n=n1+n2;
        int half = n/2;

        int i=0, j=0, k=0;

        while(k<=half && i<n1 && j<n2){
            prev = curr;
            if(nums1[i]<=nums2[j]){
                curr= nums1[i];
                i++;
            }else{
                curr = nums2[j];
                j++;
            }
            k++;
        }
        while(k<=half && i<n1){
            prev = curr;
            curr= nums1[i];
            i++; k++;
        }
        while(k<=half && j<n2){
            prev = curr;
            curr = nums2[j];
            j++; k++;
        }


        if(n%2==0){
            return (prev+curr)/2.0;
        }
        return curr;
    }
};