/**
 * 地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。而在 PAT 星人开挂的世界里，每个数字的每一位都是不同进制的，这种
 * 神奇的数字称为“PAT数”。每个 PAT 星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是 7 进制数、第 2 位是 2 进制数、第
 * 3 位是 5 进制数、第 4 位是 10 进制数，等等。每一位的进制 d 或者是 0（表示十进制）、或者是 [2，9] 区间内的整数。理论上这个进
 * 制表应该包含无穷多位数字，但从实际应用出发，PAT 星人通常只需要记住前 20 位就够用了，以后各位默认为 10 进制。
 * 在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203 + 415”呢？我们得首先计算最低位：
 * 3 + 5 = 8；因为最低位是 7 进制的，所以我们得到 1 和 1 个进位。第 2 位是：0 + 1 + 1（进位）= 2；因为此位是 2 进制的，所以我
 * 们得到 0 和 1 个进位。第 3 位是：2 + 4 + 1（进位）= 7；因为此位是 5 进制的，所以我们得到 2 和 1 个进位。第 4 位是：6 + 1
 * （进位）= 7；因为此位是 10 进制的，所以我们就得到 7。最后我们得到：6203 + 415 = 7201。
 * 输入格式：
 *     输入首先在第一行给出一个 N 位的进制表（0 < N ≤ 20），以回车结束。 随后两行，每行给出一个不超过 N 位的非负的 PAT 数。
 * 输出格式：
 *     在一行中输出两个 PAT 数之和。
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string strA, strB, strC, res;    //strA - 进制表, strB 与 strC 为两个任意 PAT 数, res 为结果
    int carry = 0;  //进位
    int flag = 0; //判断是否为 0
    int temp = 0;
    //获取参数strA, strB, strC
    cin >> strA >> strB >> strC;
    res = strA;
    //拓展两个个字符串的长度与 strA 相等
    string ssB(strA.length() - strB.length(), '0');
    strB = ssB + strB;
    string ssC(strA.length() - strC.length(), '0');
    strC = ssC + strC;
    for ( int i = (strA.length() - 1); i >= 0; i--) {
        // 判断并将每个字符转化为 int 类型
        int mod = strA[i] == '0' ? 10 : (strA[i] - '0');    //进制数
        res[i] = (strB[i] - '0' + strC[i] - '0' + carry) % mod + '0';
        carry = (strB[i] - '0' + strC[i] - '0' + carry) / mod;

    }
    if (carry != 0) {
        res = '1' + res;
    }
    for ( int i = 0; i < res.size(); i++) {
            if(res[i] != '0' || flag == 1) {
                flag = 1;
                cout << res[i];
            }
    }
    //如果一个都没有输出，则输出 0
    if(flag == 0)
        cout << 0;
    return 0;
    /**
     * 结论：
     * 1. 两个 PAT 数的长度必须与 N 为进制表的长度相同.
     * 2. 计算出 mod（进制数）, 后计算进位（carry）和结果（res[i]）
     * 3. 在结束循环后，判断是否进位（carry）为 0, 如果不为 0， 则进一位 1.
     * 4. 设置 flag 让将res（结果）前面的零不要输出.
     * 5. 最后通过 flag 判断是否有输出，没有时输出 0.
     */
}
