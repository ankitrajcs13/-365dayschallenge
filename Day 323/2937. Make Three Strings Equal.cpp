class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int anki1 = s1.size(), anki2 = s2.size(), anki3 = s3.size();
        //check for same char
        int pt = 0;
        int mini = min(anki1,min(anki2,anki3));
        while(pt<mini && s1[pt] == s2[pt] && s1[pt] == s3[pt]) pt++;
        int ankicnt = anki1+anki2+anki3 - 3 * pt;
        //cout<<ankicnt;
        return (pt==0)? -1:ankicnt;
    }
};