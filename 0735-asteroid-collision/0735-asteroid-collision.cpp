#include <cstdlib>
class Solution {
public:
    vector <int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int asteroid = asteroids[i];
            if (!st.empty() && st.top() > 0 && asteroid < 0) {
                if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                } else if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    i--;
                }
            } else {
                st.push(asteroid);
            }
        }
        
        vector <int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};