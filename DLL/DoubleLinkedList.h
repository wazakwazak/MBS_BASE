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

mBool		IsEmpty(DoubleLinkedList* _pstList);
DllNode*	GetLastNode(DoubleLinkedList* _pstList);

mBool		GetNodeIdxByValue(DoubleLinkedList* _pstList, mInt32 _nVal, mUInt32* _punIdx);
mBool		GetNodeValueByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _pnVal);

mBool		AddbyValue(DoubleLinkedList* _pstList, mInt32 _nVal);
mBool		AddByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32 _nVal);
mBool		DeleteByValue(DoubleLinkedList* _pstList, mInt32 _nVal);
mBool		DeleteByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx);

