class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        // first store element and its position
        int n = nums.size();
        vector<pair<int,int>> v(n);
        
        for(int i = 0; i<n; i++)
            v[i] = {nums[i], i};

        // sort the vector to easily calucate the number of operations
        sort(v.begin(), v.end());
        int left = n;
        long long ans = 0, curr = 1;
        for(int i = 1; i<n; i++){
            if(v[i-1].second < v[i].second)
                curr++;
            else{
                ans+=left;
                left -=curr;
                curr=1;
            }
        }
        ans += curr;
        return ans;
    }
};