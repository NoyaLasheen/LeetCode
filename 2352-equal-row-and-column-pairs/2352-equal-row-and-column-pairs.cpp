class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map <string, int> arrays;
        
        for (int i = 0; i < grid.size(); i++) {
            string s = "";
            for (int j = 0; j < grid.size(); j++) {
                s += to_string(grid[i][j]);
                s += "*";
            }
            arrays[s]++;
        }
        
        int result = 0;
        
        for (int j = 0; j < grid.size(); j++) { 
            string s = "";
            for (int i = 0; i < grid.size(); i++) {
                s += to_string(grid[i][j]);
                s += "*";
            }
            result += arrays[s];
        }
        
        return result;
       
    }
};