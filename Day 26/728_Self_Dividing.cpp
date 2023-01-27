class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i= left; i<=right; i++){
            int n = i;
            while(n != 0){
                int digit = n % 10;
                // digit should not be zero
                if(digit == 0) break;
                // digit should be completely divisible by number
                if(i % digit != 0) break;
                n /= 10;
            }
            // At this point, if the value of n is equals to 0,
            // it means that the number is self divisible.
            if(n == 0)
                ans.push_back(i);
        }
        return ans;

    }
};
// TC - O(N)
// SC - O(N)

class Solution {
public:
    bool isDiv(int i)
    {
        int num=i;
        while(i>0)
        {
            int rem=i%10;
            if(rem!=0)
            {
                if(num%rem!=0)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            i=i/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> ans;
        for(int i=left; i<=right; i++)
        {
            if(i%10!=0)
            {
                if(isDiv(i))
                {
                    ans.push_back(i);
                }
            }
            else
            {
                continue;
            }
        }
        return ans;
        
    }
};
