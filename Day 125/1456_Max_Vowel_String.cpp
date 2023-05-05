class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();

        int l = 0, r = 0;
        int ans = 0, tmp = 0;

        while(r < n){
            if(isVowel(s[r])) tmp++;
            // when we reach the window of size k
            if(r - l == k){
                if(isVowel(s[l])) tmp--;
            l++;
            }

            // we have to find the max num of vowels in a Substring
            ans = max(ans,tmp);
            r++;
        }
        return ans;



    }
};