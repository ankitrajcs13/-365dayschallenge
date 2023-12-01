class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string fst = "";
        string scn = "";
        for(auto it:word1)fst+=it;
        for(auto it:word2)scn+=it;
        return (fst==scn);

    }
};