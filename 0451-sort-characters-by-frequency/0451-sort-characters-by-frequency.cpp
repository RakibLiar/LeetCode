struct node
    {
        int count,index;
        node()
        {
            count = 0;
            index = 0;
        }
    };
bool comp(node a, node b)
    {
        return a.count>b.count;
    }
class Solution {
public:
    
    string frequencySort(string s) {
        int i,j,a,b,c,len = s.size();
        struct node arr[300];
        string res;
        for(i=0;i<len;i++)
        {
            a = s[i];
            arr[a].index = a;
            arr[a].count++;
        }
        sort(arr,arr+300,comp);
        a=-1;
        while(arr[++a].count!=0)
        {
            for(i=0;i<arr[a].count;i++)
                res.push_back(arr[a].index);
        }
        return res;
    }
};