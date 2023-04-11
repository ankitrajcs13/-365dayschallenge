class Solution {
public:
    std::string removeStars(const std::string& s) {
        std::string result;
        result.reserve(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(s[i]);
            }
        }
        return std::move(result);
    }
};