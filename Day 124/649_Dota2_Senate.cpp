class Solution {
public:
    string predictPartyVictory(string senate) {
        
         int rCnt = 0, dCnt = 0;

         queue<char> q;
         for(auto ch: senate){
             q.push(ch);
             if(ch == 'R') rCnt++;
             else dCnt++;
         }
        int d = 0, r = 0;
         while(dCnt && rCnt){
             char c = q.front();
             q.pop();

             if(c == 'D'){
                 if(d){
                     d--;
                     dCnt--;
                 }
                 else{
                     r++;
                     q.push('D');
                 }
             }
             else{
                 if(r){
                     r--;
                     rCnt--;
                 }
                 else{
                     d++;
                     q.push('R');
                 }
             }
         }
         return dCnt? "Dire": "Radiant";
        

    }
};