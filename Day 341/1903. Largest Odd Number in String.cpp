class Solution {
public:
    string largestOddNumber(string num) {
        //int n = stoi(num);
        
        for(int i = num.size()-1; i>=0; i--){
            // we are checking that if any digit is even, then remove from the string
            if(num[i]%2 == 0)
                num.pop_back();
            else
                break;
        }
        return num;

    }
};