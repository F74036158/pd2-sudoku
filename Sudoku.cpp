#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include"Sudoku.h"
using namespace std;
void Sudoku::GiveQuestion()
	{
	srand((unsigned)time(NULL));
	int a,b,c,d,e,f,g,h,i,j,k,l;
	a=rand()%9+1;
	b=rand()%9+1;
	while(b==a)
		b=rand()%9+1;
	c=rand()%9+1;
	while(c==a||c==b)
		c=rand()%9+1;
	d=rand()%9+1;
	while(d==a||d==b||d==c)
		d=rand()%9+1;
	e=rand()%9+1;
	while(e==a||e==b||e==c||e==d)
		e=rand()%9+1;
	f=rand()%9+1;
	while(f==a||f==b||f==c||f==d||f==e)
		f=rand()%9+1;
	g=rand()%9+1;
	while(g==a||g==b||g==c||g==d||g==e||g==f)
		g=rand()%9+1;
	h=rand()%9+1;
	while(h==a||h==b||h==c||h==d||h==e||h==f||h==g)
		h=rand()%9+1;
	i=rand()%9+1;
	while(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h)
		i=rand()%9+1;
	int aa[12][12]={{0,0,i,0,0,0,-1,-1,-1,b,0,0},
			{0,0,0,c,0,0,-1,-1,-1,h,0,g},
			{0,b,0,0,g,0,-1,-1,-1,0,0,d},
			{-1,-1,-1,0,0,0,0,0,0,0,b,0},
			{-1,-1,-1,0,0,f,0,0,0,g,0,0},
			{-1,-1,-1,a,0,0,0,h,i,0,e,0},
			{0,0,0,0,i,g,0,0,d,-1,-1,-1},
			{0,i,g,e,0,0,b,c,a,-1,-1,-1},
			{e,0,0,b,c,a,0,i,g,-1,-1,-1},
			{c,a,b,-1,-1,-1,0,d,e,i,g,0},
			{0,0,0,-1,-1,-1,0,a,b,f,d,0},
			{f,d,e,-1,-1,-1,i,g,0,0,a,0}};
	l=rand()%2;
	if(l==1)
		{
		for(j=0;j<12;j++)
                	{
                	for(k=0;k<12;k++)
                        	map[j][k]=aa[j][k];
        		}
		}
	else
		{
		for(j=0;j<12;j++)
                        {
                        for(k=0;k<12;k++)
                                map[j][k]=aa[k][j];
                        }
		}
	for(j=0;j<12;j++)
		{
		for(k=0;k<12;k++)
			cout<<setw(2)<<map[j][k];
		cout<<endl;
		}
	}
void Sudoku::ReadIn()
	{
	int a,b;
	for(a=0;a<12;a++)
                {
                for(b=0;b<12;b++)
                        cin>>map[a][b];
                }
	}
int Sudoku::compare(int a,int b,int c)
	{
	int l,m,n=(a/3)*3+3,o=(b/3)*3+3;
	for(l=0;l<12;l++)
		{
		if(map[l][b]==c)
			return 0;
		if(map[a][l]==c)
			return 0;
		}
	
	for(l=(a/3)*3;l<n;l++)
		{
		for(m=(b/3)*3;m<o;m++)
			{
			if(map[l][m]==c)
				return 0;
			}
		}
	return 1;
	}
void Sudoku::Solverec()
	{
	int a,b,c,t=0;
	for(a=0;a<12;a++)
		{
		for(b=0;b<12;b++)
			{
			if(map[a][b]!=0)
				t++;
			}
		}
	if(t==144)
		{
		ans++;
		for(a=0;a<12;a++)
			{
			for(b=0;b<12;b++)
				mapans[a][b]=map[a][b];
			}
		if(ans>=2)
			return;
		}
	for(a=0;a<12;a++)
		{
		for(b=0;b<12;b++)
			{
			if(map[a][b]==0)
				{
				for(c=1;c<10;c++)
					{
					if(compare(a,b,c)==1)
						{
						map[a][b]=c;
						Solverec();
						map[a][b]=0;
						if(ans>=2)
							return;
						}
					}
				return;
				}
			}
		}
	}
void Sudoku::Solve()
	{
	int a,b;
	ans=0;
	Solverec();
	if(ans==0)
		cout<<"0"<<endl;
	if(ans==1)
		{
		cout<<"1"<<endl;
		for(a=0;a<12;a++)
			{
				for(b=0;b<12;b++)
					cout<<setw(2)<<mapans[a][b];
				cout<<'\n';
			}
		}
	if(ans==2)
		cout<<"2"<<endl;
	}

