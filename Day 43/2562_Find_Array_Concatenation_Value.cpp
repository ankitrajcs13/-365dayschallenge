class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        
        
        long long m_cnt = 0, my_ans = 0;
        
        int m_n = nums.size();
        
        if(m_n <=1) return m_cnt;
        
        int m_first = 0;
        int m_last = m_n-1;
        
        while(m_first < m_last){
            string st_first  = to_string(nums[m_first]) ;
            string st_last = to_string(nums[m_last]);
            string ans = st_first + st_last;
            
            my_ans = stoi(ans);
            m_cnt +=my_ans;
            // increment first value
            m_first++;
            // decrement last value
            m_last--;
            
        }
        // finding for any value present in the array
       
        if(nums.size() % 2)
            m_cnt += nums[nums.size()/2];
        return m_cnt;
    }
};