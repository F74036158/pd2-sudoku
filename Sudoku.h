#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Sudoku
	{
	public:
		int compare(int,int,int);
		void GiveQuestion();
		void ReadIn();
		void Solverec();
		void Solve();
	private:
		int map[12][12],ans,mapans[12][12];
	};
