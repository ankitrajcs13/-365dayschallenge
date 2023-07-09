class Solution {
public:
    int largestVariance(string s) {
        vector<int> fre(26);

        for(auto it:s)
            fre[it-'a']++;

        int res = 0;

        for(char i = 'a'; i<= 'z'; i++){
            for(char j = 'a'; j<= 'z'; j++){
                if(j==i || fre[i-'a'] == 0 || fre[j-'a'] == 0) continue;

                for(int k = 1; k<=2; k++){
                    int t1 = 0, t2 = 0;
                    for(auto x:s){
                        if(x == i) t1++;
                        if(x == j) t2++;
                        if(t2 > t1) t1 = 0,t2 = 0;
                        if(t1 >0 && t2 > 0) res = max(res, t1-t2);
                    }
                    reverse(s.begin(), s.end());
                }

            }
        }
        return res;
    }
};