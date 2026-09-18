class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        
        vector<pair<int, int>> intervals;
        
        for (int c = 0; c < 26; ++c) {
            if (first[c] == -1) continue;
            
            int start = first[c];
            int end = last[c];
            bool valid = true;
            
            for (int i = start; i <= end; ++i) {
                if (first[s[i] - 'a'] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[s[i] - 'a']);
            }
            
            if (valid) {
                intervals.push_back({end, start});
            }
        }
        
        sort(intervals.begin(), intervals.end());
        vector<string> res;
        int prev = -1;
        
        for (auto& interval : intervals) {
            if (interval.second > prev) {
                res.push_back(s.substr(interval.second, interval.first - interval.second + 1));
                prev = interval.first;
            }
        }
        
        return res;
    }
};