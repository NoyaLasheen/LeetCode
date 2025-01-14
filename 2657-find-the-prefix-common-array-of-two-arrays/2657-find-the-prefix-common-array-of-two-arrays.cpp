class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> pref_com_arr;
        unordered_map<int, int> freq;
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            freq[A[i]]++;
            freq[B[i]]++;

            if (freq[A[i]] == 2) count++;
            if (freq[B[i]] == 2 && B[i] != A[i]) count++;
            pref_com_arr.push_back(count);           
        }
        return pref_com_arr;
    }
};

