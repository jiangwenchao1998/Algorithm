/**
 * 问题描述:
 * 	  给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。
 * 输入格式:
 *	  输入的第一行为一个整数n，表示棋盘的大小。
 *    接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
 * 输出格式:
 *    输出一个整数，表示总共有多少种放法。
 * 样例输入:
 *    4
 *    1 1 1 1
 *    1 1 1 1
 *    1 1 1 1
 *    1 1 1 1 
 * 样例输出:
 *    2
 */
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int n;		//棋盘大小 
int wq[10], bq[10];		//黑皇后与白皇后在棋盘的第 pos 行 的  wq[pos] 与 bq[pos] 列 
int map[10][10];		//期盼的各个位置,如果一个整数为1,表示对应的位置可以放皇后，如果一个整数为0,表示对应的位置不可以放皇后。
int count = 0;			//方法数 

void blackQueen(int pos) {
	int i, j;
	for (i = 0; i < pos - 1; i++)		//判断在同一行、同一列或同一条对角线上是否可以放置皇后，如果不可以则回溯上一层循环  blackQueen(pos - 1)
		if (bq[i] == bq[pos - 1] || abs(bq[i]- bq[pos - 1]) == abs(pos - 1 - i))
			return;
	if (pos == n) {		//如果 n 个黑皇后放置完成，则开始计数。
		count++;
		return;			//回溯上一层继续寻找可以放置皇后的位置 
	}
	for (j = 0; j < n; j++)			//循环判断是否可以放置皇后
		if (wq[pos] != j && map[pos][j] == 1) {	//注意条件白皇后的位置 
			bq[pos] = j;			//赋予第 pos 个皇后在 第 pos 行的位置 
			blackQueen(pos + 1);	//继续放置下一个皇后
		}
}

void whiteQueen(int pos) {
	int i, j;
	for (i = 0; i < pos - 1; i++)
		if (wq[i] == wq[ pos - 1] || abs(wq[i] - wq[pos - 1]) == abs(pos -1 - i))	//判断在同一行、同一列或同一条对角线上是否可以放置皇后，如果不可以则回溯上一层循环  whiteQueen(pos - 1)
			return;
	if(pos == n) {		//如果 n 个白皇后放置完成，则开始放置黑皇后。 
		blackQueen(0);
		return;
	}
	for (j = 0; j < n; j++)			//循环判断是否可以放置皇后 
		if (map[pos][j] == 1) {		// 如果  map[pos][j] 为 1 可以放置皇后，如果为 0，则不可以 
			wq[pos] = j;			//赋予第 pos 个皇后在 第 pos 行的位置 
			whiteQueen(pos + 1);	//继续放置下一个皇后 
		}
}

int main() {
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> map[i][j];
	whiteQueen(0);
	cout << count << endl;
}
/**
 * 结论:
 *        整个算法思路是先放置白皇后的位置，其中判断该位置的同一行、同一列或同一条对角线上是否可以放置皇后，如果不能则回溯，如果 n 个白皇后放置完成则开始
 *    放置黑皇后，黑皇后的放置方法同白皇后一样，只是在放置完成后，是开始计数，后回溯上一层寻找新的方法。 整个 2n 皇后问题 就是使用回溯，先放置白皇后，再
 *    放置黑皇后，其中增加判断该位置是否可以放置。 
 */ 

