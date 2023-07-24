class Solution {
public:
    double myPow(double base, int power) 
    {
        if (power < 0) { base = 1 / base; power = abs(power); }
        double ans = 1;
        while(power > 0)
        {
            if (power % 2 == 0) 
            {
                base = base * base;
                power = power / 2;
            }
            else 
            {
                ans = (ans * base);
                power--;
            }
        }
        return ans;
    }
};