class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
       
        if( numOnes >= k) return k;
        // here we can have maximum sum of ones so return ones
        if(numOnes+ numZeros >=k ) return numOnes;
        
        // subtract the k from ones and zeros to minimize k
        k = k - numOnes;
        k = k - numZeros;
        return numOnes-k;



    }
};