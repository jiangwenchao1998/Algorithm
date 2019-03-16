/**
     凑算式

         B      DEF
    A + --- + ------- = 10
         C      GHI

    这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

    比如：
    6+8/3+952/714 就是一种解法，
    5+3/1+972/486 是另一种解法。

    这个算式一共有多少种解法？

    注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int sum = 0;
    do {
        int a = arr[0], b = arr[1], c = arr[2], d = arr[3]*100 + arr[4]*10 + arr[5], e = arr[6]*100 + arr[7]*10 + arr[8];
        if (a*c*e + b*e +d*c == 10*c*e) {
            sum++;
        }
    }while (next_permutation(arr,arr+9) );
    cout << sum;
    return 0;
}
/**
 * 结论:
 *      1.全排列问题
 *      2.注意精度问题
 *      3.这道题还可以使用 DFS 算法
 */