#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
string a,b;
void tree_postorder(int l1,int r1,int l2,int r2){
    if(l1>r1) return;
    int root=b.find(a[l1]);
    tree_postorder(l1+1,l1+root-l2,l2,root-1);
    tree_postorder(l1+root-l2+1,r1,root+1,r2);
    printf("%c",a[l1]);
    return;
}
int main(){
    while((cin>>a>>b)){
        tree_postorder(0,a.length()-1,0,b.length()-1);
        printf("\n");
    }
    return 0;
}

