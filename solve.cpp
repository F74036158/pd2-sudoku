#include<iostream>
#include"Sudoku.h"
using namespace std;
int main()
	{
	Sudoku ss;
	ss.ReadIn();//讀數讀
	ss.Solve();//解數獨
	return 0;
	}
