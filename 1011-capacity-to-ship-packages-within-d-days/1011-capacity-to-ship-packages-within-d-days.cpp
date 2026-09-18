class Solution {
public:
    int daysNeeded(vector<int>& weights, int capacity) {
        int days = 1;
        int currentLoad = 0;
           for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (daysNeeded(weights, mid) <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};