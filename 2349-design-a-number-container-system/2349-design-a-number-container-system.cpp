class NumberContainers {
public:
    map<int, int> a;
    map<int, set<int>> b;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (a.count(index)) {
            int val = a[index];
            b[val].erase(index);
            if (b[val].size() == 0) {
                b.erase(val);
            }
        }
        a[index] = number;
        b[number].insert(index);
    }
    
    int find(int number) {
       if (b[number].size() == 0) return -1;
       return *b[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */