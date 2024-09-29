class AllOne {
public:
    AllOne() {}
    
    void inc(string key) {
        int count = countMap[key]++;
        if (count > 0) {
            countSet[count].erase(key);
            if (countSet[count].empty()) {
                countSet.erase(count);
            }
        }
        countSet[count + 1].insert(key);
    }
    
    void dec(string key) {
        if (countMap[key] == 0) return;
        int count = countMap[key]--;
        countSet[count].erase(key);
        if (countSet[count].empty()) {
            countSet.erase(count);
        }
        if (count > 1) {
            countSet[count - 1].insert(key);
        }
    }
    
    string getMaxKey() {
        return countSet.empty() ? "" : *countSet.rbegin()->second.begin();
    }
    
    string getMinKey() {
        return countSet.empty() ? "" : *countSet.begin()->second.begin();
    }

private:
    unordered_map<string, int> countMap;
    map<int, set<string>> countSet;
};