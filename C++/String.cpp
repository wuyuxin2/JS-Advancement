#include<cstdio>
#include<string.h>
using namespace std;
int book[10];
int main(){
    char num[22];
    scanf("%s", num);
    int len = strlen(num); 
    int flag = 0; //是否有进位 
    for(int i = len-1; i >= 0; i--){
        int temp = num[i] -'0'; //转为int
        book[temp]++;
        temp = temp * 2 + flag; 
        flag = 0; //进位后，清零
        if(temp >= 10){
            temp = temp - 10;
            flag = 1;
        }
        num[i] = temp + '0'; //转为char
        book[temp]--; //此时为新的char
    }
    int flag1 = 0; //记录是否有book[i]不等于0
    for(int i = 0; i < 10; i++){
        if(book[i] != 0){
            flag1 = 1;
        }
    }
    printf("%s", (flag == 1 || flag1 == 1) ? "No\n":"Yes\n");
    if(flag == 1) printf("1");
    printf("%s", num);
    return 0;
}