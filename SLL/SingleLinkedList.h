// This header file is for single linked list.
#pragma once

#include "../mType.h"

typedef struct _SLLNode
{
	mInt32 nVal;
	struct _SLLNode* pstNext;
}SllNode;

typedef struct _SingleLinkedList
{
	mUInt32 unCount;
	SllNode* pstFront;
	SllNode* pstRear;
}SingleLinkedList;

mBool		bIsEmpty(SingleLinkedList* _pstList);
SllNode*	GetLastNode(SingleLinkedList* _pstList);

mUInt32		GetNodeIdxByValue(SingleLinkedList* _pstList, mInt32 _nVal);
mBool		GetNodeValueByIndex(SingleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _pnVal);

mBool		AddByValue(SingleLinkedList* _pstList, mInt32 _nVal);
mBool		AddByIndex(SingleLinkedList* _pstList, mUInt32 _unIdx, mInt32 _nVal);
mBool		DeleteByValue(SingleLinkedList* _pstList, mInt32 _nVal);
mBool		DeleteByIndex(SingleLinkedList* _pstList, mUInt32 _nIdx);