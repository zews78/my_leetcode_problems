class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse =0;
        int k =32;
        while(k){
            uint32_t one = 1;
            reverse = reverse | n&(one);
            if(k!=1){
                reverse= reverse<<1;
            }
            n= n>>1;
            k--;
        }
        // cout<<n&(uint32_t)1;
        return reverse;
    }
};