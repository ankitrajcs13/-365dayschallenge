class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        
        int res1 = 0, Ares2 = 0;
        int Ankitmp = 1;
        // to track of last and second last var
        
        
        
        for(int i = 0; i<player1.size(); i++){
            
            if( (i> 0 && player1[i-1] == 10) || ( i>1 && player1[i-2] == 10))
                res1 += 2 * player1[i];
            else
                res1 += player1[i];
            
        }    
        // for second player
        for(int i = 0; i<player2.size(); i++){
            
            if( (i> 0 && player2[i-1] == 10) || ( i>1 && player2[i-2] == 10))
                Ares2 += 2 * player2[i];
            else
                Ares2 += player2[i];
            
        }  
            
        if(res1 > Ares2) return 1;
        else if(Ares2 > res1) return 2;
        else return 0;
        // return Ares2;
        
        
    }
};