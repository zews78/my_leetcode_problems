class Solution {
public:
    int reverse(int x) {
        long long int ans=0;
        int x2 = x;
        int n=0;//size of x
        // vector<int> arr;
        while(x){
            // arr.push_back(x%10);
            // cout<<x%10<<endl;
            x = x/10;
            n++;
        }
        // cout<<n;
        for(int i=0; i<n; i++){
            ans += pow(10,(n-i-1))* (x2%10);
            x2 /= 10;
            // cout<<ans<<endl;
        }
        if(ans > INT_MAX || ans<INT_MIN){
            return 0;
        }
        return ans;

        // while()
        
    }
};