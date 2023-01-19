#include "Sort.h"

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

static mVoid selectSorting1Byte(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	// only char type
	char* pchOriginalData = NULL;
	pchOriginalData = (char*)malloc(sizeof(char) * _unDataNum);
	
	if (NULL != pchOriginalData)
	{
		memcpy(pchOriginalData, _pchInput, sizeof(char) * _unDataNum);

		char chLastestMin = SCHAR_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			char chCurMin = SCHAR_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (chLastestMin < pchOriginalData[szInputIdx] && chCurMin > pchOriginalData[szInputIdx])
				{
					chCurMin = pchOriginalData[szInputIdx];
				}
			}

			chLastestMin = chCurMin;
			_pchOutput[szOutputIdx] = chCurMin;
		}

		free(pchOriginalData);
	}

	return;
}

static mVoid selectSorting2Bytes(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	// only short type
	short* puwOriginalData = NULL;
	short* puwSortedData = NULL;
	puwOriginalData = (short*)malloc(sizeof(short) * _unDataNum);
	puwSortedData = (short*)malloc(sizeof(short) * _unDataNum);

	if (NULL != puwOriginalData && NULL != puwSortedData)
	{
		memcpy(puwOriginalData, _pchInput, sizeof(short) * _unDataNum);

		short uwLastestMin = SHRT_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			short uwCurMin = SHRT_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (uwLastestMin < puwOriginalData[szInputIdx] && uwCurMin > puwOriginalData[szInputIdx])
				{
					uwCurMin = puwOriginalData[szInputIdx];
				}
			}

			uwLastestMin = uwCurMin;
			puwSortedData[szOutputIdx] = uwCurMin;
		}

		memcpy(_pchOutput, puwSortedData, sizeof(short) * _unDataNum);
		free(puwOriginalData);
		free(puwSortedData);
	}

	return;
}

static mVoid selectSortingInteger(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	int* pnOriginData = NULL;
	int* pnSortedData = NULL;
	pnOriginData = (int*)malloc(sizeof(int) * _unDataNum);
	pnSortedData = (int*)malloc(sizeof(int) * _unDataNum);

	if (NULL != pnOriginData && NULL != pnSortedData)
	{
		(mVoid)memcpy(pnOriginData, _pchInput, sizeof(int) * _unDataNum);

		int nLastestMin = INT_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			int nCurMin = INT_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (nLastestMin < pnOriginData[szInputIdx] && nCurMin > pnOriginData[szInputIdx])
				{
					nCurMin = pnOriginData[szInputIdx];
				}
			}

			nLastestMin = nCurMin;
			pnSortedData[szOutputIdx] = nCurMin;
		}

		memcpy(_pchOutput, pnSortedData, sizeof(short) * _unDataNum);
		free(pnOriginData);
		free(pnSortedData);
	}

	return;
}

static mVoid selectSortingLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	long* pnOriginData = NULL;
	long* pnSortedData = NULL;
	pnOriginData = (long*)malloc(sizeof(long) * _unDataNum);
	pnSortedData = (long*)malloc(sizeof(long) * _unDataNum);

	if (NULL != pnOriginData && NULL != pnSortedData)
	{
		(mVoid)memcpy(pnOriginData, _pchInput, sizeof(long) * _unDataNum);

		long nLastestMin = LONG_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			long nCurMin = LONG_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (nLastestMin < pnOriginData[szInputIdx] && nCurMin > pnOriginData[szInputIdx])
				{
					nCurMin = pnOriginData[szInputIdx];
				}
			}

			nLastestMin = nCurMin;
			pnSortedData[szOutputIdx] = nCurMin;
		}

		memcpy(_pchOutput, pnSortedData, sizeof(short) * _unDataNum);
		free(pnOriginData);
		free(pnSortedData);
	}

	return;
}

static mVoid selectSortingFloat(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	float* pfOriginData = NULL;
	float* pfSortedData = NULL;
	pfOriginData = (float*)malloc(sizeof(float) * _unDataNum);
	pfSortedData = (float*)malloc(sizeof(float) * _unDataNum);

	if (NULL != pfOriginData && NULL != pfSortedData)
	{
		(mVoid)memcpy(pfOriginData, _pchInput, sizeof(float) * _unDataNum);

		float nLastestMin = FLT_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			float nCurMin = FLT_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (nLastestMin < pfOriginData[szInputIdx] && nCurMin > pfOriginData[szInputIdx])
				{
					nCurMin = pfOriginData[szInputIdx];
				}
			}

			nLastestMin = nCurMin;
			pfSortedData[szOutputIdx] = nCurMin;
		}

		memcpy(_pchOutput, pfSortedData, sizeof(short) * _unDataNum);
		free(pfOriginData);
		free(pfSortedData);
	}

	return;
}

static mVoid selectSorting4Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	// Long, Integer and Float type
	switch (_eDataType)
	{
	case eDataTypeInteger:
		selectSortingInteger(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeLong:
		selectSortingLong(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeFloat:
		selectSortingFloat(_pchInput, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

static mVoid selectSortingLongLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	long long* pllOriginData = NULL;
	long long* pllSortedData = NULL;
	pllOriginData = (long long*)malloc(sizeof(long long) * _unDataNum);
	pllSortedData = (long long*)malloc(sizeof(long long) * _unDataNum);

	if (NULL != pllOriginData && NULL != pllSortedData)
	{
		(mVoid)memcpy(pllOriginData, _pchInput, sizeof(long long) * _unDataNum);

		long long nLastestMin = LLONG_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			long long nCurMin = LLONG_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (nLastestMin < pllOriginData[szInputIdx] && nCurMin > pllOriginData[szInputIdx])
				{
					nCurMin = pllOriginData[szInputIdx];
				}
			}

			nLastestMin = nCurMin;
			pllSortedData[szOutputIdx] = nCurMin;
		}

		memcpy(_pchOutput, pllSortedData, sizeof(short) * _unDataNum);
		free(pllOriginData);
		free(pllSortedData);
	}

	return;
}

static mVoid selectSortingDouble(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	double* pdOriginData = NULL;
	double* pdSortedData = NULL;
	pdOriginData = (double*)malloc(sizeof(double) * _unDataNum);
	pdSortedData = (double*)malloc(sizeof(double) * _unDataNum);

	if (NULL != pdOriginData && NULL != pdSortedData)
	{
		(mVoid)memcpy(pdOriginData, _pchInput, sizeof(double) * _unDataNum);

		double dLastestMin = LLONG_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			double dCurMin = LLONG_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (dLastestMin < pdOriginData[szInputIdx] && dCurMin > pdOriginData[szInputIdx])
				{
					dCurMin = pdOriginData[szInputIdx];
				}
			}

			dLastestMin = dCurMin;
			pdSortedData[szOutputIdx] = dCurMin;
		}

		memcpy(_pchOutput, pdSortedData, sizeof(short) * _unDataNum);
		free(pdOriginData);
		free(pdSortedData);
	}

	return;
}

static mVoid selectSorting8Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	// Long Long and Double type
	switch (_eDataType)
	{
	case eDataTypeLongLong:
		selectSortingLongLong(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeDouble:
		selectSortingDouble(_pchInput, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}
	return;
}

mVoid selectSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeChar:
		selectSorting1Byte(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeShort:
		selectSorting2Bytes(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeInteger:
	case eDataTypeLong:
	case eDataTypeFloat:
		selectSorting4Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeLongLong:
	case eDataTypeDouble:
		selectSorting8Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default :
		break;
	}

	return;
}

static mVoid bubbleSorting1Byte(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	char* lchBubble = NULL;
	lchBubble = (char*)malloc(sizeof(char) * _unDataNum);
	if (NULL != lchBubble)
	{
		memcpy(lchBubble, _pchInput, sizeof(char) * _unDataNum);

		size_t szEndIdx = _unDataNum - 1;
		size_t szCurIdx = 0;
		for (szEndIdx; szEndIdx > 0; szEndIdx--)
		{
			for (szCurIdx = 0; szCurIdx < szEndIdx; szCurIdx++)
			{
				// szCurIdx 와 szCurIdx + 1을 비교한다. 
				// szCurIdx > szCurIdx + 1 인 경우 swap
				// szCurIdx <= szCurIdx + 1 인 경우 아무것도 하지 않는다. 
				if (lchBubble[szCurIdx] > lchBubble[szCurIdx + 1])
				{
					char chTmp = lchBubble[szCurIdx];
					lchBubble[szCurIdx] = lchBubble[szCurIdx + 1];
					lchBubble[szCurIdx + 1] = chTmp;
				}
			}
		}

		memcpy(_pchOutput, lchBubble, sizeof(char) * _unDataNum);
	}

	return;
}

static mVoid bubbleSorting2Bytes(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{
	short* lwBubble = NULL;
	lwBubble = (short*)malloc(sizeof(short) * _unDataNum);
	if (NULL != lwBubble)
	{
		memcpy(lwBubble, _pchInput, sizeof(short) * _unDataNum);

		size_t szEndIdx = _unDataNum - 1;
		size_t szCurIdx = 0;
		for (szEndIdx; szEndIdx > 0; szEndIdx--)
		{
			for (szCurIdx = 0; szCurIdx < szEndIdx; szCurIdx++)
			{
				if (lwBubble[szCurIdx] > lwBubble[szCurIdx + 1])
				{
					short wTmp = lwBubble[szCurIdx];
					lwBubble[szCurIdx] = lwBubble[szCurIdx + 1];
					lwBubble[szCurIdx + 1] = wTmp;
				}
			}
		}

		memcpy(_pchOutput, lwBubble, sizeof(short) * _unDataNum);
	}

	return;
}

static mVoid bubbleSortingInteger(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid bubbleSortingLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid bubbleSortingFloat(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid bubbleSorting4Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeInteger:
		bubbleSortingInteger(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeLong:
		bubbleSortingLong(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeFloat:
		bubbleSortingFloat(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

static mVoid bubbleSortingLongLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid bubbleSortingDouble(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid bubbleSorting8Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeLongLong:
		bubbleSortingLongLong(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeDouble:
		bubbleSortingDouble(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

mVoid bubbleSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeChar:
		bubbleSorting1Byte(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeShort:
		bubbleSorting2Bytes(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeInteger:
	case eDataTypeLong:
	case eDataTypeFloat:
		bubbleSorting4Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeLongLong:
	case eDataTypeDouble:
		bubbleSorting8Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

static mVoid heapSorting1Byte(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid heapSorting2Bytes(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid heapSortingInteger(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid heapSortingLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid heapSortingFloat(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid heapSorting4Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeInteger:
		heapSortingInteger(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeLong:
		heapSortingLong(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeFloat:
		heapSortingFloat(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

static mVoid heapSortingLongLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid heapSortingDouble(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid heapSorting8Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeLongLong:
		heapSortingLongLong(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeDouble:
		heapSortingDouble(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

mVoid heapSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeChar:
		heapSorting1Byte(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeShort:
		heapSorting2Bytes(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeInteger:
	case eDataTypeLong:
	case eDataTypeFloat:
		heapSorting4Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeLongLong:
	case eDataTypeDouble:
		heapSorting8Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

static mVoid mergeSorting1Byte(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid mergeSorting2Bytes(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid mergeSortingInteger(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid mergeSortingLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid mergeSortingFloat(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid mergeSorting4Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeInteger:
		mergeSortingInteger(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeLong:
		mergeSortingLong(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeFloat:
		mergeSortingFloat(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

static mVoid mergeSortingLongLong(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid mergeSortingDouble(char* _pchInput, size_t _unDataNum, char* _pchOutput)
{}

static mVoid mergeSorting8Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeLongLong:
		mergeSortingLongLong(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeDouble:
		mergeSortingDouble(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}

mVoid mergeSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	switch (_eDataType)
	{
	case eDataTypeChar:
		mergeSorting1Byte(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeShort:
		mergeSorting2Bytes(_pchInput, _unDataNum, _pchOutput);
		break;
	case eDataTypeInteger:
	case eDataTypeLong:
	case eDataTypeFloat:
		mergeSorting4Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	case eDataTypeLongLong:
	case eDataTypeDouble:
		mergeSorting8Bytes(_pchInput, _eDataType, _unDataNum, _pchOutput);
		break;
	default:
		break;
	}

	return;
}