class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int opened = 0;

        for(int i = 0; i < S.size(); i++) {

            if(S[i] == '(') {
                
                if(opened > 0)
                    ans += S[i];

                opened++;
            }

            if(S[i] == ')') {
                opened--;

               
                if(opened > 0)
                    ans += S[i];
            }
        }

        return ans;
    }
};