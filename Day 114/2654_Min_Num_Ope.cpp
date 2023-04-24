class Solution {
public:
    int minOperations(vector<int>& A) {
        int one = 0, N=A.size();
        for (int i = 0; i < N; i++)
        {
            if (A[i] == 1)
                one++;
        }

        if (one != 0)
            return N - one;

        int minimum = INT_MAX;
        for (int i = 0; i < N; i++) 
        {
            int g = A[i]; 
            for (int j = i + 1; j < N; j++)
            {
                g = __gcd(A[j], g);
                if (g == 1) 
                {
                    minimum = min(minimum, j - i);
                    break;
                }
            }
        }

        if (minimum == INT_MAX)
            return -1;
        else
            return N + minimum - 1;
    
    }
};