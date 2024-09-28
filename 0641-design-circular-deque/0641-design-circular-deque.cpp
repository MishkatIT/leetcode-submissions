class MyCircularDeque {
public:
    vector<int> dq;
    int i, j, cnt, k;
    MyCircularDeque(int k) {
        dq.resize(k);
        i = 0, j = 0;
        cnt = 0;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        dq[i] = value;
        i = (i - 1 + k) % k;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        j = (j + 1) % k;
        dq[j] = value;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        i = (i + 1) % k;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        j = (j - 1 + k) % k;
        cnt--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return dq[(i + 1) % k];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return dq[j];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */