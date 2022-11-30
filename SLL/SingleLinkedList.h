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

mBool		SllIsEmpty(SingleLinkedList* _pstList);
SllNode*	SllGetLastNode(SingleLinkedList* _pstList);

mUInt32		SllGetNodeIdxByValue(SingleLinkedList* _pstList, mInt32 _nVal);
mBool		SllGetNodeValueByIndex(SingleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _pnVal);

mBool		SllAddByValue(SingleLinkedList* _pstList, mInt32 _nVal);
mBool		SllAddByIndex(SingleLinkedList* _pstList, mUInt32 _unIdx, mInt32 _nVal);
mBool		SllDeleteByValue(SingleLinkedList* _pstList, mInt32 _nVal);
mBool		SllDeleteByIndex(SingleLinkedList* _pstList, mUInt32 _nIdx);
