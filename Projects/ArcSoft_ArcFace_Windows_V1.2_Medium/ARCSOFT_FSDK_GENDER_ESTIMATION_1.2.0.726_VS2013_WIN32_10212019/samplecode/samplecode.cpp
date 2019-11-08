#include <stdio.h>
#include "arcsoft_fsdk_gender_estimation.h"
#include "merror.h"

#pragma comment(lib,"libarcsoft_fsdk_gender_estimation.lib")

#define MAXIMUM_FACE_NUMBER 10
#define WORKBUF_SIZE        (30*1024*1024)
#define APPID		""			//APPID
#define ASGE_SDKKey  ""			//SDKKey

#define GENDER_ESTIMATION_STATICIMAGE 
//#define GENDER_ESTIMATION_PREVIEW 

/* define global variables for gender estimation */
MHandle							GenderEngine = nullptr;
ASVLOFFSCREEN					GenderImageInfo = { 0 };
ASGE_FSDK_GENDERFACEINPUT		GenderFaceInput;
ASGE_FSDK_GENDERRESULT			GenderResult;
MByte *							pWorkMem = nullptr;

/* initialize the engine and other variables */
MInt32 InitGenderEstimate()
{
	MInt32 res = MOK;
	GenderFaceInput.lFaceNumber = 0;
	GenderFaceInput.pFaceRectArray = new MRECT[MAXIMUM_FACE_NUMBER];
	if (0 == GenderFaceInput.pFaceRectArray)
		return MERR_NO_MEMORY;
	GenderFaceInput.pFaceOrientArray = new MInt32[MAXIMUM_FACE_NUMBER];
	if (0 == GenderFaceInput.pFaceOrientArray)
		return MERR_NO_MEMORY;

	pWorkMem = new MByte[WORKBUF_SIZE];
	res = ASGE_FSDK_InitGenderEngine(APPID, ASGE_SDKKey, pWorkMem, WORKBUF_SIZE, &GenderEngine);
	return res;
}
/* release the engine and other memory handles */
MInt32 UnInitGenderEstimate()
{
	MInt32 res = MOK;
	res = ASGE_FSDK_UninitGenderEngine(GenderEngine);
	if (GenderFaceInput.pFaceRectArray != nullptr)
	{
		delete[] GenderFaceInput.pFaceRectArray;
		GenderFaceInput.pFaceRectArray = nullptr;
	}
	if (GenderFaceInput.pFaceOrientArray != nullptr)
	{
		delete[] GenderFaceInput.pFaceOrientArray;
		GenderFaceInput.pFaceOrientArray = nullptr;
	}
	if (pWorkMem != nullptr)
	{
		delete[] pWorkMem;
		pWorkMem = nullptr;
	}
	return res;
}
/* print sdk version */
void PrintVersionInfo()
{
	const ASGE_FSDK_Version * pVersionInfo = nullptr;
	pVersionInfo = ASGE_FSDK_GetVersion(GenderEngine);
	printf("%d %d %d %d\n", pVersionInfo->lCodebase, pVersionInfo->lMajor, pVersionInfo->lMinor, pVersionInfo->lBuild);
	printf("%s\n", pVersionInfo->Version);
	printf("%s\n", pVersionInfo->BuildDate);
	printf("%s\n", pVersionInfo->CopyRight);
}

#ifdef GENDER_ESTIMATION_STATICIMAGE
/* load static image and save it to "pImageInfo", which is a "ASVLOFFSCREEN" struct. return "MOK" if succeed. */
MInt32 GetImageData(ASVLOFFSCREEN * pImageInfo)
{
	MInt32 res = MOK;

	/* load image. add your code here */
	/* ... ... */

	return res;
}

/* using ArcSoft face detection sdk to detect faces in the input image and save the face results to "pFaceInput".
return "MOK" if succeed. */
MInt32 FaceDetect(ASVLOFFSCREEN * pImageInfo, ASGE_FSDK_GENDERFACEINPUT * pFaceInput)
{
	MInt32 res = MOK;

	/* add your code here */
	/* ... ... */

	return res;
}
#endif


#ifdef GENDER_ESTIMATION_PREVIEW
/* get each preview frame and save it to "pImageInfo", which is a "ASVLOFFSCREEN" struct. return "MOK" if succeed. */
MInt32 GetPreviewData(ASVLOFFSCREEN * pImageInfo)
{
	MInt32 res = MOK;

	/* get frame data. add your code here */
	/* ... ... */

	return res;
}

/* using ArcSoft face tracking library to detect faces in the input image and save the face results to "pFaceInput".
return "MOK" if succeed. */
MInt32 FaceTrack(ASVLOFFSCREEN * pImageInfo, ASGE_FSDK_GENDERFACEINPUT * pFaceInput)
{
	MInt32 res = MOK;

	/* add your code here */
	/* ... ... */

	return res;
}
#endif

/* estimate gender  */
MInt32 GenderEstimate()
{
	MInt32 res = MOK;
#ifdef GENDER_ESTIMATION_STATICIMAGE
	res = ASGE_FSDK_GenderEstimation_StaticImage(GenderEngine, &GenderImageInfo, &GenderFaceInput, &GenderResult);
#endif

#ifdef GENDER_ESTIMATION_PREVIEW
	res = ASGE_FSDK_GenderEstimation_Preview(GenderEngine, &GenderImageInfo, &GenderFaceInput, &GenderResult);
#endif

	return res;
}

int main()
{
	/* initialize the engine and other variables */
	MRESULT nRet = MERR_UNKNOWN;
	nRet = InitGenderEstimate();
	if (nRet != MOK)
	{
		printf("InitGenderEngine failed , errorcode is %d \n", nRet);
		return -1;
	}

	/* print version info */
	PrintVersionInfo();

#ifdef GENDER_ESTIMATION_STATICIMAGE
	/* image data acquisition */
	nRet = GetImageData(&GenderImageInfo);
	if (nRet != MOK)
	{
		printf("GetImageData: nRet=%d\n", nRet);
		return nRet;
	}

	/* face detection */
	nRet = FaceDetect(&GenderImageInfo, &GenderFaceInput);
	if (nRet != MOK)
	{
		printf("FaceDetect: nRet=%d\n", nRet);
		return nRet;
	}

	/* do gender estimation when the face number is bigger than 0. */
	if (GenderFaceInput.lFaceNumber > 0)
	{
		/* gender estimation */
		nRet = GenderEstimate();
		if (nRet != MOK)
		{
			printf("GenderEstimate: nRet=%d\n", nRet);
			return nRet;
		}

		/* print gender estimation result */
		for (int i = 0; i < GenderFaceInput.lFaceNumber; i++)
		{
			printf("Gender: %d\n", GenderResult.pGenderResultArray[i]);
		}
	}
#endif

#ifdef GENDER_ESTIMATION_PREVIEW
	/* preview data acquisition */
	while (MOK == GetPreviewData(&GenderImageInfo))
	{
		/* face tracking */
		nRet = FaceTrack(&GenderImageInfo, &GenderFaceInput);
		if (nRet != MOK)
		{
			printf("FaceDetect: nRet=%d\n", nRet);
			return nRet;
		}

		/* gender estimation */
		/* no matter "GenderFaceInput->lFaceNumber" is greater than or equal to 0, next sentence must be excuted. */
		nRet = GenderEstimate();
		if (nRet != MOK)
		{
			printf("GenderEstimate: nRet=%d\n", nRet);
			return nRet;
		}

		/* print gender estimation result */
		if (GenderFaceInput.lFaceNumber > 0)
		{
			for (int i = 0; i < GenderFaceInput.lFaceNumber; i++)
			{
				printf("Gender: %d\n", GenderResult.pGenderResultArray[i]);
			}
		}
	}
#endif

	/* release the engine and other memory handles */
	nRet = UnInitGenderEstimate();
	return nRet;
}
