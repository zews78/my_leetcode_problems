class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0, j=0;
        int n = arr.size();
        int count = 0;

        int sum =0;
        for(j; j<k; j++){
            sum+= arr[j];
        }

        if((sum/k)>=threshold){
            count++;
        }

        while(j<n){
            sum-=arr[i];
            sum+=arr[j];
            // cout<<sum<<" ";
            if((sum/k)>=threshold){
                count++;
            }
            i++; j++;
        }

        return count;
    }
};