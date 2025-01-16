class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int start = 0;
        int count = 0;
        for (int end = 0; end < fruits.size(); end++) {
            freq[fruits[end]]++;
            if (freq.size() > 2) {
                freq[fruits[start]]--;
                if (freq[fruits[start]] == 0) freq.erase(fruits[start]);
                start++;
            }
            count = max(count, end - start + 1);
        }
        return count;
    }
};