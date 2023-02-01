class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        // first check for the common string
        // concatenating each other to and fro is not equal
        if(str1 + str2 != str2 + str1)
            return "";
        else{
            // the substring which can divide both the string will be the gcd of both
            string ans = str1.substr(0,gcd(n,m));
            return ans;
        }
    }
};
// TC- O(1)
// SC- O(1)