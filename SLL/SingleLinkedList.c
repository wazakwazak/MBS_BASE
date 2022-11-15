#include "SingleLinkedList.h"
#include <stdlib.h>

mBool bIsEmpty(SingleLinkedList* _pstList)
{
	// true: list it empty, false: list has some nodes.
	return 0 == _pstList->unCount ? mTrue : mFalse;
}

SllNode* GetLastNode(SingleLinkedList* _pstList)
{
	return _pstList->pstRear;
}

mUInt32 GetNodeIdxByValue(SingleLinkedList* _pstList, mInt32 _nVal)
{
	// -1  : there does not exist the same value in the list.
	// else: found the same value in the list. return the index of node having the value.

	mUInt32 unRetVal = -1;

	const SllNode* pstCurNode = (const SllNode*)_pstList->pstFront;
	mUInt32 unLoopCnt = 0;
	while (NULL != pstCurNode)
	{
		if (_nVal == pstCurNode->nVal)
		{
			unRetVal = unLoopCnt;
			break;
		}

		pstCurNode = (const SllNode*)pstCurNode->pstNext;
		unLoopCnt++;
	}

	return unRetVal;
}

mBool GetNodeValueByIndex(SingleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _pnVal)
{
	mBool bRetVal = mFalse;

	if (_unIdx > _pstList->unCount)
	{
		bRetVal = mFalse;
		*_pnVal = 0;
	}
	else
	{
		SllNode* pstCurNode = _pstList->pstFront;
		mUInt32 unLoopCnt = 0;
		while (NULL != pstCurNode)
		{
			if (_unIdx == unLoopCnt)
			{
				bRetVal = mTrue;
				*_pnVal = pstCurNode->nVal;
				break;
			}

			pstCurNode = pstCurNode->pstNext;
			unLoopCnt++;
		}
	}

	return bRetVal;
}

mBool AddByValue(SingleLinkedList* _pstList, mInt32 _nVal)
{
	// add new data at the end of the list.
	mBool bRetVal = mFalse;

	SllNode* pstNewNode = NULL;
	pstNewNode = (SllNode*)malloc(sizeof(SllNode));

	if (NULL == pstNewNode)
	{
		// fail to get memory
		bRetVal = mFalse;
	}
	else
	{
		// Set data into Node
		pstNewNode->nVal = _nVal;
		pstNewNode->pstNext = NULL;

		// add data at the end of the list
		if (0 == _pstList->unCount)
		{
			// add data for the first time.
			_pstList->pstFront = pstNewNode;
			_pstList->pstRear  = pstNewNode;
			bRetVal = mTrue;
		}
		else
		{
			if (_pstList->unCount < UINT_MAX)
			{
				SllNode* pstLastNode = GetLastNode(_pstList);
				pstLastNode->pstNext = pstNewNode;
				_pstList->pstRear = pstNewNode;
				_pstList->unCount++;
				bRetVal = mTrue;
			}
			else
			{
				bRetVal = mFalse;
			}
		}
	}

	return bRetVal;
}