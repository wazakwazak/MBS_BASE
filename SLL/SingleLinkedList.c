#include "SingleLinkedList.h"
#include <stdlib.h>

mBool SllIsEmpty(SingleLinkedList* _pstList)
{
	// true: list it empty, false: list has some nodes.
	return 0 == _pstList->unCount ? mTrue : mFalse;
}

SllNode* SllGetLastNode(SingleLinkedList* _pstList)
{
	return _pstList->pstRear;
}

mUInt32 SllGetNodeIdxByValue(SingleLinkedList* _pstList, mInt32 _nVal)
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

mBool SllGetNodeValueByIndex(SingleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _pnVal)
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

mBool SllAddByValue(SingleLinkedList* _pstList, mInt32 _nVal)
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
			_pstList->unCount++;
			bRetVal = mTrue;
		}
		else
		{
			if (_pstList->unCount < UINT_MAX)
			{
				SllNode* pstLastNode = SllGetLastNode(_pstList);
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

mBool SllAddByIndex(SingleLinkedList* _pstList, mUInt32 _unIdx, mInt32 _nVal)
{
	mBool bRetVal = mFalse;
	SllNode* pstNewNode = NULL;
	pstNewNode = (SllNode*)malloc(sizeof(SllNode));

	if (NULL != pstNewNode)
	{
		pstNewNode->nVal = _nVal;
		pstNewNode->pstNext = NULL;
		if (0 == _unIdx)
		{
			// Front
			if (0 == _pstList->unCount)
			{
				_pstList->pstFront = pstNewNode;
				_pstList->pstRear = pstNewNode;
				bRetVal = mTrue;
			}
			else if (0 < _pstList->unCount)
			{
				pstNewNode->pstNext = _pstList->pstFront;
				_pstList->pstFront = pstNewNode;
				bRetVal = mTrue;
			}
		}
		else if (_unIdx >= _pstList->unCount)
		{
			// Rear
			_pstList->pstRear->pstNext = pstNewNode;
			_pstList->pstRear = pstNewNode;
			bRetVal = mTrue;
		}
		else
		{
			// middle
			SllNode* pstFastNode = _pstList->pstFront->pstNext;
			SllNode* pstSlowNode = _pstList->pstFront;

			mUInt32 unIdx = 1;
			for (unIdx = 1; unIdx < _pstList->unCount; unIdx++)
			{
				if (_unIdx == unIdx)
				{
					pstNewNode->pstNext = pstFastNode;
					pstSlowNode->pstNext = pstNewNode;
					bRetVal = mTrue;
					break;
				}
			}
		}
	}

	if (mTrue == bRetVal)
	{
		_pstList->unCount += 1;
	}

	return bRetVal;
}

mBool SllDeleteByValue(SingleLinkedList* _pstList, mInt32 _nVal)
{
	mBool bRetVal = mFalse;
	
	if (0 == _pstList->unCount)
	{
		bRetVal = mFalse;
	}
	else
	{
		SllNode* pstCurNode = _pstList->pstFront;
		SllNode* pstPreNode = NULL;

		mUInt32 unIdx = 0;
		if (NULL != pstCurNode)
		{
			for (unIdx = 0; unIdx < _pstList->unCount; unIdx++)
			{
				if (pstCurNode->nVal == _nVal)
				{
					if (0 == unIdx)
					{
						// front
						_pstList->pstFront = pstCurNode->pstNext;
						free(pstCurNode);
						_pstList->unCount--;
						bRetVal = mTrue;
					}
					else if (NULL == pstCurNode->pstNext)
					{
						// rear
						_pstList->pstRear = pstPreNode;
						_pstList->pstRear->pstNext = NULL;
						free(pstCurNode);
						_pstList->unCount--;
						bRetVal = mTrue;
					}
					else
					{
						// middle
						pstPreNode->pstNext = pstCurNode->pstNext;
						pstCurNode->pstNext = NULL;
						free(pstCurNode);
						_pstList->unCount--;
						bRetVal = mTrue;
					} // else
					break;
				} // if
				pstPreNode = pstCurNode;
				pstCurNode = pstCurNode->pstNext;
			} // for
		} // if
	}

	return bRetVal;
}

mBool SllDeleteByIndex(SingleLinkedList* _pstList, mUInt32 _nIdx)
{
	mBool bRetVal = mFalse;

	if (0 == _pstList->unCount)
	{
		bRetVal = mFalse;
	}
	else
	{
		if (0 == _nIdx)
		{
			// front
			SllNode* pstTempNode = _pstList->pstFront;
			_pstList->pstFront = pstTempNode->pstNext;
			if (_pstList->pstRear == pstTempNode)
			{
				_pstList->pstRear = pstTempNode->pstNext;
			}
			free(pstTempNode);
			_pstList->unCount--;
			bRetVal = mTrue;
		}
		else if (_nIdx >= _pstList->unCount)
		{
			// rear
			SllNode* pstCurNode = _pstList->pstRear;
			SllNode* pstPrevNode = _pstList->pstFront;

			while (pstCurNode != pstPrevNode->pstNext)
			{
				pstPrevNode = pstPrevNode->pstNext;
			}

			pstPrevNode->pstNext = NULL;
			_pstList->pstRear = pstPrevNode;
			pstCurNode->pstNext = NULL;
			free(pstCurNode);
			_pstList->unCount--;
			bRetVal = mTrue;
		}
		else
		{
			// middle
			SllNode* pstCurNode = _pstList->pstFront;
			SllNode* pstPrevNode = NULL;

			mUInt32 unIdx = 0;
			while (NULL != pstCurNode)
			{
				if (_nIdx == unIdx)
				{
					pstPrevNode->pstNext = pstCurNode->pstNext;
					pstCurNode->pstNext = NULL;
					free(pstCurNode);
					_pstList->unCount--;
					bRetVal = mTrue;
					break;
				}
				pstPrevNode = pstCurNode;
				pstCurNode = pstCurNode->pstNext;
				unIdx++;
			}
		}
	}

	return bRetVal;
}