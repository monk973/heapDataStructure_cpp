// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
