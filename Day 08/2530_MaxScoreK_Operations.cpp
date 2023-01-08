class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long int ans = 0, temp = 0;
        for(int i :nums)
            pq.push(i);
        
        // Since the Priority Queue-> i.e., Max Heap will always have max
        // Element on the top, which we require for the operation
        while(k--){
            temp = pq.top();
            ans +=temp;
            pq.pop();
            pq.push(ceil(temp/3.0));
        }
        return ans;
    }
};

// TC - O(n) + klog(n)
// SC - O(1) -> For Max Heap