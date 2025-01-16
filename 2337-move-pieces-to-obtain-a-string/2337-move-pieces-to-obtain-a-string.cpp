class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.length();
        while (i < n && j < n) {
            while (start[i] == '_') i++;
            while (target[j] == '_') j++;
            if (start[i] != target[j]) return false;
            if (start[i] == 'R') {
                if (j < i) return false;
                else i++, j++;
            } else if (start[i] == 'L') {
                if (j > i) return false;
                else i++, j++;
            }
        }

        while (i < n) {
            if (start[i] != '_') return false;
            i++;
        }
        while (j < n) {
            if (target[j] != '_') return false;
            j++;
        }
        return true;
    }
};