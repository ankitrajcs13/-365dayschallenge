class Solution {
public:
    int maxScore(string s) {
        int left = -1;
        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0')
                zeros++;
            else
                ones++;
            left = max(left, zeros - ones);
        }
        ones += s.back() == '1';
        return left + ones;        
    }
};