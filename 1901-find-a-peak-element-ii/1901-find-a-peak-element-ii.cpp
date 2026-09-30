class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int r = 0, c = m - 1;
        while(r < n && c >= 0){
            int rprev = -1, rnext = -1, cprev = -1, cnext = -1;
            if(r > 0) rprev = mat[r - 1][c];
            if(r < n - 1) rnext = mat[r + 1][c];
            if(c > 0) cprev = mat[r][c - 1];
            if(c < m - 1) cnext = mat[r][c + 1];
            if(mat[r][c] > rprev && mat[r][c] > rnext && mat[r][c] > cprev && mat[r][c] > cnext){
                return {r, c};
            }
            else if (mat[r][c] < rprev) r--;
            else if (mat[r][c] < rnext) r++;
            else if (mat[r][c] < cprev) c--;
            else if (mat[r][c] < cnext) c++;
        }
        return {-1,-1};
    }
};