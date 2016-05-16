#include "stdafx.h"
#include "Heap.h"


/*
m_DataArr 

0 | 1 2 | 3 4 5 6 | ...

*/

CHeap::CHeap(int InitSize)
{
	float cnt=sqrt(InitSize);
	int IntegerVar = cnt;

	if (!(cnt >= IntegerVar - 0.0001f && cnt <= IntegerVar + 0.0001f))
		cnt = IntegerVar+1;

	m_capacity = pow(2, cnt);

	m_DataArr = new int[m_capacity];
	memset(m_DataArr, 0, sizeof(int)*cnt);


}


CHeap::~CHeap()
{
	if(m_DataArr)
		delete m_DataArr;
}

void CHeap::Add(int data)
{
	if (m_CurPos + 1 == m_capacity){
		m_DataArr=(int*)realloc(m_DataArr, sizeof(int)* m_capacity * 2);

		m_DataArr = (int*)realloc(m_DataArr, sizeof(int)* m_capacity * 2);
		memset(&m_DataArr[m_CurPos+1], 0, sizeof(int)*m_capacity);
		m_capacity *= 2;
	}

	int posIdx = m_CurPos+1;
	int parentIdx = getParent(posIdx);

	if (posIdx <= 0)
	{
		m_DataArr[posIdx] = data;
		m_CurPos=posIdx;
		return;
	}

	if (data == m_DataArr[parentIdx])
		return;

	m_DataArr[posIdx] = data;

	while (posIdx>0)
	{
		if (m_DataArr[parentIdx] > m_DataArr[posIdx])
		{
			swap(&m_DataArr[parentIdx], &m_DataArr[posIdx]);
		}
		posIdx = parentIdx;
		parentIdx = getParent(posIdx);
	}

	m_CurPos++;
}

int CHeap::pop()
{
	int retVal=0;
	int selectedIdx = 0;
	int LeftIdx = 0, RightIdx = 0;
	int tmpPosIdx =0;


	if (m_CurPos == -1)
		return -1;

	retVal = m_DataArr[0];

	LeftIdx = getChildIdx(0);
	RightIdx = LeftIdx + 1;

	swap(&m_DataArr[0], &m_DataArr[m_CurPos]);
	m_DataArr[m_CurPos] = 0;

	m_CurPos--;

	while (LeftIdx <= m_CurPos)
	{
		if (RightIdx > m_CurPos)
		{
			selectedIdx = LeftIdx;
		}
		else
		{
			selectedIdx = m_DataArr[LeftIdx] < m_DataArr[RightIdx] ? LeftIdx : RightIdx;
		}

		if(m_DataArr[tmpPosIdx] < m_DataArr[selectedIdx]){
			return retVal;
		}

		swap(&m_DataArr[tmpPosIdx], &m_DataArr[selectedIdx]);
		tmpPosIdx = selectedIdx;

		LeftIdx = getChildIdx(selectedIdx);
		RightIdx = LeftIdx + 1;
	}

	return retVal; 
}

void CHeap::Print()
{
	if (m_CurPos <= -1)
		return;

	for (int i = 0; i <= m_CurPos; ++i)
	{
		printf("%d ", m_DataArr[i]);
	}
	puts("");

	getchar();
}


void CHeap::clear()
{
	for (int i = 0; i < m_CurPos; ++i)
		m_DataArr[i] = 0;
}

int CHeap::getParent(int idx)
{
	/*
	if (idx == 0 || idx==1 || idx==2 )
		return 0;

	return (idx % 2) == 0 ? (idx / 2) - 1 : (idx / 2);
	*/
	return (idx - 1) / 2;
}

int CHeap::getChildIdx(int idx)
{
	return idx*2+1;
}

void CHeap::swap(int * A, int * B)
{
	*A ^= *B;
	*B ^= *A;
	*A ^= *B;
}
