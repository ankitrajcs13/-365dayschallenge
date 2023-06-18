class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        
        int res = 0;
        while(mainTank>0){
            mainTank--;
            res++;
            if(res%5 == 0 && additionalTank> 0){
                mainTank++;
                additionalTank--;
            }

        }
        return res * 10;


    }
};

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return (mainTank + min( additionalTank, (mainTank-1)/4)) * 10;
    }
};