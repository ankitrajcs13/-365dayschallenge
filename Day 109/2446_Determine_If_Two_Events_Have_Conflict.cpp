class Solution {
public:

    int tomin(string s) {
        return ((s[0]-'0')*10 + (s[1]-'0'))*60 + ((s[3]-'0')*10 + (s[4]-'0'));
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        
        int t1 = tomin(event1[0]);
        int t2 = tomin(event1[1]);
        int t3 = tomin(event2[0]);
        int t4 = tomin(event2[1]);

        int myRes = max(t1,t3);
        int myRes1 = min(t2,t4);

        return myRes <= myRes1;


    }
};