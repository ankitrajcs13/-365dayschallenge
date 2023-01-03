class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) 
            return "0";
        string ans;
        int n=abs(num);
        while(n!=0){
            ans.push_back(n%7+'0');
            n=n/7;
        }
        if(num<0){
            ans.push_back('-');
        }
        // we are reversing the string because we are solving it from right!
    reverse(ans.begin(),ans.end());

   return ans;
    }
};