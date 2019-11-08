#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>
#include "arcsoft_fsdk_face_tracking.h"
#include "merror.h"

#pragma comment(lib,"libarcsoft_fsdk_face_tracking.lib")

#define WORKBUF_SIZE        (40*1024*1024)
#define APPID		""			//APPID
#define SDKKey		""			//SDKKey

/* ��ȡ��Ƶ֡���ݣ������浽ASVLOFFSCREEN�ṹ���� */
MRESULT GetPreviewData(ASVLOFFSCREEN *offInput)
{
	MInt32 res = MOK;

	/* get frame data. add your code here */
	/* ... ... */

	return res;
}
int main()
{
	/* ��ʼ������ͱ��� */
	MRESULT nRet = MERR_UNKNOWN;
	MHandle hEngine = nullptr;
	MInt32 nScale = 16;
	MInt32 nMaxFace = 10;
	MByte *pWorkMem = (MByte *)malloc(WORKBUF_SIZE);
	if (pWorkMem == nullptr)
	{
		return -1;
	}
	nRet = AFT_FSDK_InitialFaceEngine(APPID, SDKKey, pWorkMem, WORKBUF_SIZE, &hEngine, AFT_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);
	if (nRet != MOK)
	{
		return -1;
	}
	/* ��ӡ�汾��Ϣ */
	const AFT_FSDK_Version * pVersionInfo = nullptr;
	pVersionInfo = AFT_FSDK_GetVersion(hEngine);
	fprintf(stdout, "%d %d %d %d\n", pVersionInfo->lCodebase, pVersionInfo->lMajor, pVersionInfo->lMinor, pVersionInfo->lBuild);
	fprintf(stdout, "%s\n", pVersionInfo->Version);
	fprintf(stdout, "%s\n", pVersionInfo->BuildDate);
	fprintf(stdout, "%s\n", pVersionInfo->CopyRight);

	/* ��ȡ��Ƶ֡���ݣ������浽ASVLOFFSCREEN�ṹ�� */
	ASVLOFFSCREEN offInput = { 0 };
	int frame = 1;
	while (MOK == GetPreviewData(&offInput))
	{
		LPAFT_FSDK_FACERES	FaceRes = nullptr;
		/* �������� */
		nRet = AFT_FSDK_FaceFeatureDetect(hEngine, &offInput, &FaceRes);
		if (nRet != MOK)
		{
			fprintf(stderr, "Face Tracking failed, error code: %d\n", nRet);
		}
		else
		{
			fprintf(stdout, "The number of face: %d\n", FaceRes->nFace);
			for (int i = 0; i < FaceRes->nFace; i++)
			{
				fprintf(stdout, "Frame : %d, Face[%d]: rect[%d,%d,%d,%d]\n", frame++, i, FaceRes->rcFace[i].left, FaceRes->rcFace[i].top, FaceRes->rcFace[i].right, FaceRes->rcFace[i].bottom);
			}
		}
	}
	/* �ͷ�������ڴ� */
	nRet = AFT_FSDK_UninitialFaceEngine(hEngine);
	if (nRet != MOK)
	{
		fprintf(stderr, "UninitialFaceEngine failed , errorcode is %d \n", nRet);
	}
	free(offInput.ppu8Plane[0]);
	free(pWorkMem);
	return 0;
}

