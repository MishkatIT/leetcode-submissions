class AllOne {
public:
    AllOne() {
        
    }
    map<string, int> freq;
    map<int, set<string>> maxmin;
    void inc(string key) {
        freq[key]++;
        int cnt = freq[key];
        if (cnt > 1) {
            maxmin[cnt - 1].erase(key);
            if (maxmin[cnt - 1].size() == 0) {
                maxmin.erase(cnt - 1);
            }
        }
        maxmin[cnt].insert(key);
    }
    
    void dec(string key) {
        freq[key]--;
        int cnt = freq[key];
        if (cnt != 0) {
            maxmin[cnt].insert(key);
        } 
        maxmin[cnt + 1].erase(key);
        if (maxmin[cnt + 1].size() == 0) {
            maxmin.erase(cnt + 1);
        }
    }
    
    string getMaxKey() {
        return (maxmin.empty() ? "" : *maxmin.rbegin()->second.begin());
    }
    
    string getMinKey() {
        return (maxmin.empty() ? "" : *maxmin.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */