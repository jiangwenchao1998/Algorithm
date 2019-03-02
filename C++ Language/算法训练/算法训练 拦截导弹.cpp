#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 10010

int main() {
    //输入数据
    string str;
    int intercepts[MAXSIZE];    //导弹高度
    int len = 0;    //导弹数量
    getline(cin,str);
    istringstream ss(str);
    int x;
    while(ss >> x) intercepts[len++] = x;
    int resA = 0, resB = 0;
    int up[MAXSIZE], down[MAXSIZE];
    for (int i = 0; i < len; ++i) {
        up[i] = down[i] = 1;
        for (int j = 0; j < i; ++j) {
            //最长下降序列
            if (intercepts[i] <= intercepts[j])
                down[i] = max(down[i], down[j]+1);
            else {  //最长上升序列
                up[i] = max(up[i], up[j]+1);
            }
        }
        resA = max(resA, down[i]);
        resB = max(resB, up[i]);
    }
    cout << resA << endl << resB << endl;
    return 0;
}

/**
 * 结论：
 *  1.这个题目第一个问题最多能拦截的导弹数，本质上是求取最长下降序列，需要求取状态转移方程式 up[i] = max(up[i], up[j]+1)
 *  2.第二个问题拦截所有导弹最少要配备的系统数，本质上是能找几条“最长非上升子序列”, 将序列倒置下就换成求最长非下降子序列
 */
