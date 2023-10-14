class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ankires;
        // track last
        int ankilst = groups[0];
        ankires.push_back(words[0]);
        for(int i = 1; i<groups.size(); i++){
            if(groups[i] != ankilst){
                ankires.push_back(words[i]);
                ankilst = groups[i];
            }
        }
        //cout<<ankires[0];
        return ankires;
        
    }
};