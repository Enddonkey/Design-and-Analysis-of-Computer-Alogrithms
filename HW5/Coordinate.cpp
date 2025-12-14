#include<bits/stdc++.h>
using namespace std;
int T,n,m;
bool book[10],flag;
char directions[5]={'U','D','L','R'};
int cnt[10],d[10];
int dx[6]={0,0,0,-1,1,0};
int dy[6]={0,1,-1,0,0,0};
int start_x=0, start_y=0;
bool cheak(){
    int x=0,y=0;
    for(int i=1;i<=4;++i){
        int dir=d[i];
        for(int j=1;j<=cnt[dir];++j){
            x+=dx[dir];
            y+=dy[dir];
            if(x==n&&y==m) return false;
        }
    }
    for(int i=1;i<=4;++i){
        for(int j=1;j<=cnt[d[i]];++j){
            printf("%c",directions[d[i]-1]);
        }
    }
    printf("\n");
    flag=1;
    return true;
}
string s;
bool dfs(int step){
    if(flag) return true;
    if(step==4){
      if(cheak()) return true;
    }
    for(int i=1;i<=4;++i){
        if(!book[i]){
            book[i]=1;
            d[step+1]=i;
            if(dfs(step+1)) return true;
            book[i]=0;
        }
    }
    return false;
}
int main(){
    scanf("%d",&T);
    while(T--){
        start_x=0, start_y=0;flag=0;
        memset(book,0,sizeof(book));
        memset(cnt,0,sizeof(cnt));
        memset(d,0,sizeof(d));
        scanf("%d %d",&n,&m);
        cin >> s;
        int length = s.size();
        int tmpx=0,tmpy=0;
        for(int i=0;i<length;++i){
            if(s[i]=='U') cnt[1]++,tmpy++;
            else if(s[i]=='D') cnt[2]++,tmpy--;
            else if(s[i]=='L') cnt[3]++,tmpx--;
            else if(s[i]=='R') cnt[4]++,tmpx++;
        }
        if(n==0&&m==0||n==tmpx&&m==tmpy){
            printf("Impossible\n");
            continue;
        } 
        if(!dfs(0)) printf("Impossible\n");
    }

    return 0;
}