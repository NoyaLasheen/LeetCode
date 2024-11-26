#include <bits/stdc++.h>
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        if (n > 1 && edges.size() == 0) return -1;
        
        set<int> numberSet;
        
        for (int i = 0; i < n; ++i) {
            numberSet.insert(i);
        }
        
        for (int i = 0; i < edges.size() && edges.size() > 0; i++) {
            numberSet.erase(edges[i][1]);   
        }
        
        
        if (numberSet.size() == 1) {
            return *numberSet.begin();
        }
        
        return -1;
    }
};