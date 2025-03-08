class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minBlack = INT_MAX;
        int left = 0, right = 0, count = 0;

        for (; right < blocks.size(); right++) {
            if (blocks[right] == 'W') count++;
            if (right - left + 1 > k) {
                if (blocks[left++] == 'W') count--;
            } 
            if (right - left + 1 == k) {
                minBlack = min(minBlack, count);
            }
        }
        return minBlack;
    }
};