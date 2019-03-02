/**
 * 问题描述
 * 我们可以把由“0”和“1”组成的字符串分为三类：全“0”串称为B串，全“1”串称为I串，既含“0”又含“1”的串则称为F串。FBI树是一种二叉树，它的结点类型也包括F结点，B结点和I结点三种。由一个长度为2N的“01”串S可以构造出一棵FBI树T，递归的构造方法如下：
 * 1)T的根结点为R，其类型与串S的类型相同；
 * 2)若串S的长度大于1，将串S从中间分开，分为等长的左右子串S1和S2；由左子串S1构造R的左子树T1，由右子串S2构造R的右子树T2。
 * 现在给定一个长度为2N的“01”串，请用上述构造方法构造出一棵FBI树，并输出它的后序遍历序列。
 * 输入格式
 * 第一行是一个整数N（0 <= N <= 10），第二行是一个长度为2N的“01”串。
 * 输出格式
 * 包括一行，这一行只包含一个字符串，即FBI树的后序遍历序列。
 * 样例输入
 * 3
 * 10001011
 * 样例输出
 * IBFBBBFIBFIIIFF
 * 数据规模和约定
 *    对于40%的数据，N <= 2；
 *    对于全部的数据，N <= 10。
 *  注：
 *    [1] 二叉树：二叉树是结点的有限集合，这个集合或为空集，或由一个根结点和两棵不相交的二叉树组成。这两棵不相交的二叉树分别称为这个根结点的左子树和右子树。
 *    [2] 后序遍历：后序遍历是深度优先遍历二叉树的一种方法，它的递归定义是：先后序遍历左子树，再后序遍历右子树，最后访问根。
 */

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
