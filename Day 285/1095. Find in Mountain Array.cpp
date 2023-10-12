/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakElement(MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int l = 0;
        int r = n-1;
        
        while(l < r) {
            
            int mid = l + (r-l)/2;
            
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid+1;
            else
                r = mid;
            
        }
        
        return l;
    }
    int bs(MountainArray &mountainArr,int l, int h, int target){
        while(l<=h){
            int mid = l + (h-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target ) l = mid+1;
            else h = mid-1;
        }
        return -1;
    }
    int rbs(MountainArray &mountainArr,int l, int h, int target){
        while(l<=h){
            int mid = l + (h-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target ) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIdx = peakElement(mountainArr);

        int fst = bs(mountainArr,0,peakIdx,target);
        if(fst != -1) return fst;

        int scnd = rbs(mountainArr,peakIdx+1,n-1,target);
        return scnd;
    }
};