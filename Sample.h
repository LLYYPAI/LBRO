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

void SetScreenGrid();//������ʾ������������
void ClearScreen();//�����Ļ��Ϣ
void SetSysCaption(const char* pText);//���ô��������
void ShowWelcome();//��ʾ��ӭ��Ϣ
void ShowRootMenu();//��ʾ��ʼ�˵�
void WaitView(int iPage);//������ݵȴ��û�����
void WaitUser();//�ȴ��û�����
void GuildInput();//ʹ�������ͼ����Ϣ
int GetSelect();//����û��˵�ѡ��
long GetFileLength(ifstream &ifs);//��ȡ�ļ�����
void ViewData(int iSelPage);//������е�ͼ���¼
void DeletBookFromFile();//���ļ��в���ͼ����Ϣ
void mainloop();//��ѭ��

