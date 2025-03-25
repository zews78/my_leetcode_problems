class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int rect_count = rectangles.size();
        vector<vector<int>> horizontal;
        vector<vector<int>> vertical;
        for(int i=0; i<rectangles.size(); i++){
            int ver_start = rectangles[i][1];
            int ver_end = rectangles[i][3];
            int hor_start = rectangles[i][0];
            int hor_end = rectangles[i][2];
            horizontal.push_back({hor_start, hor_end});
            vertical.push_back({ver_start, ver_end});
        }
        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());

        int vertical_latest=vertical[0][1];
        int vertical_lines =0;

        int horizontal_latest=horizontal[0][1];
        int horizontal_lines =0;
        // for(auto x: vertical){
        //     cout<<x[0];
        // }

        for(int i=1; i<vertical.size(); i++){
            int s = vertical[i][0];
            int e = vertical[i][1];

            int s_h = horizontal[i][0];
            int e_h = horizontal[i][1];

            if(s_h>= horizontal_latest){
                horizontal_lines++;
            }
            horizontal_latest = max(horizontal_latest, e_h);

            if(s>= vertical_latest){
                vertical_lines++;
            }
            vertical_latest = max(vertical_latest, e);
            
        }

        cout<<horizontal_lines<<" "<<vertical_lines<<endl;
        return (horizontal_lines>=2 || vertical_lines>=2);
    }
};