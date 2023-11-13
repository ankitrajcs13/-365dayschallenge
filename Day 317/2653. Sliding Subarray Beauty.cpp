class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        vector<int> freq(101, 0); // Frequency array to store the occurrences of each element

        for (int i = 0; i < k; ++i) {
            freq[nums[i] + 50]++; // Adjusting the index to handle negative values
        }

        // Find the beauty of the first subarray
        int beauty = 0;
        for (int i = 0; i < 101; ++i) {
            beauty += freq[i];
            if (beauty >= x) {
                ans.push_back((i - 50) < 0 ? i - 50 : 0); // Adjusting the index to get the original value
                break;
            }
        }

        // Iterate through the remaining windows
        for (int i = k; i < n; ++i) {
            freq[nums[i - k] + 50]--; // Remove the leftmost element from the window
            freq[nums[i] + 50]++;    // Add the current element to the window

            beauty = 0;
            for (int j = 0; j < 101; ++j) {
                beauty += freq[j];
                if (beauty >= x) {
                     ans.push_back((j - 50) < 0 ? j - 50 : 0); // Adjusting the index to get the original value
                    break;
                }
            }
        }

        return ans;
    }
};