/**
 * 问题描述
 * X国的一段古城墙的顶端可以看成 2*N个格子组成的矩形（如下图所示），现需要把这些格子刷上保护漆。
 * 你可以从任意一个格子刷起，刷完一格，可以移动到和它相邻的格子（对角相邻也算数），但不能移动到较远的格子（因为油漆未干不能踩！）
 * 比如：a d b c e f 就是合格的刷漆顺序。
 * c e f d a b 是另一种合适的方案。
 * 当已知 N 时，求总的方案数。当N较大时，结果会迅速增大，请把结果对 1000000007 (十亿零七) 取模。
 */

#include <iostream>
using namespace std;

long long int a[1001] = { 0 };
long long int b[1001] = { 0 };
const int def = 1000000007; //取模运算
int main() {
    int i, n;
    cin >> n;
    b[1] = 1;
    for (i = 2; i <= n; i++)
        b[i] = (b[i - 1] * 2 % def);
    a[1] = 1; a[2] = 6;
    //从四角出发
    for (i = 3; i <= n; i++)
        a[i] = (2 * a[i - 1] + b[i] + 4 * a[i - 2]) % def;
    long long int sum = 4 * a[n];
    //从中间出发
    for (i = 2; i<n; i++) {
        sum += 2 * ((2 * b[n - i] * 2 * a[i - 1]) % def + (2 * a[n - i] * 2 * b[i - 1]) % def) % def;
        sum %= def;
    }
    if (n == 1)  sum = 2;
    cout << sum <<endl;

    return 0;
}
