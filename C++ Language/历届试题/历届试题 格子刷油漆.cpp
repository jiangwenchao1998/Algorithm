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
	//特殊情况
    if (n == 1)  sum = 2;
    cout << sum <<endl;

    return 0;
}
