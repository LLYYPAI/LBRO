#pragma once
#define NUM1 128
#define NUM2 50
class Cbook {
public:
	Cbook() {};
	Cbook(char* cName, char* cIsbn, char* cPrice, char* cAuthor);
	~Cbook() {};
public:
	char* GetName();
	void SetName(char* cName);
	char* GetAuthor();
	void SetAuthor(char* cAuthor);
	char* GetPrice();
	void SetPrice(char* cPrice);
	char* GetIsbn();
	void SetIsbn(char* cIsbn);
	void WriteData();
	void DeleteData(int iCount);
	void GetBookFromFile(int icount);
protected:
	char m_cName[NUM1];
	char m_cIsbn[NUM1];
	char m_cPrice[NUM2];
	char m_cAuthor[NUM2];

};

