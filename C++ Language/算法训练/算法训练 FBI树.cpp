#include <iostream>
#include <cmath>
using namespace std;

string FBI(string str) {
    if (str.length() == 1) {
        switch (str[0]) {
            case '1':
                cout << "I";
                return "I";
            case '0':
                cout << "B";
                return "B";
            default:
                break;
        }
    }
    //二叉树后续遍历
    string strA = str.substr(0, str.length()/2);
    string left = FBI(strA);
    string strB = str.substr(str.length()/2, str.length());
    string right = FBI(strB);
    if (left.compare(right) == 0) {
        cout << left;
        return left;
    } else {
        cout << "F";
        return "F";
    }
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int len = (int) pow(2, n);
    FBI(str);
    return 0;
}
