# Algorithm
C/C++ · Java 等语言的算法的学习
## 库函数（算法学习中所遇到的库函数）
1. C++ Language
	* cout << setiosflags(ios::fixed) << setprecision(paraA) << paraB << endl;（作用：保留 paraB 的 paraA 位小数）
	* cout << setprecision(paraA) << paraB << endl;（作用：保留 paraB 的 paraA 位有效数字）
	* cout << setw(paraA) << setiosflags(ios::left/right) << paraB << endl;（作用：让 paraB 占 paraA 位字符的宽度，left：左对齐，right：右对齐）
	* strA.find(string/char strB);（作用：查找在字符串 strA 中字符串/字符 strB 第一次出现的位置，index 从 0 开始）
	* strA.find(string/char strB, int position);（作用，查找在字符串 strA 中从第 position 个字符开始，字符串/字符 strB 第一次出现的位置，index 从 0 开始）
	* str.erase(int position, int length);（作用：删除在字符串 strA 中从第 position 个字符开始 length 个字符，包括第 position 个字符）
	* str.substr(int position, int length);（作用：分割字符串 str 中从第 position 个字符开始的 length 个字符，组成新的字符串）
## 学习记录
1. C++ Language
	* [古风排版](https://github.com/jiangwenchao1998/Algorithm/blob/master/C%2B%2B%20Language/%E5%8F%A4%E9%A3%8E%E6%8E%92%E7%89%88.cpp)
	* [大笨钟](https://github.com/jiangwenchao1998/Algorithm/blob/master/C%2B%2B%20Language/%E5%A4%A7%E7%AC%A8%E9%92%9F.cpp)
	* [宇宙无敌加法器](https://github.com/jiangwenchao1998/Algorithm/blob/master/C%2B%2B%20Language/%E5%AE%87%E5%AE%99%E6%97%A0%E6%95%8C%E5%8A%A0%E6%B3%95%E5%99%A8.cpp)
	* [情人节](https://github.com/jiangwenchao1998/Algorithm/blob/master/C%2B%2B%20Language/%E6%83%85%E4%BA%BA%E8%8A%82.cpp)
	* [2n皇后](https://github.com/jiangwenchao1998/Algorithm/blob/master/C%2B%2B%20Language/2n%E7%9A%87%E5%90%8E.cpp)