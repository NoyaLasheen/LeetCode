class ProductOfNumbers {
    vector<int> stream = {1};
    int n;
    int idx_0;
public:
    ProductOfNumbers() {
        n = 1;
        idx_0 = -1;
    }
    
    void add(int num) {
        if (num == 0) idx_0 = n;

        if (stream.back() == 0) stream.push_back(num);
        else stream.push_back(num * stream.back());
        n++;
    }
    
    int getProduct(int k) {
        if (idx_0 >= n - k) return 0;
        if (stream[n - k - 1] == 0) return stream[n - 1];
        return stream[n - 1] / stream[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */