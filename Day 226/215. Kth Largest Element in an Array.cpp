// Using Min Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int it: nums) pq.push(it);
        while(pq.size() > k)pq.pop();
        return pq.top();
    }
};

// Using MAx Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int it: nums) pq.push(it);
        while(pq.size() > k)pq.pop();
        return pq.top();
    }
};