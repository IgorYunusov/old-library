#include "iterator.h"
#include "literator.h"
#include "graph.h"

#include <iostream>

int main()
{
	char * iidx ="asdfasdfasdfasdfasdfads";

	// �Ϲ� �迭�� �ݺ���
	iterator<iterator_base<char> > copy_x(iidx);

	// Head�� ����Ʈ
	llist<char> * x = new llist<char>;

	// ����Ʈ�� ������ ǥ����
	x->_Prev = x;

	// ��ũ�帮��Ʈ�� �ݺ���
	const_literator<llist<char> > t(x);
	const_literator<llist<char> > tx(x);

	// �ӽ� ����� ����Ʈ ������
	llist<char>::str_pointer copy;
	copy = x;

	// ����Ʈ ����
	for( ; *copy_x; copy_x++)
	{
		copy->_Data = *copy_x;
		copy->_Next = new llist<char>;
		copy = copy->_Next;
	}

	// ��ġ��
	copy->_Data = '\0';
	
	// ����Ʈ�� ���� ǥ����
	copy->_Next = copy;
	
	// �ݺ��� ���(������, ���� ��ġ)
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