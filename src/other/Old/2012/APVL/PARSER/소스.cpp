#include "equation_postfix.h"
#include <stdio.h>

int main()
{
	const char *x = "5+4*6-1"; 
	const char *operand = _EQUATION_OPERAND;
	const char *salvot = _EQUATION_SALVOT;
	____tx__parse__limited<char> tpl;		// 과정 진행용, 마지막 리턴용
	____tx__parse__limited<char *> tplx;	// 과정 저장용
	____tx__parse__limited<char> xtx;		// 오퍼렌드 저장용
	const char *ptr = x;
	for( ; *ptr; ptr++)
		if(one_match(operand, *ptr))		// 식의 위치가 오퍼렌드이다면(단, 오퍼렌드는 기호를 의미하고 1단위 이다.)
			tpl.push_back(*ptr),			// 기호발견시 뒤로 넣는다.
			tplx.push_back(&tpl),			// x에 추가한다.
			tpl.deletenone();				// deletenone으로 포인터 변수상 해제시킨다.
		else if(one_match(salvot, *ptr))
			;								// 여기에 괄호처리를 위한 코드를 추가하십시오.
		else
			tpl.push_back(*ptr);			// 뒤에다 구겨넣자.
	tplx.push_back(&tpl);					// 마지막 남은 비 오퍼렌드
	tpl.deletenone();						// 변수상 해제
	for( ; tplx.get_one(); )				// 뒤로 넣었으니 앞으로 뺌
	{
		for( ; !one_match(operand, *tplx.front()); tplx.front()++)
			tpl.push_back(*tplx.front());
		xtx.push_back(*(++tplx.front()));
		tplx.pop_front();
	}
	for( ; *xtx; )
		tpl.push_back(xtx.pop_front());
	tpl.push_back('\0');
	
	printf_s(&tpl);
	return 0;
}