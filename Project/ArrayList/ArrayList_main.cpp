#include "ArrayList.h"
/*
	std::vector에 대한 기본 바탕이 되는게 ArrayList인듯.
	리스트는 참조가 O(1)이다. 인덱스 기준으로 바로 접근 가능(=배열)

	stack 혹은 queue와 굉장히 비슷해보이는데,
	가장 큰 차이는 중간 삽입, 중간 삭제가 가능하다는 점이다.
	stack은 후입선출 LIFO, queue는 선입선출 FIFO 구조이다.
	하지만 모두다 정적 배열을 이용했기에 크기에 제한적이다. 변경 불가능.
	
	물론, 리스트에서 이 부분을 동적할당으로 한다면 크기 제한이 사라진다.
	더 나아가 IsFull 함수의 역할이 사라진다. 끝이 없으니까.
	그 대신 새로운 메모리를 재 할당하는 과정이 존재하고,
	기존의 메모리를 해제하는 과정을 필요로 한다.

	std::vector 는 위와 같은 재할당 구조로 설계되어 있다.

	참고로 이렇게 추가적으로 재할당하는 구조가 아니라,
	매번 새로운 데이터를 추가할때마다 추가 동적할당을 하는 형태가 연결리스트 형태이다.
	2019, August, 17.

	Copyright 2019. SungHoon Kim. All rights reserved.
*/

int main()
{
	ArrayList arrList;
	std::cout << "현재 리스트 크기는 : " << arrList.GetSize() << std::endl;
	
	arrList.Insert(3, 5); // 5
	arrList.Insert(1, 1); // 5 1
	arrList.Insert(2, 3); // 5 1 3
	arrList.Print();
	arrList.Insert(0, 4); // 4 5 1 3

	arrList.Remove(2); // 4 5 3
	arrList.Remove(1); // 4 3
	arrList.Print();
	std::cout << "현재 리스트 크기는 : " << arrList.GetSize() << std::endl;

	arrList.Find(3);
	arrList.Find(5);

	return 0;
}