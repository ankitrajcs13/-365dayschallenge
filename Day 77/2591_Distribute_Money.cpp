class Solution {
public:
    int distMoney(int money, int children) {
        
        // edge case
        if(children > money) return -1;
        if(money < 8 ) return 0;
        
        int ds = money / 8; 
        int md = money % 8;
        if(ds == children && md == 0) return children;
        
        if(ds >= children) return children -1;
        
        if(md == 4 && (children-ds) == 1 ) return children -2;
        if(md >= (children - ds)) return ds;
        
        int Anki = children - ds;
        while(md < Anki){
            Anki++;
            md+=8;
            ds--;
        }
        
        
        return ds;
    }
};