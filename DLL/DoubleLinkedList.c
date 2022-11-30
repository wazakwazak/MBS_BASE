#include "DoubleLinkedList.h"
#include <stdlib.h>

mBool DllIsEmpty(DoubleLinkedList* _pstList)
{
	// true: list it empty, false: list has some nodes.
	return 0 == _pstList->unCount ? mTrue : mFalse;
}

DllNode* DllGetLastNode(DoubleLinkedList* _pstList)
{
	// Return the last node of the list
	return _pstList->pstRear;
}

mBool DllGetNodeIdxByValue(DoubleLinkedList* _pstList, mInt32 _nVal, mUInt32* _punIdx)
{
	mBool bRetVal = mFalse;

	if (mTrue == DllIsEmpty(_pstList))
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

mBool DllGetNodeValueByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32* _punVal)
{
	mBool bRetVal = mFalse;

	if (mTrue == DllIsEmpty(_pstList))
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

mBool DllAddbyValue(DoubleLinkedList* _pstList, mInt32 _nVal)
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

		if (mTrue == DllIsEmpty(_pstList))
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


mBool DllAddByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx, mInt32 _nVal)
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

		if (mTrue == DllIsEmpty(_pstList))
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

mBool DllDeleteByValue(DoubleLinkedList* _pstList, mInt32 _nVal)
{
	mBool bRetVal = mFalse;

	if (mTrue == DllIsEmpty(_pstList))
	{
		// there is no data in the list
		bRetVal = mFalse;
	}
	else
	{
		if (_nVal == _pstList->pstFront->nVal)
		{
			// front
			DllNode* pstTemp = _pstList->pstFront;

			if (NULL == _pstList->pstFront->pstNext)
			{
				_pstList->pstFront = NULL;
				_pstList->pstRear = NULL;
			}
			else
			{
				_pstList->pstFront->pstNext->pstPrev = NULL;
				_pstList->pstFront = _pstList->pstFront->pstNext;
			}

			_pstList->unCount--;
			free(pstTemp);
			bRetVal = mTrue;
		}
		else if (_nVal == _pstList->pstFront->nVal)
		{
			// rear
			DllNode* pstTemp = _pstList->pstRear;
			_pstList->pstRear = pstTemp->pstPrev;
			_pstList->pstRear->pstNext = NULL;
			pstTemp->pstPrev = NULL;
			_pstList->unCount--;
			free(pstTemp);
			bRetVal = mTrue;
		}
		else
		{
			// middle
			DllNode* pstTemp = _pstList->pstFront->pstNext;

			while (NULL != pstTemp)
			{
				if (_nVal == pstTemp->nVal)
				{
					break;
				}
				pstTemp = pstTemp->pstNext;
			}

			if (NULL == pstTemp)
			{
				// there is no the same data. could not find the value
				bRetVal = mTrue;
			}
			else
			{
				pstTemp->pstPrev->pstNext = pstTemp->pstNext;
				pstTemp->pstNext->pstPrev = pstTemp->pstPrev;
				pstTemp->pstNext = NULL;
				pstTemp->pstPrev = NULL;
				free(pstTemp);
				_pstList->unCount--;
				bRetVal = mTrue;
			}
		}
	}

	return bRetVal;
}

mBool DllDeleteByIndex(DoubleLinkedList* _pstList, mUInt32 _unIdx)
{
	mBool bRetVal = mFalse;

	if (mTrue == DllIsEmpty(_pstList))
	{
		// There is no data in the list.
		bRetVal = mFalse;
	}
	else
	{
		if (0 == _unIdx)
		{
			// Front
			DllNode* pstTemp = _pstList->pstFront;

			if (NULL == _pstList->pstFront->pstNext)
			{
				_pstList->pstFront = NULL;
				_pstList->pstRear = NULL;
			}
			else
			{
				_pstList->pstFront->pstNext->pstPrev = NULL;
				_pstList->pstFront = _pstList->pstFront->pstNext;
			}
			free(pstTemp);
		}
		else if (_unIdx >= _pstList->unCount - 1)
		{
			// Rear
			DllNode* pstTemp = _pstList->pstRear;
			_pstList->pstRear = pstTemp->pstPrev;
			_pstList->pstRear->pstNext = NULL;
			pstTemp->pstPrev = NULL;
			free(pstTemp);
		}
		else
		{
			// Middle
			DllNode* pstTemp = _pstList->pstFront;
			unsigned int unIdx = 0;
			for (unIdx = 0; unIdx < _unIdx; unIdx++)
			{
				pstTemp = pstTemp->pstNext;
			}

			pstTemp->pstPrev->pstNext = pstTemp->pstNext;
			pstTemp->pstNext->pstPrev = pstTemp->pstPrev;
			pstTemp->pstNext = NULL;
			pstTemp->pstPrev = NULL;
			free(pstTemp);
		}
		_pstList->unCount--;
		bRetVal = mTrue;
	}

	return bRetVal;
}
