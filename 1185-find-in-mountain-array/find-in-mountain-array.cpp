/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //find pivot
        int pivot = 0;
        int st=0;
        int end=mountainArr.length()-1;

        while(st<end){
            int mid=st+(end-st)/2;

            if((mountainArr.get(mid) < mountainArr.get(mid+1))){
                st=mid+1;
            }else{
                end=mid;
            }
        }
        pivot=end;

        int target_idx = -1;

        BinarySearch(pivot, mountainArr.length()-1, mountainArr, target, target_idx, false);
        BinarySearch(0, pivot, mountainArr, target, target_idx, true);

        return target_idx;
        
    }

    void BinarySearch(
        int st,
        int end,
        MountainArray &mountainArr,
        int target,
        int &target_idx,
        bool ascending
    ) {

        while (st <= end) {

            int mid = st + (end - st) / 2;

            int value = mountainArr.get(mid);

            if (value == target) {
                target_idx = mid;
                return;
            }

            if (ascending) {

                // Increasing array
                if (value < target)
                    st = mid + 1;
                else
                    end = mid - 1;

            }
            else {

                // Decreasing array
                if (value < target)
                    end = mid - 1;
                else
                    st = mid + 1;
            }
        }
    }
};