#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <float.h>
#define d_num 2
#define INF 9000000000000000000
using namespace std;
int currentd,root;
struct node_class{
    int value[d_num];
    int split;
    int left,right,father;
    int id;
} node[100010];
bool cmp(node_class a,node_class b){
    return a.value[currentd]<b.value[currentd];
}
bool cmp1(node_class a,node_class b){
    return a.id<b.id;
}
double calVarience(int l,int r,int d){
    double x2=0,xbar=0;
    for (int i = l;i<=r;i++){
        x2+=1LL*node[i].value[d]*node[i].value[d];
        xbar+=node[i].value[d];
    }
    xbar/=(r-l+1);
    return x2/(r-l+1)-xbar*xbar;
}
int build(int root,int l,int r){
    if (l>r) return 0;
    double max=-1;
    int d=0;
    for (int i = 0;i<d_num;i++){
        double tmpmax = calVarience(l,r,i);
        if (tmpmax>max){
            max = tmpmax;
            d = i;
        }
    }

    currentd = d;
    sort(node+l,node+r+1,cmp);
    int mid = (l+r)>>1;
    while(mid < r && node[mid].value[d] == node[mid+1].value[d])
        mid++;
    node[mid].split = d;
    node[mid].father = root;
    node[mid].left = build(mid,l,mid-1);
    node[mid].right = build(mid,mid+1,r);
    return mid;
}

long long calDistance(node_class a,node_class b){
    long long ans = 0;
    for (int i = 0;i<d_num;i++)
        ans+=1LL*(a.value[i]-b.value[i])*(a.value[i]-b.value[i]);
    return ans;
}
int stackNode[100010];
struct stack_struct{
    int size;
    void push(int x){
        stackNode[size++] = x;
    }
    void pop(){
        size--;
    }
    int top(){
        return stackNode[size-1];
    }
} searchStack;
long long currentNear;
int currentNode;
void downSearch(int root,node_class t){
    //if (!root) return ;
    searchStack.push(root);

    /**/
    long long tmpdis = calDistance(node[root],t);
    if (tmpdis>0) {
        if (currentNear > tmpdis) {
            currentNode = root;
            currentNear = tmpdis;
        }
        else if (currentNear == tmpdis){
            if (node[currentNode].value[0] > node[root].value[0])
                currentNode = root;
            else if (node[currentNode].value[0] == node[root].value[0] && node[currentNode].value[1] > node[root].value[1])
                currentNode = root;
        }
    }
    /**/

    int sonnode = 0, d = node[root].split; 
    if (node[root].value[d]>=t.value[d])
        sonnode = node[root].left;
    else sonnode = node[root].right;
    if (sonnode) downSearch(sonnode,t);
    else return;
}
void search(int root,node_class t){
    currentNear = INF;
    downSearch(root,t);

    while (searchStack.size){
        int topNode = searchStack.top();
        int d = node[topNode].split;
        searchStack.pop();
        long long cha = t.value[d]-node[topNode].value[d];
        if (cha*cha<=currentNear) {
            int sonnode = 0;
            if (t.value[d]<=node[topNode].value[d]) sonnode = node[topNode].right;
            else sonnode = node[topNode].left;
            downSearch(sonnode,t);
        }
    }
}
int main(){
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++){
        scanf("%d%d",&node[i].value[0],&node[i].value[1]);
        node[i].id = i;
    }
    int root = build(0,1,n);
    search(root,node[1]);
    cout<<currentNode<<endl;

    return 0;
}