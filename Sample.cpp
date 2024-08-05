#include "Sample.h"

void SetScreenGrid()
{
	char SysSetBuf[80];
	sprintf_s(SysSetBuf, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
	system(SysSetBuf);
}

void ClearScreen()
{
	system("cls");
}

void SetSysCaption()
{
	system("title Sample");
}

void ShowWelcome()
{
	for (int i = 0; i < 7; i++)
	{
		cout << endl;
		
	}
	cout << setw(40);
	cout << "**************" << endl;
	cout << setw(40);
	cout << "图书管理系统" << endl;
	cout << setw(40);
	cout << "**************" << endl;

	
}
void ShowRootMenu()
{
	
	cout << setw(38);
	cout << "请选择功能" << endl;
	cout << endl;
	cout << setw(38);
	cout << "1 添加图书";
	cout << endl;
	cout << setw(38);
	cout << "2 浏览全部";
	cout << endl;
	cout << setw(38);
	cout << "3 删除图书";
	cout << endl; cout << endl; cout << setw(35) << "请选择:";


}
void WaitView(int iPage)
{
	char buf[256];
	fgets(buf, sizeof(buf), stdin);
	if (buf[0] == 'q')
		system("exit");
	if (buf[0] == 'm')
		mainloop();
	if (buf[0] == 'n')
		ViewData(iPage);
}
void WaitUser()
{
	int ilinputPage = 0;
	cout << "enter返回主菜单q退出"<<endl;
	char buf[256];
	std::fgets(buf,sizeof(buf), stdin);
	if (buf[0] == 'q')
	{
		system("exit");
	}
}
void GuildInput()
{
	char inName[NUM1];
	char inIsbn[NUM1];
	char inAuthor[NUM2];
	char inPrice[NUM2];
	cout << "输入书名" << endl;
	cin >> inName;
	cout << "输入ISBN" << endl;
	cin >> inIsbn;
	cout << "输入价格" << endl;
	cin >> inPrice;
	cout << "输入作者" << endl;
	cin >> inAuthor;
	Cbook book(inName, inIsbn, inPrice, inAuthor);
	book.WriteData();
	cout<<"写入完成" << endl;
	WaitUser();
}
int GetSelect()
{
	char buf[256];
	fgets(buf, sizeof(buf), stdin);
	return atoi(buf);
}
long GetFileLength(ifstream& ifs)
{
	long tmppos;
	long respos;
	tmppos = ifs.tellg();
	ifs.seekg(0, ios::end);
	respos = ifs.tellg();
	ifs.seekg(tmppos, ios::beg);
	return respos;
}
void ViewData(int iSelPage = 1)
{
	int iPage = 0;
	int iCurPage = 0;
	int iDataCount = 0;
	char inName[NUM1];
	char inIsbn[NUM1];
	char inAuthor[NUM2];
	char inPrice[NUM2];
	bool bIndex = false;
	int iFileLength;
	iCurPage = iSelPage;
	ifstream ifile;
	ifile.open("book.dat", ios::binary);
	iFileLength = GetFileLength(ifile);
	
	iDataCount = iFileLength / (NUM1 + NUM1 + NUM2 + NUM2);
	if (iDataCount >= 1)
		bIndex = true;
	iPage = iDataCount / 20 + 1;
	ClearScreen(); 
	cout<<"共有记录" <<iDataCount<<"条"<<" ";
	cout << "共有页数" << iPage << "页" << " ";
	cout << "当前页数" << iCurPage << "页" << " ";
	cout << "n:显示下一页 m返回" << endl;
	cout << setw(5) << "Index";
	cout << setw(22) << "Name" << setw(22) << "Isbn";
	cout << setw(15) << "Price" << setw(15) << "Author";
	cout << endl;
	try
	{
		//printf("hgdsh");
		ifile.seekg((iCurPage - 1) * 20 * (NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
		//cout << ifile.fail() << endl;
		if (!ifile.fail())
		{
			//cout << "gggg";
			//printf("hgdsh");
			for (int i = 1; i < 21; i++)
			{
				memset(inName, 0, 128);
				memset(inIsbn, 0, 128);
				memset(inPrice, 0, 50);
				memset(inAuthor, 0, 50);
				if (bIndex)
					cout << setw(3) << (iCurPage - 1) * 20 + i;
				ifile.read(inName, NUM1);
				cout << setw(24) << inName;
				ifile.read(inIsbn, NUM1);
				cout << setw(24) << inIsbn;
				ifile.read(inPrice, NUM2);
				cout << setw(12) << inPrice;
				ifile.read(inAuthor, NUM2);
				cout << setw(12) << inAuthor;
				cout << endl;
				if (ifile.tellg() < 0)
					bIndex = false;
				else
					bIndex = true;	
			}
		}
		
	}
	catch (...)
	{
		cout << "throw file exception"<<endl;
		throw "file error occurred";
		ifile.close();
	}
	if (iCurPage < iPage)
	{
		iCurPage++;
		WaitView(iCurPage);
	}
	else
	{
		WaitView(iCurPage);
	}
	
	ifile.close();
}
void DeletBookFromFile()
{
	int iDeletCount;
	cout << "删除号码" << endl;
	cin >> iDeletCount;
	Cbook tmpbook;
	tmpbook.DeleteData(iDeletCount);
	cout << "删除完成" << endl;
	WaitUser();
}
void mainloop()
{
	ShowWelcome();
	while (1)
	{
		ClearScreen();
		ShowWelcome();
		ShowRootMenu();
		switch (GetSelect())
		{
		case 1:
			ClearScreen();
			GuildInput();
			break;
		case 2:
			ClearScreen();
			ViewData();
			break;
		case 3:
			ClearScreen();
			DeletBookFromFile();
			break;
		}
	}
}
void SetSysCaption(const char* pText)
{
	char SysSetBuf[80];
	sprintf_s(SysSetBuf,"title %s",pText);
	system(SysSetBuf);
}

