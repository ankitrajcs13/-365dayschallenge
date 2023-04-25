class SmallestInfiniteSet {
public:
    map<int,int> mp;
    SmallestInfiniteSet() {
        for(int i =1;i<=1000;i++) mp[i]++;
    }
    
    int popSmallest() {
        int a = mp.begin()->first;
        mp.erase(a);
        return a;
    }
    
    void addBack(int num) {
        mp[num]++;
    }
};