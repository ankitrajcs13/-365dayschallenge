class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; 
        vector<int> NGE; 
        for(int i=2*n-1;i>=0;i--)
    {
        // poping till our stack top dont become greater 
        while(st.empty()==false && nums[i%n]>=st.top())
        {
            st.pop();
        }
        
        // taking into NGE top n elements out of 2n by implementing (i % n) -> it implements the imaginary vector of 2n which
        // solves the case of circular vector
        if(i<n)
        {
            if(st.empty()==false)
            {
                NGE.push_back(st.top());
            }
            else
            {
                NGE.push_back(-1);
            }
        }
        st.push(nums[i%n]);
    }
    // reverse after the whole iteration beacuse this is the vector and its store the values in a manner 
    // it is not like array indexing so after whole iteration we need to reverse because we iterate it
    // from behind
    reverse(NGE.begin(),NGE.end());
    return NGE;

    }
};