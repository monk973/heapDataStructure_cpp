// ConsoleApplication2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Heap.h"

void main()
{
	CHeap heap(1);


	heap.Add(10);
	heap.Add(9);

	heap.Add(8);



	heap.Add(7);
	heap.Add(6);

	heap.Print();
	
	//
	//

	heap.pop();

	heap.Print();
	//
	//
	heap.pop();

	heap.Print();

	//
	//

	heap.pop();

	heap.Print();

	//
	//

	heap.pop();

	heap.Print();

	//
	//

	heap.pop();

	heap.Print();

	heap.clear();


	getchar();
}
