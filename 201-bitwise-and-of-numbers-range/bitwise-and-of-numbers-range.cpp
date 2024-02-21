class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        // int ans=1;
        // if(right==0){
        //     return 0;
        // }
        while(right>left){
            // ans = ans & right;
            right=right &(right-1);
        }
        return right;
    }
};