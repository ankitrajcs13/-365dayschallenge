class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;

        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for(auto it : mp) 
            pq.push(make_pair(it.second, it.first));
        int i = 0;
        while(i<k) {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans;

    }
};