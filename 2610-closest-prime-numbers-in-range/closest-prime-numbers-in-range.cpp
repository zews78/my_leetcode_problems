class Solution {
public:
    bool checkPrime(int val){
        if(val<=1) return false;
        if(val==2 || val==3) return true;
        if(val%2==0 || val%3==0) return false;
        for(int i=5; i*i<=val; i=i+6){
            if(val%i ==0 || val%(i+2)==0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime_numbers;
        for(int i=left; i<=right; i++){
            if(checkPrime(i)){
                prime_numbers.push_back(i);
            }
        }

        if(prime_numbers.size()<2){
            return {-1, -1};
        }
        for(auto x: prime_numbers){
            cout<<x<<" ";
        }
        int min_ind;
        int min_val=INT_MAX;
        for(int i=prime_numbers.size()-1; i>0; i--){
            if(prime_numbers[i]-prime_numbers[i-1]<= min_val){
                min_val = prime_numbers[i]-prime_numbers[i-1];
                min_ind = i;
            }
        }
        return {prime_numbers[min_ind-1], prime_numbers[min_ind]};
        // return {};
    }
};