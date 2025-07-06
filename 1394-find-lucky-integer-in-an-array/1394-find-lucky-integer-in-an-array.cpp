class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int lucky_int = -1;
        for (int i : arr) freq[i]++;
        for (auto &pair : freq) {
            if ((pair.first == pair.second) && pair.first > lucky_int) lucky_int = pair.first;
        }
        return lucky_int;
    }
};