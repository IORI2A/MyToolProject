#include <stdio.h>
#include "arcsoft_fsdk_age_estimation.h"
#include "merror.h"

#pragma comment(lib,"libarcsoft_fsdk_age_estimation.lib")

#define MAXIMUM_FACE_NUMBER 10
#define WORKBUF_SIZE        (30*1024*1024)
#define APPID		""			//APPID
#define ASAE_SDKKey  ""			//SDKKey

#define AGE_ESTIMATION_STATICIMAGE 
#define AGE_ESTIMATION_PREVIEW 

/* define global variables for age estimation */
MHandle						AgeEngine = nullptr;
ASVLOFFSCREEN				AgeImageInfo = { 0 };
ASAE_FSDK_AGEFACEINPUT		AgeFaceInput;
ASAE_FSDK_AGERESULT			AgeResult;
MByte *						pWorkMem = nullptr;

/* initialize the engine and other variables */
MInt32 InitAgeEstimate()
{
	MInt32 res = MOK;
	AgeFaceInput.lFaceNumber = 0;
	AgeFaceInput.pFaceRectArray = new MRECT[MAXIMUM_FACE_NUMBER];
	if (0 == AgeFaceInput.pFaceRectArray)
		return MERR_NO_MEMORY;
	AgeFaceInput.pFaceOrientArray = new MInt32[MAXIMUM_FACE_NUMBER];
	if (0 == AgeFaceInput.pFaceOrientArray)
		return MERR_NO_MEMORY;

	pWorkMem = new MByte[WORKBUF_SIZE];
	res = ASAE_FSDK_InitAgeEngine(APPID, ASAE_SDKKey, pWorkMem, WORKBUF_SIZE, &AgeEngine);
	return res;
}
/* release the engine and other memory handles */
MInt32 UnInitAgeEstimate()
{
	MInt32 res = MOK;
	res = ASAE_FSDK_UninitAgeEngine(AgeEngine);
	if (AgeFaceInput.pFaceRectArray != nullptr)
	{
		delete[] AgeFaceInput.pFaceRectArray;
		AgeFaceInput.pFaceRectArray = nullptr;
	}
	if (AgeFaceInput.pFaceOrientArray != nullptr)
	{
		delete[] AgeFaceInput.pFaceOrientArray;
		AgeFaceInput.pFaceOrientArray = nullptr;
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
	const ASAE_FSDK_Version * pVersionInfo = nullptr;
	pVersionInfo = ASAE_FSDK_GetVersion(AgeEngine);
	printf("%d %d %d %d\n", pVersionInfo->lCodebase, pVersionInfo->lMajor, pVersionInfo->lMinor, pVersionInfo->lBuild);
	printf("%s\n", pVersionInfo->Version);
	printf("%s\n", pVersionInfo->BuildDate);
	printf("%s\n", pVersionInfo->CopyRight);
}

#ifdef AGE_ESTIMATION_STATICIMAGE
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
MInt32 FaceDetect(ASVLOFFSCREEN * pImageInfo, ASAE_FSDK_AGEFACEINPUT * pFaceInput)
{
	MInt32 res = MOK;

	/* add your code here */
	/* ... ... */

	return res;
}
#endif


#ifdef AGE_ESTIMATION_PREVIEW
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
MInt32 FaceTrack(ASVLOFFSCREEN * pImageInfo, ASAE_FSDK_AGEFACEINPUT * pFaceInput)
{
	MInt32 res = MOK;

	/* add your code here */
	/* ... ... */

	return res;
}
#endif

/* estimate age  */
MInt32 AgeEstimate()
{
	MInt32 res = MOK;
#ifdef AGE_ESTIMATION_STATICIMAGE
	res = ASAE_FSDK_AgeEstimation_StaticImage(AgeEngine, &AgeImageInfo, &AgeFaceInput, &AgeResult);
#endif

#ifdef AGE_ESTIMATION_PREVIEW
	res = ASAE_FSDK_AgeEstimation_Preview(AgeEngine, &AgeImageInfo, &AgeFaceInput, &AgeResult);
#endif

	return res;
}

int main()
{
	/* initialize the engine and other variables */
	MRESULT nRet = MERR_UNKNOWN;
	nRet = InitAgeEstimate();
	if (nRet != MOK)
	{
		printf("InitAgeEngine failed , errorcode is %d \n", nRet);
		return -1;
	}

	/* print version info */
	PrintVersionInfo();

#ifdef AGE_ESTIMATION_STATICIMAGE
	/* image data acquisition */
	nRet = GetImageData(&AgeImageInfo);
	if (nRet != MOK)
	{
		printf("GetImageData: nRet=%d\n", nRet);
		return nRet;
	}

	/* face detection */
	nRet = FaceDetect(&AgeImageInfo, &AgeFaceInput);
	if (nRet != MOK)
	{
		printf("FaceDetect: nRet=%d\n", nRet);
		return nRet;
	}

	/* do age estimation when the face number is bigger than 0. */
	if (AgeFaceInput.lFaceNumber > 0)
	{
		/* age estimation */
		nRet = AgeEstimate();
		if (nRet != MOK)
		{
			printf("AgeEstimate: nRet=%d\n", nRet);
			return nRet;
		}

		/* print age estimation result */
		for (int i = 0; i < AgeFaceInput.lFaceNumber; i++)
		{
			printf("Age: %d, ", AgeResult.pAgeResultArray[i]);
		}
		printf("\n");
	}
#endif

#ifdef AGE_ESTIMATION_PREVIEW
	/* preview data acquisition */
	while (MOK == GetPreviewData(&AgeImageInfo)) 
	{
		/* face tracking */
		nRet = FaceTrack(&AgeImageInfo, &AgeFaceInput);
		if (nRet != MOK)
		{
			printf("FaceDetect: nRet=%d\n", nRet);
			return nRet;
		}

		/* age estimation */
		/* no matter "AgeFaceInput->lFaceNumber" is greater than or equal to 0, next sentence must be excuted. */
		nRet = AgeEstimate();
		if (nRet != MOK)
		{
			printf("AgeEstimate: nRet=%d\n", nRet);
			return nRet;
		}

		/* print age estimation result */
		if (AgeFaceInput.lFaceNumber > 0)
		{
			for (int i = 0; i < AgeFaceInput.lFaceNumber; i++)
			{
				printf("Age: %d, ", AgeResult.pAgeResultArray[i]);
			}
			printf("\n");
		}
	}
#endif

	/* release the engine and other memory handles */
	nRet = UnInitAgeEstimate();
	return nRet;
}
