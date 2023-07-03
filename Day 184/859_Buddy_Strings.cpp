class Solution {
public:
    bool buddyStrings(string s, string goal) {
        //edge case
        if(s.size()!= goal.size()) return false;
        unordered_map<char,int> mp;

        if(s== goal){ // to handle the case when both strings are same and we have to swap
        // so we can swap only if any element occurs more than once.
        // so if the distinct chars are less than the size of string which means we can perform swapping
            unordered_set<char> disChar(s.begin(), s.end());
            return disChar.size() < s.length();
        }

        vector<int> idx;
        for(int i = 0; i<s.length(); i++){
            if(s[i] != goal[i]){
                idx.push_back(i);
            }
        }
        // it will ensure than we only have two values which has to be swapped
        if(idx.size() != 2) return false;

        // we are swapping both the values then
        swap(s[idx[0]], s[idx[1]]);
        return s==goal;

        
    }
};