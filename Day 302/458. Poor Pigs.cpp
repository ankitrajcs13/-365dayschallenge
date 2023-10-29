class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest/minutesToDie + 1;
        int pigs = 0;
        while(pow(T, pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};