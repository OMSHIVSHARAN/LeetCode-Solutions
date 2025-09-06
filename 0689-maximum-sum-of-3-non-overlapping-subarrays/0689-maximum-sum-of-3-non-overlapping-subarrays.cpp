class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windowSum(n - k + 1, 0);
        vector<int> leftBest(n - k + 1), rightBest(n - k + 1);
        
       
        int currentSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            if (i >= k - 1) {
                windowSum[i - k + 1] = currentSum;
                currentSum -= nums[i - k + 1];
            }
        }
        int bestIdx = 0;
        for (int i = 0; i < windowSum.size(); ++i) {
            if (windowSum[i] > windowSum[bestIdx]) {
                bestIdx = i;
            }
            leftBest[i] = bestIdx;
        }

        
        bestIdx = windowSum.size() - 1;
        for (int i = windowSum.size() - 1; i >= 0; --i) {
            if (windowSum[i] >= windowSum[bestIdx]) {
                bestIdx = i;
            }
            rightBest[i] = bestIdx;
        }

        
        vector<int> result(3, -1);
        int maxSum = 0;
        for (int mid = k; mid < windowSum.size() - k; ++mid) {
            int left = leftBest[mid - k];
            int right = rightBest[mid + k];
            int totalSum = windowSum[left] + windowSum[mid] + windowSum[right];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {left, mid, right};
            }
        }

        return result;
    }
};
