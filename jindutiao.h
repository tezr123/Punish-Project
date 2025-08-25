#ifndef JINDUTIAO_H
#define JINDUTIAO_H

#include<cstdio>
#include<iostream>
#include<vector>
#include<random>
#include<string>
#include<conio.h>
#include<windows.h>
using namespace std;
class LittleTools
{
	public:
		//更精准的Sleep() 
		void HpSleep(int ms)
		{
			static clock_t oldclock = clock();		// 静态变量，记录上一次 tick
			oldclock += ms * CLOCKS_PER_SEC / 1000;	// 更新 tick
			if (clock() > oldclock)					// 如果已经超时，无需延时
				oldclock = clock();
			else
			while (clock() < oldclock)				// 延时
			Sleep(1);								// 释放 CPU 控制权，降低 CPU 占用率
		}
		
		void Sout(string n,int sudu) //减速输出 
		{
			for (int i = 0; i < n.size(); i++)
			{
				cout << n[i];
				HpSleep(sudu);
			}
		}
		
		void hidden() //遮挡 
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_CURSOR_INFO CursorInfo; GetConsoleCursorInfo(handle, &CursorInfo);
			CursorInfo.bVisible = false;
			SetConsoleCursorInfo(handle, &CursorInfo);
		}
		
		void DIYpause(string n) //自定义system("pause") 
		{
			hidden();
			cout<<n<<endl;
			_getch();
			system("cls");
		}
};
LittleTools lt,littlegongju;
class JinDuTiao
{
	public:
		void Jindutiao(int wait_time,int OK_wait_time,int tiao_guo_bai_fen_bi,int more_number,char non_OK_icon,char OK_icon,string text,string mode)
		//wait_time是过每个百分比时要等待的时间(ms)
		//OK_wait_time是完成之后要等待的时间(ms) 
		/*text是进度条显示的内容:当输入为"加载"时为"已加载 %"(mode为more时为 / ),
		当输入为"文件"时为" 共 个文件，已加载 个文件"，
		当输入为" "时，输出为" %"， 
		当输入的为其它的字，为"你输入的字符+ %*/
		//mode为模式，有"low" "fast" "more"三种
		/*tiao_guo_bai_fen_bi是当模式为fast时，每“过每个百分比时要等待的时间(ms)”时,
		 跳过tiao_guo_bai_fen_bi个百分比(当模式不为fast时，不用管)*/ 
		//more_number为当mode为more时的最高进度 (当模式不为more时，不用管)
		//non_OK_icon是还没完成的进度条样式，为一个字符（当输入为' '时，为默认的'□'） 
		//OK_icon是已经完成的进度条样式，为一个字符（当输入为' '时，为默认的'■'） 
		//当输入的内容不符合时，函数直接返回 
		{
			int jindu=100,j,k,jindu_d,i,jindu_1,jindu_2,jindu_3,jindu_4,jindu_5,bfb;
			if(text=="加载")
			{
				if(mode=="low")
				{
					for(j=1;j<=jindu;j++)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<"已加载"<<j<<"%"<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<"已加载"<<jindu<<"%"<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="fast")
				{
					j=0;
					if(jindu%tiao_guo_bai_fen_bi!=0)
						j+=(jindu%tiao_guo_bai_fen_bi);
					for(;j<=jindu;j+=tiao_guo_bai_fen_bi)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<"已加载"<<j<<"%"<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<"已加载"<<jindu<<"%"<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="more")
				{
					jindu=more_number;
					i=0;
					bfb=0;
					if(jindu%5!=0) i+=(jindu%5);
					jindu_1=(jindu-i)/5*1;
					jindu_2=(jindu-i)/5*2;
					jindu_3=(jindu-i)/5*3;
					jindu_4=(jindu-i)/5*4;
					jindu_5=(jindu-i)/5*5;
					for(;i<=jindu;i++)
					{
						if(i<=jindu_1)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_1&&i<=jindu_2)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_2&&i<=jindu_3)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_3&&i<=jindu_4)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_4&&i<=jindu_5)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}
						else break;
						cout<<bfb<<'/'<<jindu<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<jindu<<'/'<<jindu<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				} 
				else return; 
			}
			if(text=="文件")
			{
				if(mode=="low")
				{
					for(j=1;j<=jindu;j++)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<"共"<<jindu<<"个文件，已加载"<<j<<"个"<<endl; 
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<"共"<<jindu<<"个文件，已加载"<<j<<"个"<<endl; 
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="fast")
				{
					j=0;
					if(jindu%tiao_guo_bai_fen_bi!=0)
						j+=(jindu%tiao_guo_bai_fen_bi);
					for(;j<=jindu;j+=tiao_guo_bai_fen_bi)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<"共"<<jindu<<"个文件，已加载"<<j<<"个"<<endl; 
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<"共"<<jindu<<"个文件，已加载"<<j<<"个"<<endl; 
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="more")
				{
					jindu=more_number;
					i=0;
					if(jindu%5!=0) i+=(jindu%5);
					jindu_1=(jindu-i)/5*1;
					jindu_2=(jindu-i)/5*2;
					jindu_3=(jindu-i)/5*3;
					jindu_4=(jindu-i)/5*4;
					jindu_5=(jindu-i)/5*5;
					for(;i<=jindu;i++)
					{
						if(i<=jindu_1)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(i>jindu_1&&i<=jindu_2)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(i>jindu_2&&i<=jindu_3)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(i>jindu_3&&i<=jindu_4)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(i>jindu_4&&i<=jindu_5)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<"共"<<jindu<<"个文件，已加载"<<i<<"个"<<endl; 
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<"共"<<jindu<<"个文件，已加载"<<i<<"个"<<endl; 
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				} 
				else return; 
			}
			if(text==" ")
			{
				if(mode=="low")
				{
					for(j=1;j<=jindu;j++)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<j<<"%"<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<jindu<<"%"<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="fast")
				{
					j=0;
					if(jindu%tiao_guo_bai_fen_bi!=0)
						j+=(jindu%tiao_guo_bai_fen_bi);
					for(;j<=jindu;j+=tiao_guo_bai_fen_bi)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<j<<"%"<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<jindu<<"%"<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="more")
				{
					jindu=more_number;
					i=0;
					bfb=0;
					if(jindu%5!=0) i+=(jindu%5);
					jindu_1=(jindu-i)/5*1;
					jindu_2=(jindu-i)/5*2;
					jindu_3=(jindu-i)/5*3;
					jindu_4=(jindu-i)/5*4;
					jindu_5=(jindu-i)/5*5;
					for(;i<=jindu;i++)
					{
						if(i<=jindu_1)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_1&&i<=jindu_2)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_2&&i<=jindu_3)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_3&&i<=jindu_4)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_4&&i<=jindu_5)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}
						else break;
						cout<<bfb<<'/'<<jindu<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<jindu<<'/'<<jindu<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}  
				else return; 
			}
			else
			{
				if(mode=="low")
				{
					for(j=1;j<=jindu;j++)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<text<<j<<"%"<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<text<<jindu<<"%"<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="fast")
				{
					j=0;
					if(jindu%tiao_guo_bai_fen_bi!=0)
						j+=(jindu%tiao_guo_bai_fen_bi);
					for(;j<=jindu;j+=tiao_guo_bai_fen_bi)
					{
						if(j<=20)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>20&&j<=40)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>40&&j<=60)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>60&&j<=80)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}	
						else if(j>80&&j<=99)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
						}
						else break;
						cout<<text<<j<<"%"<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<text<<jindu<<"%"<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				}
				if(mode=="more")
				{
					jindu=more_number;
					i=0;
					bfb=0;
					if(jindu%5!=0) i+=(jindu%5);
					jindu_1=(jindu-i)/5*1;
					jindu_2=(jindu-i)/5*2;
					jindu_3=(jindu-i)/5*3;
					jindu_4=(jindu-i)/5*4;
					jindu_5=(jindu-i)/5*5;
					for(;i<=jindu;i++)
					{
						if(i<=jindu_1)
						{
							if(non_OK_icon==' ') cout<<"□□□□□"<<endl;	
							else
							{
								for(k=0;k<5;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_1&&i<=jindu_2)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<1;k++) cout<<"■";	
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<1;k++) cout<<"■";
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<1;k++) cout<<OK_icon;
								for(k=0;k<4;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_2&&i<=jindu_3)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<2;k++) cout<<"■";	
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<2;k++) cout<<"■";
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<2;k++) cout<<OK_icon;
								for(k=0;k<3;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_3&&i<=jindu_4)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<3;k++) cout<<"■";	
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<3;k++) cout<<"■";
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<3;k++) cout<<OK_icon;
								for(k=0;k<2;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}	
						else if(i>jindu_4&&i<=jindu_5)
						{
							if(non_OK_icon==' '&&OK_icon==' ') 
							{
								for(k=0;k<4;k++) cout<<"■";	
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon==' '&&OK_icon!=' ')
							{
								
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<"□";
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon==' ')
							{
								for(k=0;k<4;k++) cout<<"■";
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							else if(non_OK_icon!=' '&&OK_icon!=' ')
							{
								for(k=0;k<4;k++) cout<<OK_icon;
								for(k=0;k<1;k++) cout<<non_OK_icon;
								cout<<endl;
							}
							bfb++;
						}
						else break;
						cout<<text<<bfb<<'/'<<jindu<<endl;
						littlegongju.HpSleep(wait_time);
						system("cls");
					}
					if(OK_icon==' ') cout<<"■■■■■"<<endl;	
					else
					{
						for(k=0;k<5;k++) cout<<OK_icon;
						cout<<endl;
					}
					cout<<text<<jindu<<'/'<<jindu<<endl;
					littlegongju.HpSleep(OK_wait_time);
					system("cls");
					return;
				} 
				else return; 
			}		
		}
};
JinDuTiao jindutiao;

#endif 
