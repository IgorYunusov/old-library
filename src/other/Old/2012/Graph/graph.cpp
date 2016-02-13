#include "iterator.h"
#include "literator.h"
#include "graph.h"

#include <iostream>

int main()
{
	char * iidx ="asdfasdfasdfasdfasdfads";

	// 일반 배열용 반복자
	iterator<iterator_base<char> > copy_x(iidx);

	// Head용 리스트
	llist<char> * x = new llist<char>;

	// 리스트의 시작을 표시함
	x->_Prev = x;

	// 링크드리스트용 반복자
	const_literator<llist<char> > t(x);
	const_literator<llist<char> > tx(x);

	// 임시 저장용 리스트 포인터
	llist<char>::str_pointer copy;
	copy = x;

	// 리스트 복사
	for( ; *copy_x; copy_x++)
	{
		copy->_Data = *copy_x;
		copy->_Next = new llist<char>;
		copy = copy->_Next;
	}

	// 전치영
	copy->_Data = '\0';
	
	// 리스트의 끝을 표시함
	copy->_Next = copy;
	
	// 반복자 출력(데이터, 현재 위치)
	for( ; *t; t++)
		std::cout << *t << tx - t << ' ';
	
	automata txx;

	char * iiidx = "a(d(f)a)sdfasdf(asfasdf)Asdfasd(asdfaasdf)f";

	for( ; *iiidx; iiidx++)
	{
		txx.push(*iiidx);
		if(*iiidx == '(')
			txx.save();
		else if(*iiidx == ')')
			txx.load();
	}

	automata::iterator txxx;
	int i = 0;

	for(txxx = txx.begin(); txxx != txx.end(); txxx++)
	{
		std::cout << txxx(0);
	}

	return 0;
}