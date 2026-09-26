class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(k, 0);
        int best = 0;

        for (int l = 0; l < n; l++) {
            long long sum = 0;
            vector<int> added;

            for (int r = l; r < n; r++) {
                sum += nums[r];
                int rem2x = (int)(((2LL * nums[r]) % k + k) % k);
                cnt[rem2x]++;
                added.push_back(rem2x);

                long long sm = ((sum % k) + k) % k;
                if (sm == 0 || cnt[(int)sm] > 0) {
                    best = max(best, r - l + 1);
                }
            }

            for (int x : added) cnt[x]--;
        }

        return best;
    }
};