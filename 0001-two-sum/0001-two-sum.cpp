class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> array;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if((i != j) && ((nums[i] + nums[j]) == target))
                {
                    
                    array.push_back(i);
                    array.push_back(j);
                    break;
                    
                }
            }
        }
        array.resize(2);
        return array; 
               
    }
};