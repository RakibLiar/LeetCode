class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i=1; i<=9; i++) {
            int num = 0;
            for(int j=i; j<10; j++) {
                num = 10*num + j;
                if(low <= num && num <= high)
                    result.push_back(num);
                if(num > high) break;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};