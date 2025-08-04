class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int firstValue, secondValue, firstCount = 0, secondCount = 0, maxValue = 0;
        for(int slow = 0, fast = 0; fast < fruits.size(); fast++) {
            if(firstCount == 0) {
                firstValue = fruits[fast];
                firstCount = 1;
            } else if(firstValue == fruits[fast]) {
                firstCount++;
            } else if(secondCount == 0) {
                secondValue = fruits[fast];
                secondCount = 1;
            }  else if(secondValue == fruits[fast]) {
                secondCount++;
            } else {
                maxValue = max(maxValue, firstCount + secondCount);
                while(firstCount != 0 && secondCount != 0) {
                    if(firstValue == fruits[slow]) firstCount--;
                    else secondCount--;
                    slow++;
                }
                if(firstCount == 0) {
                    firstValue = fruits[fast];
                    firstCount = 1;
                } else {
                    secondValue = fruits[fast];
                    secondCount = 1;
                }
            }
        }
        return maxValue = max(maxValue, firstCount + secondCount);
    }
};