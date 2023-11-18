class Solution
{
    public:
        int n;
    bool check(vector<long long>&bit)
    {
        // any number more than two bit are same or not pair wise
        for(int i=0;i<32;i++)
        {
            if(bit[i]>=2)
            {
                return false;
            }
        }
        return true;
    }
    int longestNiceSubarray(vector<int> &nums)
    {
        n = nums.size();
        int j = 0;
        int ans = 1;
        vector < long long > bit(32, 0);
        for (int i = 0; i < n; i++)
        {
            for (int x = 0; x < 32; x++)
            {
                if (nums[i] &(1 << x))
                {
                    bit[x]++;
                }
            }
            while (j <= i && check(bit) == false)
            {
                for (int x = 0; x < 32; x++)
                {
                    if (nums[j] &(1 << x))
                    {
                        bit[x]--;
                    }
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};