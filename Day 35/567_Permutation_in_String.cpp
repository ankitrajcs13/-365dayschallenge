class Solution {
    bool check(vector<int> a, vector<int> b){
        for(int i = 0; i<26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // edge case
        if(s2.size() < s1.size()) return false;

        // frequency array
        vector<int> fs1(26,0);
        for(char c:s1)
            fs1[c-'a']++;
        
        // freq array for s2 string
        vector<int> fs2(26,0);
        int i = 0, j=0;

        while(j < s2.size()){
            fs2[s2[j] - 'a']++;
            // checking the window size
            if(j-i+1 == s1.size()){
                if(check(fs1,fs2)) return true;
            }

            if(j-i+1 < s1.size()) j++;
            else{
                fs2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;


    }
};
// TC - O(N)
// SC - O(1)