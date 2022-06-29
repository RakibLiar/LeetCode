class Solution {
public:
    int row,col;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool flag=false;
    bool vis[20][20];
    bool check(int x,int y){
        return 0<=x && x<row && 0<=y && y<col;
    }
    
    bool dfs(int x,int y,int sz, vector<vector<char>>& board, string word){
        if(!check(x,y))
            return false;
        if(board[x][y]!=word[sz])
            return false;
        //cout<<word[sz]<<board[x][y]<<endl;
        sz++;
        if(sz==word.size())
            return true;
        bool res = false;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            if(check(x+dx[i],y+dy[i]) && !vis[x+dx[i]][y+dy[i]])
                res |= dfs(x+dx[i],y+dy[i],sz,board,word);
        }
        vis[x][y]=0;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        row=board.size();
        col=board[0].size();
        bool res=false;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    memset(vis,0,sizeof(vis));
                    res = dfs(i,j,0,board,word);
                }
                if(res) break;
            }
            if(res) break;
        }
        return res;
    }
};