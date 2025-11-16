class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n2<n1){
            return findMedianSortedArrays(nums2, nums1);
        }

        int n=n1+n2;
    
        int st=0;
        int e=n1;

        while(st<=e){
            int mid1 = st+(e-st)/2;
            int mid2 = ((n+1)/2)-mid1;
            // int mid2 = n2-mid1-1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if(mid1-1>=0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];

            if(mid1<n1) r1 = nums1[mid1];
            if(mid2<n2) r2 = nums2[mid2];

            if(l1<=r2 && l2<=r1){
                if(n%2==0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else{
                    return max(l1, l2);
                }
            }
            else if(l1>r2){
                e = mid1-1;
            }else{
                st = mid1+1;
            }

        }

        return 0;
    }
};