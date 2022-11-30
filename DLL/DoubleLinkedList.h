// This header file is for double linked list.
#pragma once

#include "../mType.h"

typedef struct _DLLNode
{
	mInt32 nVal;
	struct _DLLNode* pstPrev;
	struct _DLLNode* pstNext;
}DllNode;

typedef struct _DoubleLinkedList
{
	mUInt32 unCount;
	DllNode* pstFront;
	DllNode* pstRear;
}DoubleLinkedList;

mBool		DllIsEmpty(DoubleLinkedList* _pstList);
DllNode*	DllGetLastNode(DoubleLinkedList* _pstList);

mBool		DllGetNodeIdxByValue(DoubleLinkedList* _pstList, mInt32 _nVal, mUInt32* _punIdx);
mBool		DllGetNodeValueByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _pnVal);

mBool		DllAddbyValue(DoubleLinkedList* _pstList, mInt32 _nVal);
mBool		DllAddByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32 _nVal);
mBool		DllDeleteByValue(DoubleLinkedList* _pstList, mInt32 _nVal);
mBool		DllDeleteByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx);

