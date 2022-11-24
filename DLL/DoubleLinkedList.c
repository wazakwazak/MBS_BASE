#include "DoubleLinkedList.h"
#include <stdlib.h>

mBool IsEmpty(DoubleLinkedList* _pstList)
{
	// true: list it empty, false: list has some nodes.
	return 0 == _pstList->unCount ? mTrue : mFalse;
}

DllNode* GetLastNode(DoubleLinkedList* _pstList)
{
	// Return the last node of the list
	return _pstList->pstRear;
}

mBool GetNodeIdxByValue(DoubleLinkedList* _pstList, mInt32 _nVal, mUInt32* _punIdx)
{
	mBool bRetVal = mFalse;

	if (mTrue == IsEmpty(_pstList))
	{
		// The list is empty. Therefore, can not return any index value.
		bRetVal = mFalse;
	}
	else
	{
		// There are some nodes in the list, search the value.
		const DllNode* pstCurNode = (const DllNode*)_pstList->pstFront;
		mUInt32 unListCount = _pstList->unCount;
		mUInt32 unCountIdx = 0;
		for (unCountIdx = 0; unCountIdx < unListCount; unCountIdx++)
		{
			if (_nVal == pstCurNode->nVal)
			{
				*_punIdx = unCountIdx;
				bRetVal = mTrue;
				break;
			}

			pstCurNode = (const DllNode*)pstCurNode->pstNext;
		}

		if (unCountIdx == unListCount)
		{
			bRetVal = mFalse;
		}
	}

	return bRetVal;
}

mBool GetNodeValueByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _punVal)
{
	mBool bRetVal = mFalse;

	if (mTrue == IsEmpty(_pstList))
	{
		bRetVal = mFalse;
	}
	else
	{
		if (0 == _unIdx)
		{
			// first Node
			*_punVal = _pstList->pstFront->nVal;
			bRetVal = mTrue;
		}
		else if (_unIdx >= _pstList->unCount - 1)
		{
			// if _unIdx is better than or equal to the number of node counts, return last node's value.
			*_punVal = _pstList->pstRear->nVal;
			bRetVal = mTrue;
		}
		else
		{
			const DllNode* pstCurNode = (const DllNode*)_pstList->pstFront;
			mUInt32 unListCount = _pstList->unCount;
			mUInt32 unCountIdx = 0;
			for (unCountIdx = 0; unCountIdx < unListCount; unCountIdx++)
			{
				if (_unIdx == unCountIdx)
				{
					*_punVal = pstCurNode->nVal;
					bRetVal = mTrue;
					break;
				}
				pstCurNode = (const DllNode*)pstCurNode->pstNext;
			}

			if (unCountIdx == unListCount)
			{
				bRetVal = mFalse;
			}
		}
	}

	return bRetVal;
}

mBool AddbyValue(DoubleLinkedList* _pstList, mInt32 _nVal)
{
	mBool bRetVal = mFalse;

	// Add the new value at the end of the list

	DllNode* pstNewNode = NULL;
	pstNewNode = (DllNode*)malloc(sizeof(DllNode));

	if (NULL == pstNewNode)
	{
		bRetVal = mFalse;
	}
	else
	{
		// Set data into the node
		pstNewNode->nVal = _nVal;
		pstNewNode->pstNext = NULL;
		pstNewNode->pstPrev = _pstList->pstRear;

		if (mTrue == IsEmpty(_pstList))
		{
			// The list is empty. add the new data in the begining of the list
			_pstList->pstFront = pstNewNode;
			_pstList->pstRear  = pstNewNode;
			_pstList->unCount++;
			bRetVal = mTrue;
		}
		else
		{
			if (_pstList->unCount < UINT_MAX)
			{
				_pstList->pstRear->pstNext = pstNewNode;
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


mBool AddByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32 _nVal)
{
	mBool bRetVal = mFalse;

	// Add the new value at the index of the list

	DllNode* pstNewNode = NULL;
	pstNewNode = (DllNode*)malloc(sizeof(DllNode));

	if (NULL == pstNewNode)
	{
		bRetVal = mFalse;
	}
	else
	{
		pstNewNode->nVal = _nVal;
		pstNewNode->pstNext = NULL;
		pstNewNode->pstPrev = NULL;

		if (mTrue == IsEmpty(_pstList))
		{
			_pstList->pstFront = pstNewNode;
			_pstList->pstRear = pstNewNode;
			_pstList->unCount++;
			bRetVal = mTrue;
		}
		else
		{
			// Get Node
			DllNode* pstCurNode = NULL;

			if (0 == _unIdx)
			{
				// Front
				pstCurNode = _pstList->pstFront;

				pstNewNode->pstNext = pstCurNode;
				pstCurNode->pstPrev = pstNewNode;
				_pstList->pstFront = pstCurNode;
				_pstList->unCount++;
				bRetVal = mTrue;
			}
			else if (_unIdx >= _pstList->unCount)
			{
				// Rear
				_pstList->pstRear->pstNext = pstNewNode;
				pstNewNode->pstPrev = _pstList->pstRear;
				_pstList->pstRear = pstNewNode;
				_pstList->unCount++;
				bRetVal = mTrue;
			}
			else
			{
				// Middle

				pstCurNode = _pstList->pstFront;
				mUInt32 unListCount = _pstList->unCount;
				mUInt32 unCountIdx = 0;
				for (unCountIdx = 0; unCountIdx < unListCount; unCountIdx++)
				{
					if (_unIdx == unCountIdx)
					{
						break;
					}
					pstCurNode = pstCurNode->pstNext;
				}

				pstNewNode->pstNext = pstCurNode;
				pstNewNode->pstPrev = pstCurNode->pstPrev;
				pstCurNode->pstPrev->pstNext = pstNewNode;
				pstCurNode->pstPrev = pstNewNode;
				_pstList->unCount++;
				bRetVal = mTrue;
			}
		}
	}

	return bRetVal;
}

mBool DeleteByValue(DoubleLinkedList* _pstList, mInt32 _nVal)
{
	mBool bRetVal = mFalse;


	return bRetVal;
}

mBool DeleteByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx)
{
	mBool bRetVal = mFalse;

	

	return bRetVal;
}
