class Solution {
    #define pii pair<int,int>
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();

        unordered_map<char,pii> first_last;
        for(int i=0;i<n;++i){
            if(!first_last.count(s[i]))
                first_last[s[i]].first = first_last[s[i]].second = i;
            else
                first_last[s[i]].second = i;
        }

        int count=0;
        for(auto [c,se]: first_last){
            if(se.first==se.second) continue;
            count += unordered_set<char>(s.begin()+se.first+1, s.begin()+se.second).size();
        }
        return count;
    }
};