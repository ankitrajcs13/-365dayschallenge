class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long n = gifts.size();
        while(k--){
            int myGift = INT_MIN, myInd = 0;
            
            for(int i = 0; i<n; i++){
                // finding the max element of array
                if(gifts[i] > myGift){
                    myGift = gifts[i];
                    myInd = i;
                }
            }
            // updating the value of that index by floor value of sqrt
            gifts[myInd] = floor(sqrt(gifts[myInd]));
        }
        // now couting the sum of array elements
        long long mySum = 0;
        for(int i = 0; i<n; i++){
            mySum +=gifts[i];
        }
        return mySum;
        
        
    }
};