class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> ugly;
        ugly.push_back(1);
        int i2=0;
        int i3=0;
        int i5=0;


        for(int i=1; i<n; i++){
            int next2= ugly[i2]*2;
            int next3= ugly[i3]*3;
            int next5= ugly[i5]*5;

            int nextUgly = min({next2, next3, next5});
            ugly.push_back(nextUgly);

            if(next2==nextUgly) i2++;
            if(next3==nextUgly) i3++;
            if(next5==nextUgly) i5++;
        }

        return ugly[n-1];


    }
};