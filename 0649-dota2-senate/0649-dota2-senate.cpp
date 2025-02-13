class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq, rq;
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') rq.push(i);
            else dq.push(i);
        }

        int rIdx, dIdx;
        while (!dq.empty() && !rq.empty()) {
            rIdx = rq.front();
            rq.pop();
            dIdx = dq.front();
            dq.pop();
            
            if (rIdx < dIdx) {
                rq.push(rIdx + senate.length());
            } else {
                dq.push(dIdx + senate.length());
            }
        }

        if (!rq.empty()) return "Radiant";
        return "Dire";
    }
};