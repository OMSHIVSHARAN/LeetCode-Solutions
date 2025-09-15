class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     if (nums1.size() > nums2.size()) swap(nums1, nums2);
    
    int m = nums1.size(), n = nums2.size();
    int totalLeft = (m + n + 1) / 2;
    int low = 0, high = m;
    
    while (low <= high) {
        int i = (low + high) / 2;
        int j = totalLeft - i;
        
        int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
        int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
        int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
        int nums2RightMin = (j == n) ? INT_MAX : nums2[j];
        
        if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
            if ((m + n) % 2 == 0) {
                return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
            } else {
                return max(nums1LeftMax, nums2LeftMax);
            }
        } else if (nums1LeftMax > nums2RightMin) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    
    throw invalid_argument("Input arrays are not sorted or invalid.");
}
};