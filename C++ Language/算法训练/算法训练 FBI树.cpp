#include <iostream>
#include <cmath>
using namespace std;

//递归
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
	//左子树
    string strA = str.substr(0, str.length()/2);
    string left = FBI(strA);
	//右子树
    string strB = str.substr(str.length()/2, str.length());
    string right = FBI(strB);
	//节点
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
