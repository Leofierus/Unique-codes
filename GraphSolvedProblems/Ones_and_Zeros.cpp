
//problem link
//https://www.spoj.com/problems/ONEZERO/

#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
 
typedef long long int LLD;
 
using namespace std;
 
queue< pair<LLD, int> > q;
pair<LLD, int> p;
 
LLD bfs(int n){
    bool visited[20000];
    fill(visited, visited + n, false);
    LLD res;
    q.push(make_pair(1, 1));
 
    while(!q.empty()){
        p = q.front();
        q.pop();
        visited[p.second] = true;
        if((p.second % n) == 0){
            res = p.first;
            break;
        } else{
            LLD tmp1 = p.first;
            tmp1 <<= 1;
            int modulo = (p.second * 10) % n;
            if(!visited[modulo])
                q.push(make_pair(tmp1, modulo));
            LLD tmp2 = p.first;
            tmp2 <<= 1;
            tmp2 |= 1;
            modulo = (p.second * 10 + 1) % n;
            if(!visited[modulo])
                q.push(make_pair(tmp2, modulo));
        }
    }
 
    while(!q.empty())
        q.pop();
 
    return res;
}
 
void display(LLD n){
    stack<int> s;
    while(n){
        s.push(n % 2);
        n >>= 1;
    }
    while(!s.empty()){
        printf("%d", s.top());
        s.pop();
    }
    printf("\n");
}
 
int main(){
    int t, n;
 
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        LLD result = bfs(n);
        display(result);
    }
    return 0;
} 
