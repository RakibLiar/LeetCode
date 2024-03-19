class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char task: tasks) {
            freq[task-'A']++;
        }
        sort(freq.begin(), freq.end());
        int div = freq[25]-1;
        int idleTime = div * n;
        
        for(int i=24; i>=0; i--) {
            idleTime -= min(div, freq[i]);
        }
        
        return idleTime < 0 ? tasks.size() : tasks.size() + idleTime;
    }
};