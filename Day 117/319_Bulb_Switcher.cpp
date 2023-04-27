class Solution {
public:
    int bulbSwitch(int n) {
        long long i=1;
        int ct=0;
        while((i*i)<=n){
            i++;
            ct++;
        }
        return ct;
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        return (sqrt(n));
    }
};