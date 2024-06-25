class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> greatestCandies;
        
        int greatest = *max_element(candies.begin(), candies.end());
        
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= greatest) {
                greatestCandies.push_back(true);
            } else {
                greatestCandies.push_back(false);
            }
        }
        
        return greatestCandies;
    }
};