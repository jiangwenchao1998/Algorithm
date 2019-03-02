#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 10010

int main() {
    //��������
    string str;
    int intercepts[MAXSIZE];    //�����߶�
    int len = 0;    //��������
    getline(cin,str);
    istringstream ss(str);
    int x;
    while(ss >> x) intercepts[len++] = x;
    int resA = 0, resB = 0;
    int up[MAXSIZE], down[MAXSIZE];
    for (int i = 0; i < len; ++i) {
        up[i] = down[i] = 1;
        for (int j = 0; j < i; ++j) {
            //��½�����
            if (intercepts[i] <= intercepts[j])
                down[i] = max(down[i], down[j]+1);
            else {  //���������
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
 * ���ۣ�
 *  1.�����Ŀ��һ��������������صĵ�����������������ȡ��½����У���Ҫ��ȡ״̬ת�Ʒ���ʽ up[i] = max(up[i], up[j]+1)
 *  2.�ڶ��������������е�������Ҫ�䱸��ϵͳ���������������Ҽ�����������������С�, �����е����¾ͻ���������½�������
 */
