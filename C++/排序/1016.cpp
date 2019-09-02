#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
    string name;
    int status,month,time,day,hour,minute;
};
bool cmp(node a, node b){
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double billFromZero(node call, int *rate)