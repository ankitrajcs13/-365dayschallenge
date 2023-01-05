class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            // we will count the number of capital letters
            if(isupper(word[i]))
                cnt++;
        }

        /* now check all the conditions:
            1. if all the characters are capital (cnt == n)
            2. if none of them are capital (cnt == 0)
            3. if only one is capital then we will verify that it should be the first element
        */
        if((cnt == n) || (cnt == 0) || (cnt == 1 && isupper(word[0])) ){
            return true;
        }
        return false;

    }
};
// TC: O(n)
// SC: O(1)

// 2nd approach - we will check the false conditons like where this is not true:

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n = word.size();

        for(int i = 1; i<n; i++){
            // to check that if first letter is capital and others are small then return false
            if(islower(word[0]) && isupper(word[i]))) 
                return false;
            // to check that all the elements from 1st to last index are capital or not
            if(isupper(word[1]) != isupper(word[i]))
                return false;
        }
        return true;


    }
};
