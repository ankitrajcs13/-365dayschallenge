class BrowserHistory {
private:
    vector<string> history;
    int currPage;
    int maxPage;
    
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPage = 0;
        maxPage = 0;
    }
    
    void visit(string url) {
        history.erase(history.begin() + currPage + 1, history.end());
        history.push_back(url);
        currPage++;
        maxPage = currPage;
    }
    
    string back(int steps) {
        currPage = max(0, currPage - steps);
        return history[currPage];
    }
    
    string forward(int steps) {
        currPage = min(maxPage, currPage + steps);
        return history[currPage];
    }
};