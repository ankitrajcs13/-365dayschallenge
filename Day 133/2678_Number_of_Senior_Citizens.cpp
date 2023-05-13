class Solution {
public:
    int countSeniors(vector<string>& details) {
        string anst = "";
        string st1 = "";
        int AnkiCnt = 0;
        for(int i = 0; i<details.size(); i++){
            anst = details[i];
            st1 = anst.substr(11,2);
            int AnAge = stoi(st1);
            if(AnAge > 60) AnkiCnt++;
        }
        return AnkiCnt;
    }
};