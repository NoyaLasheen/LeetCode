class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);
        res[n - 1] = prices[n - 1];
        stack<int> st;
        st.push(n - 1);
        
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }
            if (st.empty()) 
                res[i] = prices[i];
            else 
                res[i] = prices[i] - prices[st.top()];
            
            st.push(i);
        }
        return res;
    }
};