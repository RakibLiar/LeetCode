class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> prefix(boxes.size(), 0), postfix(boxes.size(), 0), result(boxes.size(), 0);
        int cumsum = 0, n = boxes.size()-1;
        for(int i=1; i<boxes.size(); i++) {
            prefix[i] += (boxes[i-1]-'0');
            prefix[i] += cumsum;
            prefix[i] += prefix[i-1];
            cumsum += (boxes[i-1] - '0');
        }
        cumsum = 0;
        for(int i=n-1; i>=0; i--) {
            postfix[i] += (boxes[i+1] - '0');
            postfix[i] += cumsum;
            postfix[i] += postfix[i+1];
            cumsum += (boxes[i+1] - '0');
        }
        for(int i=0; i<boxes.size(); i++) {
            cout<<prefix[i]<<" "<<postfix[i]<<endl;
            result[i] = prefix[i] + postfix[i];
        }
        return result;
    }
};