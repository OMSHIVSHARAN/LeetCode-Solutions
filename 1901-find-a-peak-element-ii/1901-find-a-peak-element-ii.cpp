class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0, high = cols - 1;

        while (low <= high) {
            int midCol = low + (high - low) / 2;
            
            int maxRow = 0;
            for (int i = 0; i < rows; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int left = midCol > 0 ? mat[maxRow][midCol - 1] : -1;
            int right = midCol < cols - 1 ? mat[maxRow][midCol + 1] : -1;

            if (mat[maxRow][midCol] > left && mat[maxRow][midCol] > right) {
                return {maxRow, midCol};
            } else if (mat[maxRow][midCol] < left) {
                high = midCol - 1;
            } else {
                low = midCol + 1;
            }
        }

        return {-1, -1};
    }
};