
// JPEG2BMP.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CJPEG2BMPApp:
// �йش����ʵ�֣������ JPEG2BMP.cpp
//

class CJPEG2BMPApp : public CWinApp
{
public:
	CJPEG2BMPApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CJPEG2BMPApp theApp;