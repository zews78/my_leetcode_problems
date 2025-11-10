class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child=0;
        int cookie=0;
        int count=0;
        // for(int i=0; i<g.size(); i++){
        //     cout<<g[i];
        // }cout<<endl;
        // for(int i=0; i<s.size(); i++){
        //     cout<<s[i];
        // }cout<<endl;
        while(child<g.size() && cookie<s.size()){
            // cout<<g[child]<<"-"s[cookie]<<endl;
            if(g[child]<=s[cookie]){
                count++;
                child++;
                cookie++;
            }else{
                cookie++;
            }
        }
        return count;
    }
};