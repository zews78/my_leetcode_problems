class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int s =0;
        int e =nums.size()-1;
        return countReverse(s, e, nums);
    }

    int countReverse(int s, int e, vector<int>& nums){
        int cnt = 0;
        if(s<e){
            int mid = s + (e-s)/2;
            cnt+= countReverse(s, mid, nums);
            cnt+= countReverse(mid+1, e, nums);
            cnt+= countMerge(s,mid,e,nums);
            
        }
        return cnt;
    }

    int countMerge(int s, int mid, int e, vector<int>& nums){
        int n1 = mid-s+1;
        int n2 = e-mid;
        int cnt =0;

        vector<int> arr1;
        for(int i=0; i<n1; i++){
            arr1.push_back(nums[s+i]);
        }

        vector<int> arr2;
        for(int i=0; i<n2; i++){
            arr2.push_back(nums[mid+i+1]);
        }

        int i=0, j=0;
        while(i<n1 && j<n2){
            if(arr1[i]> 2*(long)arr2[j]){
                cnt+= n1-i;
                j++;
            }
            else{
                i++;
            }

        }        

        i=0, j=0;
        int k=s;
        while(i<n1 && j<n2){
            if(arr1[i]>arr2[j]){
                nums[k++] = arr2[j++];
            }
            else{
                nums[k++]=arr1[i++];
            }

        }

        while(i<n1){
            nums[k++] = arr1[i++];
        }
        while(j<n2){
            nums[k++] = arr2[j++];
        }

        return cnt;

    }
};