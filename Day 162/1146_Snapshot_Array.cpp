class SnapshotArray {
public:

    vector<map<int,int>> mpv;
    int id = 0;

    SnapshotArray(int length) {
        mpv.resize(length);
        // initially putting all the elements as 0
        for(int i = 0; i<length; i++)
            mpv[i][0] = 0;
    }
    
    void set(int index, int val) {
        mpv[index][id] = val;
    }
    
    int snap() {
        id++;
        return id-1;
    }
    
    int get(int index, int snap_id) {
        if(mpv[index].find(snap_id) == mpv[index].end()){
            // it means it's not present
            auto it = --mpv[index].lower_bound(snap_id);
            return it->second;
        }
        return mpv[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */