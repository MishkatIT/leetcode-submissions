class CustomStack {
public:
    vector<int> stack;
    int mx;
    int i = 0;
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        mx = maxSize;
    }
    
    void push(int x) {
        if (i < mx) {
            stack[i++] = x;
        }
    }
    
    int pop() {
        if (i == 0) return -1;
        return stack[--i];
    }
    
    void increment(int k, int val) {
        for (int j = 0; j <= min(mx - 1, i) && k--; j++) {
            stack[j] += val;
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