class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        

        int n = s.length();
        for(int i = 0; i<n;i++){
            for(int j = i+1; j<n; j++){
                if(s[i] == s[j]){
                    if(j-i-1 != distance[s[i]-'a']) return false;
                }
            }
        }
        return true;

    }
};