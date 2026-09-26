class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        int dr = tr - sr;
        int dc = tc - sc;

        if (dr == 0 && dc == 0) return 0;
        if (dr == 0 || dc == 0 || abs(dr) == abs(dc)) return 1;
        return 2;
    }
};