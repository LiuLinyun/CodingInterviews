#include <iostream>
#include <cstring>

using namespace std;

class CMyString 
{
    public: 
    CMyString(char* pData = nullptr)
    {
        if(pData == nullptr)
            m_pData = new char('\0');
        else
        {
            m_pData = new char[strlen(pData)+1];
            strcpy(m_pData, pData);
        }
    }
    CMyString(const CMyString& str)
    {
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }
    CMyString& operator=(const CMyString& str)
    {
        CMyString temp{str};
        std::swap(this->m_pData, temp.m_pData);
        return *this;
    }
    CMyString& operator=(CMyString&& str)
    { 
        std::swap(*this, str);
        return *this;
    }
    ~CMyString()
    {
        delete m_pData;
    }

    void print() const
    {
        cout << string(m_pData) << endl;
    }

    private: 
    char* m_pData;
};


int main()
{
    char* pchar = new char[10];
    for(int i=0; i<9; ++i)
    {
        *(pchar+i) = 'a' + i;
    }
    *(pchar + 9) = '\0';

    CMyString cstr1{pchar};
    CMyString cstr2;
    cstr2.print();
    cstr2 = cstr1;

    cout << string(pchar) << endl;
    cstr1.print();
    cstr2.print();
    cstr2 = cstr2;
    cstr2.print();
    return 0;
}