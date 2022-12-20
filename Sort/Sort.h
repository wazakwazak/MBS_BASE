#pragma once
#include "../mType.h"

#define DATA_UNSIGNED 0
#define DATA_SIGNED   1

typedef enum _DateType {
	eDataTypeChar,		// 1 Byte
	eDataTypeShort,		// 2 Bytes
	eDataTypeInteger,	// 4 Bytes
	eDataTypeLong,		// 4 Bytes
	eDataTypeLongLong,	// 8 Bytes
	eDataTypeFloat,		// 4 Bytes
	eDataTypeDouble,	// 8 Bytes
	eDataTypeUnknown
}DataType;

mVoid selectSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);
mVoid bubbleSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);
mVoid heapSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);
mVoid mergeSorting(char* _pchInput, DataType _eDataType, size_t _unDataNum, char* _pchOutput);