#pragma once
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include"Cbook.h"
#include<conio.h>
#include<iomanip>
#include<stdio.h>

#define CMD_COLS 80
#define CMD_LINES 20

using namespace std;

void SetScreenGrid();//设置显示的行数和列数
void ClearScreen();//清除屏幕信息
void SetSysCaption(const char* pText);//设置窗体标题栏
void ShowWelcome();//显示欢迎信息
void ShowRootMenu();//显示开始菜单
void WaitView(int iPage);//浏览数据等待用户操作
void WaitUser();//等待用户操作
void GuildInput();//使用向导添加图书信息
int GetSelect();//获得用户菜单选择
long GetFileLength(ifstream &ifs);//获取文件长度
void ViewData(int iSelPage);//获得所有的图书记录
void DeletBookFromFile();//从文件中产生图书信息
void mainloop();//主循环

