#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N];
struct Node{
    int l,r,lmax,rmax,sum,maxn; 
}tree[N*4];
void pushup(int node){
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
    tree[node].lmax=max(tree[node*2].lmax,tree[node*2].sum+tree[node*2+1].lmax);
    tree[node].rmax=max(tree[node*2+1].rmax,tree[node*2+1].sum+tree[node*2].rmax);
    tree[node].maxn=max(max(tree[node*2].maxn,tree[node*2+1].maxn),tree[node*2].rmax+tree[node*2+1].lmax);
}
void build(int node ,int l,int r){
    tree[node].l=l;
    tree[node].r=r;
    if(l==r){
        tree[node].lmax=tree[node].rmax=tree[node].sum=tree[node].maxn=a[l];
        return;
    }else{
        int mid=(l+r)>>1;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        pushup(node);
    }
}
Node query(int node,int l,int r){
    if(tree[node].l>=l&&tree[node].r<=r){
        return tree[node];
    }
    int mid=(tree[node].l+tree[node].r)>>1;
    if(r<=mid) return query(node*2,l,r);
    else if(l>mid) return query(node*2+1,l,r);
    else{
        Node left=query(node*2,l,r);
        Node right=query(node*2+1,l,r);
        Node res;
        res.l=left.l;
        res.r=right.r;
        res.sum=left.sum+right.sum;
        res.lmax=max(left.lmax,left.sum+right.lmax);
        res.rmax=max(right.rmax,right.sum+left.rmax);
        res.maxn=max(max(left.maxn,right.maxn),left.rmax+right.lmax);
        return res;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        printf("%d\n",query(1,l,r).maxn);
    }
    return 0;
}