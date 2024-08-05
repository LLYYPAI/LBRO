#include "Cbook.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
Cbook::Cbook(char* cName, char* cIsbn, char* cPrice, char* cAuthor)
{
    strncpy_s(m_cName, cName, NUM1);
    strncpy_s(m_cIsbn, cIsbn, NUM1);
    strncpy_s(m_cPrice, cPrice, NUM2);
    strncpy_s(m_cAuthor, cAuthor, NUM2);
}


char* Cbook::GetName()
{
    return m_cName;
}

void Cbook::SetName(char* cName)
{
    strncpy_s(m_cName, cName, NUM1);
}

void Cbook::SetAuthor(char *cAuthor)
{
    strncpy_s(m_cAuthor, cAuthor, NUM2);
}
char* Cbook::GetAuthor() 
{
    return m_cAuthor;

}



char* Cbook::GetPrice()
{
    return m_cPrice;
}

void Cbook::SetPrice(char* cPrice)
{
    strncpy_s(m_cPrice, cPrice, NUM2);
}

char* Cbook::GetIsbn()
{
    return m_cIsbn;
}

void Cbook::SetIsbn(char* cIsbn)
{
    strncpy_s(m_cIsbn, cIsbn, NUM1);
}

void Cbook::DeleteData(int iCount)
{
    long respos;
    int iDataCount = 0;
    fstream file;
    fstream tmpFile;
    ofstream ofile;
    char cTmpBuffer[NUM1 + NUM1 + NUM2 + NUM2];
    file.open("book.dat", ios::in | ios::out | ios::binary);
    tmpFile.open("temp.dat", ios::in | ios::out | ios::binary | ios::trunc);
    file.seekg(0, ios::end);
    respos = file.tellg();
    iDataCount = respos / (NUM1 + NUM1 + NUM2 + NUM2);
    if (iCount<0 || iCount>iDataCount)
    {
        throw "Input number error";
    }
    else
    {
        file.seekg(iCount * (NUM1 + NUM1 + NUM2 + NUM2),ios::beg);
        for (int j = 0; j < (iDataCount - iCount); j++)
        {
            memset(cTmpBuffer, 0, NUM1 + NUM1 + NUM2 + NUM2);
            file.read(cTmpBuffer, NUM1 + NUM1 + NUM2 + NUM2);
            tmpFile.write(cTmpBuffer, NUM1 + NUM1 + NUM2 + NUM2);
        }
        file.close();
        tmpFile.seekp(0, ios::beg);
        ofile.open("book.dat");
        ofile.seekp((iCount - 1) * (NUM1 + NUM1 + NUM2 + NUM2),ios::beg);
        for (int i = 0; i < (iDataCount - iCount); i++)
        {
            memset(cTmpBuffer, 0, NUM1 + NUM1 + NUM2 + NUM2);
            tmpFile.read(cTmpBuffer, NUM1 + NUM1 + NUM2 + NUM2);
            ofile.write(cTmpBuffer, NUM1 + NUM1 + NUM2 + NUM2);
        }
        
    }
    tmpFile.close();
    ofile.close();
    remove("temp.dat");


}

void Cbook::GetBookFromFile(int iCount)
{
    char cName[NUM1];
    char cIsbn[NUM1];
    char cPrice[NUM2];
    char cAuthor[NUM2];
    ifstream ifile;
    ifile.open("book.dat", ios::binary);
    try
    {
        ifile.seekg(iCount * (NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
        ifile.read(cName,NUM1);
        if (ifile.tellg() > 0)
            strncpy_s(m_cName, cName, NUM1);
        ifile.read(cIsbn, NUM1);
        if (ifile.tellg() > 0)
            strncpy_s(m_cIsbn, cIsbn, NUM1);
        ifile.read(cAuthor, NUM2);
        if (ifile.tellg() > 0)
            strncpy_s(m_cAuthor, cAuthor, NUM1);
        ifile.read(cPrice, NUM2);
        if (ifile.tellg() > 0)
            strncpy_s(m_cPrice, cPrice, NUM2);
    }
    catch(...)
    {
        throw "File error occurred";
        ifile.close();
    }
    ifile.close();
}
void Cbook::WriteData()
{
    ofstream ofile;
    ofile.open("book.dat", ios::app | ios::binary);
    try
    {
        ofile.write(m_cName, NUM1);
        ofile.write(m_cIsbn, NUM1);
        ofile.write(m_cAuthor, NUM2);
        ofile.write(m_cPrice, NUM2);

    }
    catch (...)
    {
        throw "File error occurred";
        ofile.close();
    }
    ofile.close();
}
