class Solution {
public:
    string bi(int n ){
        string myAnk ;
        
        while(n){
            if(n & 1) myAnk += '1';
            else myAnk += '0';
            n >>= 1;// right shift
        }
        return myAnk;
    }
    
    vector<int> evenOddBit(int n) {
        
        string myAnk = bi(n);
        
        int ankiZ = 0, ankiO = 0;
        for(int i = 0; i<myAnk.length(); i++){
            if(myAnk[i] == '1' && i % 2 == 0) ankiO++;
            if(myAnk[i] == '1' && i % 2 != 0) ankiZ++;
        }
        return {ankiO,ankiZ};
        
        
    }
};