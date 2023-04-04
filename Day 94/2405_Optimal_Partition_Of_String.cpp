class Solution {
public:
    int partitionString(string s) {
        // vector to store the prev occurence of each character in the string
        vector<int> v(26,-1);
        int newIdx = 0;
        int cnt = 1;
        for(int i = 0; i<s.length(); i++){
            int idx = s[i]-'a';
            // it means we can create new substring
            if(v[idx] >= newIdx){
                cnt++;
                newIdx = i;
            }
            // update the prev occurence in vector
            v[idx] = i;
        }
        return cnt;

    }
};