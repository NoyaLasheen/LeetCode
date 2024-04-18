class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        Map <Integer, Integer> HM = new HashMap <> ();
        
        for (int i = 0; i< nums.length; i++){
            int compliment = target - nums[i];
            
            if (HM.containsKey(compliment)) {
                return new int[]{i, HM.get(compliment)};
            } else {
                HM.put(nums[i], i);
            }
        }
        return null;
    }
}