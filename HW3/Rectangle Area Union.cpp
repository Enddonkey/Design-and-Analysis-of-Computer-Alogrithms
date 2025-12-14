#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int N=1e5+10;
struct Event{
    long long x1,x2,y,type;
}events[N*2];
int n,tot;
long long a[N*2];
long long segtree[N*8],cover[N*8],ans=0;
bool cmp(Event a,Event b){
    return a.y<b.y;
}
int find(long long y){
    return lower_bound(a+1,a+tot+1,y)-a;
}
void update(int node,int nl,int nr){
    if(cover[node]>0) segtree[node]=a[nr+1]-a[nl];
    else if(nl==nr) segtree[node]=0;
    else segtree[node]=segtree[node*2]+segtree[node*2+1];
}
void add(int l,int r,long long type,int node,int nl,int nr){
    if(l<=nl&&nr<=r){
        cover[node]+=type;
    } else {
        int mid=(nl+nr)/2;
        if(l<=mid) add(l,r,type,node*2,nl,mid);
        if(r>mid) add(l,r,type,node*2+1,mid+1,nr);
    }
    update(node,nl,nr);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){  
        long long x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        events[2*i-1]={x1,x2,y1,1};
        events[2*i]={x1,x2,y2,-1};
        a[2*i-1]=x1;
        a[2*i]=x2;
    }   
    sort(a+1,a+2*n+1);
    tot=unique(a+1, a+2*n+1)-(a+1);
    
    sort(events+1,events+2*n+1,cmp);

    for(int i=1;i<=2*n;i++){
        if(i > 1) ans+=segtree[1]*(events[i].y-events[i-1].y);
        int l = find(events[i].x1);
        int r = find(events[i].x2)-1;
        if(l<=r) add(l,r,events[i].type,1,1,tot-1);
    }
    printf("%lld\n",ans);
    return 0;
}
