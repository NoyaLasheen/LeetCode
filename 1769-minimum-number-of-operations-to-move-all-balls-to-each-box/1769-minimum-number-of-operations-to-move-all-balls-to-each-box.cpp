class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        int sum=0;
        int right_ones=0;
        for(int i=0;i<n;++i)
            if(boxes[i]=='1'){
                sum += i;
                right_ones++;
            }
        
        vector<int> res(n);
        int prefix_sum=0;
        int left_ones=0;
        for(int i=0;i<n;++i){
            int moves = sum + prefix_sum;
            res[i]=moves;

            if(boxes[i]=='1'){
                left_ones++;
                right_ones--;
            }
            prefix_sum += left_ones;
            sum -= right_ones;
        }
        return res;
    }
};