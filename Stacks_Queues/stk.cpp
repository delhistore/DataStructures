
#include <stack>
#include <iostream>
using namespace std;
int main(){
    stack<int> s;
    s.push(2);
    s.push(3);

    s.top() = 4;
    // 2 = 4;
}