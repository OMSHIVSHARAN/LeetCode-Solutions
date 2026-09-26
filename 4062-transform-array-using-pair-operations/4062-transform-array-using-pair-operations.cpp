class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sumSource = 0, sumTarget = 0;
        for (int x : source) sumSource += x;
        for (int x : target) sumTarget += x;
        return sumSource == sumTarget;
        
        
    }
};