#include "Sort.h"

#include <limits.h>
#include <string.h>
#include <stdlib.h>

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

		char chLastestMin = SCHAR_MIN;
		size_t szOutputIdx = 0;
		size_t szInputIdx = 0;
		for (szOutputIdx = 0; szOutputIdx < _unDataNum; szOutputIdx++)
		{
			char chCurMin = SCHAR_MAX;
			for (szInputIdx = 0; szInputIdx < _unDataNum; szInputIdx++)
			{
				if (chLastestMin < puwOriginalData[szInputIdx] && chCurMin > puwOriginalData[szInputIdx])
				{
					chCurMin = puwOriginalData[szInputIdx];
				}
			}

			chLastestMin = chCurMin;
			puwSortedData[szOutputIdx] = chCurMin;
		}

		memcpy(_pchOutput, puwSortedData, sizeof(short) * _unDataNum);
		free(puwOriginalData);
		free(puwSortedData);
	}

	return;
}

static mVoid selectSorting4Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	return;
}

static mVoid selectSorting8Bytes(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
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

mVoid bubbleSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	return;
}

mVoid heapSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	return;
}

mVoid mergeSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput)
{
	return;
}