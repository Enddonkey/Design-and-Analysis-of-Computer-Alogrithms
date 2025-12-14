#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
    int y;
}; node a[100010];
node tmp[100010];
int n;
const double INF=1e22;
double ans=INF;
bool cmp_x(node point_1,node point_2){
    return point_1.x<point_2.x||(point_1.x==point_2.x&&point_1.y<point_2.y);
}
bool cmp_y(node point_1,node point_2){
    return point_1.y<point_2.y;
}
void updata_ans(node point_1,node point_2){
    double distance=sqrt((double)(point_1.x-point_2.x)*(point_1.x-point_2.x)+(double)(point_1.y-point_2.y)*(point_1.y-point_2.y));
    ans=min(ans,distance);
}
void get_ans(int l,int r){
    if(r-l<=3){
        for(int i=l;i<=r;++i){
            for(int j=i+1;j<=r;++j){
                updata_ans(a[i],a[j]);
            }
        }
        sort(a+l,a+r+1,&cmp_y);
        return;
    }
    int mid=(l+r)/2;
    int midx=a[mid].x;
    get_ans(l,mid);
    get_ans(mid+1,r);
    inplace_merge(a+l,a+mid+1,a+r+1,&cmp_y);
    int cnt=0;
    for(int i=l;i<=r;++i){
        if(abs(a[i].x-midx)<ans){
            for(int j=cnt-1;j>=0&&a[i].y-tmp[j].y<ans;--j){
                updata_ans(a[i],tmp[j]);
            }
            tmp[cnt++]=a[i];
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort(a+1,a+1+n,&cmp_x);
    get_ans(1,n);
    printf("%.8lf",ans);
    return 0;
}