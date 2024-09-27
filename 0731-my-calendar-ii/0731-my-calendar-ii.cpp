class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    vector<pair<int, int>> nonOv, ov; // non overlapping, overlapping
    bool book(int start, int end) {
        
        auto ok = [&](vector<pair<int,int>>& x) {
            for (auto& i : x) {
                if (start >= i.second || end <= i.first) continue;
                else return false;
            }
            return true;
        };

        if (ok(ov)) {
            for (auto& i : nonOv) {
                if (start >= i.second || end <= i.first) continue;
                else {
                    ov.push_back({max(i.first, start), min(i.second, end)});
                }
            }
            nonOv.push_back({start, end});
            return true;
        } else return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */