class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n = n1+n2;

        if(n1>n2){
            return findMedianSortedArrays(nums2, nums1);
        }

        int s=0;
        int end=n1; //since it's about the number of elements not index;

        while(s<=end){
            int mid1= s+(end-s)/2; //no. of ele on the left of nums1
            int mid2 = ((n+1)/2)-mid1; //no. of ele on left of nums2

            int l1 = (mid1>0)? nums1[mid1-1]: INT_MIN;
            int r1 = (mid1<n1)? nums1[mid1]: INT_MAX;

            int l2 = (mid2>0)? nums2[mid2-1]: INT_MIN;
            int r2 = (mid2<n2)? nums2[mid2]: INT_MAX;


            if((l2<=r1) && (l1<=r2)){
                //even-odd
                if(n%2==0){
                    return (max(l1, l2) + min(r1,r2))/2.0;
                }else{
                    return max(l1, l2);
                }
            }
            else if(r1<l2){
                s= mid1+1;
            }else{
                end = mid1-1;
            }
        }

        return 0;


    }
};