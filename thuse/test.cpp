//
// Created by admin on 2021/6/8.
//

using namespace std;
#include <iostream>

int main(){
    long long a,b;
    char c;
    cin >> a>>c>> b;
    switch (c) {
        case '+':
            cout << a+b;
            break;
        case '-':
            cout << a-b;
            break;
        case '*':
            cout << a*b;
            break;
    }
}