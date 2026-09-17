class Solution {
public:
    long long sumByD(vector<int>& arr, int div) {
        long long sum = 0;
        for (int num : arr) {
            sum += (num + div - 1) / div;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (sumByD(arr, mid) <= threshold) {
                high = mid - 1; 
            } else {
                low = mid + 1;   
            }
        }

        return low;
    }
};