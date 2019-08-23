#include<iostream>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int temp;
    int a[1001];
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        a[temp]++;
    }
    for(int i = 0; i < 1001; i++){
        if(a[i]){
            a[i]--;
            if(m > i && a[m-i]){
                printf("%d %d", i, m-i);
                return 0; 
            }
            a[i]++;
        }
    }
    printf("No solution");
    return 0;
}