int minTaps(int n, vector<int> &ranges)
{
    vector<int> rightMax(ranges.size(), 0);
    for (int i = 0; i <= n; i++)
    {
        if (ranges[i] != 0)
        {
            int leftEndPoint = max(0, i - ranges[i]);
            rightMax[leftEndPoint] = max(rightMax[leftEndPoint], i + ranges[i]);
        }
    }

    int maxReached = 0;
    int end = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        maxReached = max(maxReached, rightMax[i]);
        if (i == end)
        {
            if (end == maxReached)
                return -1;
            end = maxReached;
            ans++;
        }
    }
    return ans;
}

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> arr(n + 1, 0);
        for (int i = 0; i < ranges.size(); i++)
        {
            if (ranges[i] == 0)
                continue;
            int left = max(0, i - ranges[i]);
            arr[left] = max(arr[left], i + ranges[i]);
        }
        int end = 0, farCanReach = 0, ans = 0;
        for (int i = 0; i < arr.size() && end < n; end = farCanReach)
        {
            ans++;
            while (i < arr.size() && i <= end)
            {
                farCanReach = max(farCanReach, arr[i++]);
            }
            if (end == farCanReach)
                return -1;
        }
        return ans;
    }
};