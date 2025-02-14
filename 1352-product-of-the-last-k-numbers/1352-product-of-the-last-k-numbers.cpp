class ProductOfNumbers {
public:
    vector<int> v = {0};
    int zero = 0;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) zero = v.size();
        if (v.back()) {
            v.push_back(v.back() * num);
        } else {
            v.push_back(num);
        }
    }
    
    int getProduct(int k) {
        int n = v.size() - 1;
        if (zero > n - k) return 0;
        else {
            if (v[n - k] == 0) return v.back();
            else return v.back() / v[n - k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */