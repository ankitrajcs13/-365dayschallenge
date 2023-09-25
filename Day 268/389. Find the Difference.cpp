class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for(int it:t) sum+=it;
        for(int it:s) sum-=it;
        return (char)sum;
    }
};

// using map

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        unordered_map<char,int>mp;
        for(auto it:s) mp[it]++;

        for(int it: t){
            if(--mp[it]<0) return it;
        }
        return -1;
    }
};