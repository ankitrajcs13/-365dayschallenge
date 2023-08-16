// Using Priority Queue

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for(int i = k; i < n; i++) {
            pq.push({nums[i], i});

            while(pq.top().second < i+1-k) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

// Using Monotonic Queue

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
            q.pop_back();
            }
            q.push_back(i);
            if (q.front() == i - k) {
            q.pop_front();
            }
            if (i >= k - 1) {
            res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};