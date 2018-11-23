/**
 * 以上是朋友圈中一奇葩贴：“2月14情人节了，我决定造福大家。第2个赞和第14个赞的，我介绍你俩认识…………咱三吃饭…你俩请…”。现给出此贴
 * 下点赞的朋友名单，请你找出那两位要请客的倒霉蛋。
 * 输入格式：
 *     输入按照点赞的先后顺序给出不知道多少个点赞的人名，每个人名占一行，为不超过10个英文字母的非空单词，以回车结束。一个英文句点
 *     .标志输入的结束，这个符号不算在点赞名单里。
 *  输出格式：
 *      根据点赞情况在一行中输出结论：若存在第2个人A和第14个人B，则输出“A and B are inviting you to dinner...”；若只有A没有B，
 *      则输出“A is the only one for you...”；若连A都没有，则输出“Momo... No one is for you ...”。
 */
#include <iostream>

using namespace std;

int main() {
    //至多只有14个人
    string name[1000];
    int num = 0;    //记录当前人数
    for (int i = 0; i < 1000; ++i) {
        cin >> name[i];
        if (name[i] == ".") {
            break;
        } else {
            num++;
        }
    }
    if (num >= 14) {
        cout << name[1] << " and " << name[13] << " are inviting you to dinner...";
    } else if (num >= 2) {
        cout << name[1] << " is the only one for you...";
    } else {
        cout << "Momo... No one is for you ...";
    }
    /**
     * 结论：
     *      1. 要注意审题.
     *      2. 要注意系统测试用例的长度，尽可能将 name 数组变长.
     */
}
