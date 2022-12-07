#pragma once
#include "../mType.h"

#define DATA_UNSIGNED 0
#define DATA_SIGNED   1

typedef enum _DateType {
	eDataTypeChar,
	eDataTypeShort,
	eDataTypeInteger,
	eDataTypeLong,
	eDataTypeFloat,
	eDataTypeDouble,
	eDataTypeUnknown
}DataType;

mVoid selectSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);
mVoid bubbleSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);
mVoid heapSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);
mVoid mergeSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);