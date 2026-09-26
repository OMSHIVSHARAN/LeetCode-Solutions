class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        const int INF = 1e9;
        int n = nums.size();

        vector<int> bestL(k, INF);
        vector<int> combinedBestL(k, INF);
        vector<vector<int>> pending(k);

        bestL[0] = 0;

        for (int d = 0; d < k; d++) {
            pending[d].push_back(0);
        }

        int prefix = 0;
        int ans = 0;

        for (int j = 0; j < n; j++) {
            int v = nums[j] % k;
            if (v < 0) v += k;

            int d = (2LL * v) % k;

            for (int res : pending[d]) {
                int target = (res + d) % k;
                combinedBestL[target] =
                    min(combinedBestL[target], bestL[res]);
            }

            pending[d].clear();

            prefix = (prefix + v) % k;
            int r = j + 1;

            if (bestL[prefix] != INF) {
                ans = max(ans, r - bestL[prefix]);
            }

            if (combinedBestL[prefix] != INF) {
                ans = max(ans, r - combinedBestL[prefix]);
            }

            if (bestL[prefix] == INF) {
                bestL[prefix] = r;

                for (int x = 0; x < k; x++) {
                    pending[x].push_back(prefix);
                }
            }
        }

        return ans;
    }
};