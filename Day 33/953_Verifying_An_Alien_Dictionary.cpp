unordered_map<char,int> mp;
    bool cmp(string a, string b){
        int s = min(a.length(),b.length());

        for(int i = 0; i<s; i++){
            if(mp[a[i]] < mp[b[i]])
                return true;
            else if(mp[a[i]] > mp[b[i]])
                return false;
        }
        // now if length of a is smaller, then also it will be sorted
        if(a.length() <= b.length())
            return true;
        return false;
    }
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // store the order in map in ascending order
        for(int i = 0; i<order.length(); i++){
            mp[order[i]] = i;
        }

        // vector to store the word in sorted order
        vector<string> tmp = words;
        sort(tmp.begin(),tmp.end(), cmp);

        if(tmp == words)
            return true;
        else
            return false;



    }
};