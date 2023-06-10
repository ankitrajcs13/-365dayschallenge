class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if(n==1) return maxSum;
        maxSum-=n;
        int left = index,right = n-index-1,ans=1;
        // finding indexes_count left of index and right of index

        int t1=-1,t2=-1;
        while(maxSum) {
            t1++; t2++; // goes left and right to get difference <=1
            int x = min(t1,left)+min(t2,right)+1;
            // x is the cost to increment 1, at given index 

            if(maxSum<x) break;  maxSum-=x;
            ans++;
            if(x==(left+right+1)) { // this if case make O[n] => O[logn]
                ans+=(maxSum/x); break;
            }
        }
        return ans;
    }
};