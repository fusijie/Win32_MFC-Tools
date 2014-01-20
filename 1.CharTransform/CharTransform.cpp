#include "stdafx.h"
#include "CharTransform.h"

CCharTransform::CCharTransform()
:m_char(NULL)
,m_wchar(NULL)
{
}

CCharTransform::~CCharTransform()
{
    Release();
}

char* CCharTransform::WcharToChar(const wchar_t* wc)
{
    Release();
    int len= WideCharToMultiByte(CP_ACP,0,wc,wcslen(wc),NULL,0,NULL,NULL);
    m_char=new char[len+1];
    WideCharToMultiByte(CP_ACP,0,wc,wcslen(wc),m_char,len,NULL,NULL);
    m_char[len]='\0';
    return m_char;
}

wchar_t* CCharTransform::CharToWchar(const char* c)
{
    Release();
    int len = MultiByteToWideChar(CP_ACP,0,c,strlen(c),NULL,0);
    m_wchar=new wchar_t[len+1];
    MultiByteToWideChar(CP_ACP,0,c,strlen(c),m_wchar,len);
    m_wchar[len]='\0';
    return m_wchar;
}

void CCharTransform::Release()
{
    if(m_char)
    {
        delete m_char;
        m_char=NULL;
    }
    if(m_wchar)
    {
        delete m_wchar;
        m_wchar=NULL;
    }
}