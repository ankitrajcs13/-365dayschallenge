class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> st;
    unordered_map<string, unordered_map<string,int>> tot,tim;
    UndergroundSystem() {
        st.clear(), tot.clear(), tim.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        st[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        tot[st[id].first][stationName] += t - st[id].second;
        tim[st[id].first][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (tot[startStation][endStation])/(double)(tim[startStation][endStation]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */