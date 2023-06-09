class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st = 0, end = letters.size()-1, mid;

        while(st <=end){
            mid = st + (end-st)/2;
            if(letters[mid] > target) end = mid-1;
            else st = mid+1;
        }
        if(st == letters.size()) return letters[0];
        else return letters[st];
    }
};