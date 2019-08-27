#include<iostream>
using namespace std;
char book[256];
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    // 记录s1拥有的珠子
    for(int i = 0; i < s1.length(); i++){
        book[s1[i]]++;
    }
    // s2上的珠子与book[]对比
    int no = 0;
    for(int i = 0; i < s2.length(); i++){
        if(book[s2[i]] > 0){
            book[s2[i]]--;
        }else{
            no++;
        }
        
    }
    // 判断是否满足
    if(no != 0) printf("No %d", no);
    else printf("Yes %d", s1.length()-s2.length());
    return 0;
}