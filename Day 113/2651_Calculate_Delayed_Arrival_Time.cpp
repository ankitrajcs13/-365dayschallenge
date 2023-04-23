class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
     
        int ankiTime = arrivalTime + delayedTime;
        
        if(ankiTime >=24)
            ankiTime = ankiTime % 24;
        return ankiTime;
        
    }
};