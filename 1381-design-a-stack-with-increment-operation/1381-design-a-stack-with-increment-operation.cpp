class CustomStack {
    
    vector<int> stack;
    int maxSize; 
    int currSize;
    
public:
    
    CustomStack(int maxSize) {        
        this->maxSize = maxSize;
        currSize = 0;
    }
    
    void push(int x) {
        if (currSize == maxSize) // overflow
            return;
        
        stack.push_back(x);
        currSize++;    
        
        
    }
    
    int pop() {
        
        if (currSize == 0) // underflow
            return -1;
        
        int top = stack.back();
        stack.pop_back();
        currSize--;
        return top;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, currSize); i++) {
            stack[i] += val;
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