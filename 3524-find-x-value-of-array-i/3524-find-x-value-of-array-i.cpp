class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> current_freq(k, 0);
        
        for (int num : nums) {
            vector<long long> next_freq(k, 0);
            long long val = num % k;
            
            next_freq[val] += 1;
            
            for (int i = 0; i < k; i++) {
                if (current_freq[i] > 0) {
                    next_freq[(i * val) % k] += current_freq[i];
                }
            }
            
            for (int i = 0; i < k; i++) {
                ans[i] += next_freq[i];
                current_freq[i] = next_freq[i];
            }
        }
        
        return ans;
    }
};