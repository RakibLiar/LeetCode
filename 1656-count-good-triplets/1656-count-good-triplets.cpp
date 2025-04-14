class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0;
        for(int j=1; j<arr.size()-1; j++) {
            for(int i=0; i<j; i++) {
                for(int k=j+1; k<arr.size(); k++) {
                    if(abs(arr[i]-arr[j]) <= a && abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};