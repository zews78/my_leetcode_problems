class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int j=k;
        int n = blocks.size();
        int minRecolor= 0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W') minRecolor+=1;
        }
        
        cout<<n<<minRecolor<<endl;


        int temp=minRecolor;
        while(j<n){
            if(blocks[j-k]=='W'){
                temp--;
            }
            if(blocks[j]=='W'){
                temp++;
            }

            minRecolor = min(minRecolor, temp);
            // cout<<blocks[j]<<blocks[j-k]<<"-"<<temp<<","<<minRecolor<<" ";
            j++;
        }
        return minRecolor;
    }
};