class Solution {
public:
    int pivotInteger(int n) {
        // using binary search
        if(n == 1) return 1;
        int st = 0;
        int end = n;
        while(st<=end){
            int mid = (st+end)/2;

            int s1 = (mid)*(mid+1)/2;
            int s2 = (n*(n+1))/2-s1+mid;

            if(s1 == s2) return mid;

            else if(s1 < s2) st = mid+1;
            else end = mid-1;
        }
        return -1;
        
    }
};