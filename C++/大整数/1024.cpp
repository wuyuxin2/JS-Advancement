#include<iostream>
#include<algorithm>
using namespace std;

string s;
void add(string t){
    int len = s.length(), flag = 0;
    for(int i = 0; i < len; i++){
        s[i] = s[i] + t[i] + flag - '0';
        flag = 0;
        if(s[i] > '9'){
            s[i] = s[i] - 10;
            flag = 1;
        }
    }
    if(flag) s += '1';
    reverse(s.begin(), s.end());
}

int main(){
    int cnt, i;
    cin >> s >> cnt;
    for(i = 0; i <= cnt; i++){
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t || i == cnt) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}