class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int result = 1, subArrStart = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size(); ++i) {
            k -= nums[subArrStart] - nums[i];

            while (k < 0)
                k += (nums[subArrStart] - nums[subArrStart + 1]) * (i - subArrStart++);

            result = max(result, i - subArrStart + 1);
        }

        return result;
    }
};