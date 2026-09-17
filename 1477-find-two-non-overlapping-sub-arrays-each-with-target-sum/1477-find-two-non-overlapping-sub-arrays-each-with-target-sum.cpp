class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e9); 
        
        int left = 0, sum = 0;
        int best = 1e9, ans = 1e9;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int curr_len = right - left + 1;
                
                if (left > 0 && min_len[left - 1] != 1e9) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                
                best = min(best, curr_len);
            }
            
            min_len[right] = best;
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};