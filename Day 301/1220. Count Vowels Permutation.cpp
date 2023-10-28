class Solution {
public:
    int M = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    int countVowelPermutation(int n) {

        long long t[5][n+1];

        for(int vowel = 0; vowel <= 4; vowel++) {
            t[vowel][1] = 1;
        }

        for(int len = 2; len <= n; len++) {
            t[a][len] = (t[e][len-1] + t[i][len-1] + t[u][len-1]) % M;

            t[e][len] = (t[a][len-1] + t[i][len-1]) % M;

            t[i][len] = (t[e][len-1] + t[o][len-1]) % M;

            t[o][len] = (t[i][len-1]) % M;

            t[u][len] = (t[i][len-1] + t[o][len-1]) % M;
        }
        long long result = 0;
        for(int vowel = 0; vowel <= 4; vowel++) {
            result = (result + t[vowel][n]) % M;
        }
        return result;
   
    }
};