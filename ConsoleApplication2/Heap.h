#pragma once
class CHeap
{
public:
	//whatever initSize is not power of 2, this func will auto expand the size correctly.
	CHeap(int InitSize);
	
	//delete that dynamically created memory.
	virtual ~CHeap();

	void Add(int data);
	int pop();

	void Print();

	void clear();



	

private:
	int getParent(int idx);
	int getChildIdx(int idx);
	void swap(int* A, int* B);


private:
	int *m_DataArr=nullptr;
	int m_capacity = 0;
	int m_CurPos = -1;
};

