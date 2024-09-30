class CustomStack {
public:
    deque<int> dq;
    int mx;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if (dq.size() < mx) {
            dq.push_front(x);
        }
    }
    
    int pop() {
        if (dq.empty()) return -1;
        int temp = dq.front();
        dq.pop_front();
        return temp;
    }
    
    void increment(int k, int val) {
        for (int i = dq.size() - 1; i >= 0 && k > 0; i--) {
            dq[i] += val;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */