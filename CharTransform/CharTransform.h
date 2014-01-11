#include <iostream>

using namespace std;

class CCharTransform    
{
public:
    CCharTransform();
    virtual ~CCharTransform();    
    char* WcharToChar(const wchar_t* wc);
    wchar_t* CharToWchar(const char* c);
    void Release();  
private:
    char* m_char;
    wchar_t* m_wchar;
};  