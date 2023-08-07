class Solution
{
public:
    int minimumSeconds(vector<int> &nums)
    {
        int n = nums.size();
        int ans = n - 1; 
        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++)
            m[nums[i]].push_back(i);

        for (auto i : m) 
        {
            vector<int> v = i.second; 
            int len = v.size();    
            //  now we change all remaining number= total size of array - size of same number
            int maxi = (n - 1) - (v[len - 1] - v[0]);
            for (int j = 1; j < len; j++)
            {
                maxi = max(maxi, v[j] - v[j - 1] - 1);
            }
            ans = min(ans, maxi);
        }
        return (ans + 1) / 2;
    }
};