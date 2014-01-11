/*****************************************************************
 
	功能:读取当前目录下ini配置文件的
	包含:dll文件,lib文件,.h头文件,测试文件
	日期:2013-11-30
	作者:fusijie
	E_Mail:Geek.Jacky@Gmail.com
	version: 1.0
	注:当前版本必须全部设置，并不是以追加的形式

*****************************************************************/

#pragma once

// CIniFile 命令目标

class AFX_EXT_CLASS CIniFile : public CObject
{
public:
	CIniFile();
	CIniFile(CString FileName):m_sFileName(FileName){}
	virtual ~CIniFile();

public:
	void SetFileName(CString FileName);

	CString GetString(CString Section, CString Item, CString default);
	int GetInt(CString Section, CString Item, int default);
	bool GetBool(CString Section, CString Item, bool default);

	void SetString(CString Section, CString Item, CString Value);
	void SetInt(CString Section, CString Item, int Value);
	void SetBool(CString Section, CString Item, bool Value);

private:

	void WriteFileString(CString Section, CString Item, CString Value);
	CString GetFileString(CString Section, CString Item, CString Value);

	BOOL WriteIniFile();
	BOOL ReadIniFile();

	CString m_sFileName;
	CStdioFile IniFile;
	BOOL  bFileExist;
	CStringArray FileContainer;
};


