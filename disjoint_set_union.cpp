#include <bits/stdc++.h>
using namespace std;

int parent[100001];
int size[100001];

void make_set(int x){
    parent[x] = x;
    size[x]=1;
}

//find the leader of the set with path compression.
int find_set(int x){
    if(x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

//union of 2 sets by size(merging smaller to the larger one)
void union_sets(int x,int y){
    x = find_set(x);
    y = find_set(y);
    if(x!=y){
        if(x<y) swap(x,y);
        parent[y] = x; //Making the parent pointer of smaller set y point to larger set x.
        size[x] += size[y];
    }
}

int main(){

    int n = 6;
    //(1,2,5) , (3,4) , (6)
    for(int i=1;i<=6;i++) make_set(i);

    union_sets(1,2);
    union_sets(1,5);
    union_sets(3,4);

    for(int i=1;i<=6;i++) cout<<find_set(i)<<" ";
    cout<<endl;
    
    return 0;
}