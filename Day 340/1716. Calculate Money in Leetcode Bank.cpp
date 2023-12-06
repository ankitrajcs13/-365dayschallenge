class Solution {
public:
    int totalMoney(int n) {
        if(n <8){
            return (n * (n+1))/2;
        }
        else{
          int ans = 0, mon =1;
          while(n>0){
            for(int i = 0; i<min(n,7); i++){
              ans += mon + i;
            }
            n-=7;
            mon++;
          }
          return ans;
        }
    }
};