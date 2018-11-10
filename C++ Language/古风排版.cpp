/**
 * 中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。
 * 输入格式：
 * 输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。
 * 输出格式：
 * 按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）。
 */
#include <iostream>
using namespace std;

int main() {
    string str;     //字符串
    int num;        //每列显示字符数
    cin>>num;
    getchar();      //接受换行符
    getline(cin, str);
    int index = (str.length() + num - 1) / num, temp = 0;
    char all[num][index];
    for (int i = index - 1; i >= 0; i--) {
        for (int j = 0; j < num; j++) {
            if(temp < str.length())
                all[j][i] = str[temp++];
            else
                all[j][i] = ' ';
        }
    }
    for (int k = 0; k < num; k++) {
        for (int i = 0; i < index; i++)
            cout<<all[k][i];
        cout<<'\n';
    }
    return 0;
}