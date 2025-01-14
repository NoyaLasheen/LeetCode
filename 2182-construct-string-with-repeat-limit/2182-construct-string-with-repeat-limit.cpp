class Solution {
    #define pii pair<int,int>
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        string res;
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        priority_queue<pii> maxHeap;
        for (int i = 0; i < freq.size(); i++) {
            if(freq[i] > 0)
                maxHeap.push(make_pair(i, freq[i]));
        }

        while (!maxHeap.empty()) {
            pii curr = maxHeap.top();
            maxHeap.pop();
            int count = min(curr.second, repeatLimit);
            curr.second -= count;
            res.append(count, curr.first + 'a');

            if (curr.second > 0) {
                if (maxHeap.empty()) break;

                pii next = maxHeap.top();
                maxHeap.pop();
                res.push_back(next.first + 'a');
                next.second--;

                if(next.second > 0)
                    maxHeap.push(next);
                maxHeap.push(curr);
            }
        }
        return res;
    }
};