#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char s1[10000], s2[10000];
int main(){
    cin.getline(s1, 10000);
    cin.getline(s2, 10000);
    int lens1 = strlen(s1);
    int lens2 = strlen(s2);
    bool flag[256] = {false};
    for(int i = 0; i < lens2; i++){
        flag[s2[i]] = true;
    }
    for(int i = 0; i < lens1; i++){
        if(!flag[s1[i]]){
            printf("%c", s1[i]);
        }
    }
    return 0; 
}