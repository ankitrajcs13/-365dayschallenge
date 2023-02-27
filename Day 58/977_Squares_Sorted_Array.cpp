class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            nums[i]  = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;

    }
};
// TC - O(N)
// SC - O(1)



// 2nd Approach
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // using min Heap
        priority_queue<int, vector<int>, greater<int> > pq;
        
        while(nums.size() > 0){
            pq.push(pow(nums.back(),2));
            nums.pop_back();
        }

        while(!pq.empty()){
            nums.push_back(pq.top());
            pq.pop();
        }
        return nums;
    }
};

// TC - O(LogN)
// SC - O(N) for priority queue