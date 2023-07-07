class Solution {
public:
    int solve(string str, int k, char ch) {
            int left = 0;
            int ans = 0;
            int count = 0;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ch) {
                    count++;
                }
                while (count > k) {
                    if (str[left] == ch) {
                        count--;
                    }
                    left++;
                }
                ans = max(ans, i - left + 1);
            }
            return ans;
        }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};