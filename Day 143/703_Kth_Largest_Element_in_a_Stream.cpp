class KthLargest {
public:
    // we are using min heap so that we can find kth largest element
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        // pushing every element of vector to queue
        for(int i = 0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        // assigning to the global variable
        K = k;
    }
    
    int add(int val) {
        // adding new values to queue
        pq.push(val);
        // if the size of queue is greater than k then pop it
        while(pq.size() > K) pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */