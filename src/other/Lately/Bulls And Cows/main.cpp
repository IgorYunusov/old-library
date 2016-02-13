/*************************************************************************
 *
 * FILE NAME : main.cpp
 *
 * ROLLRAT SOFTWARE NUMBER BASEBALL
 *
 *
 * LANGUAGE : C++11
 * VERSION  : ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.10.16
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include <iostream>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <vector> 
#include <cstdlib> 
#include <ctime>

// 2자리전용 프로그램입니다.
// 3자리 이상 적용시 설계상 문제가 발생할 수 있습니다. 

	// 컴퓨터 끼리 대결함
#define _COMPUTER_PVP

	// 무승부가 없음
#define _NO_DRAW

	// Computer1에 메뉴얼을 적용하지 아니함. 올 랜덤 출력
//#define _NO_MENUAL_C1

	// Computer2에 메뉴얼을 적용하지 아니함. 올 랜덤 출력
#define _NO_MENUAL_C2
	
	// 3번 답해서 못 맞출 경우 자동 패배. Computer 1 만
//#define _IN_THREE_GAME

using namespace std;

template<typename _ty> int delete_dup(vector<_ty>& vec)
{
	vector<_ty> temp;
	if (vec.empty())
		return 0;
	vec.erase(remove_if(vec.begin(), vec.end(), 
		[&temp](_ty x)->bool{
		for (auto temp : temp)
			if (temp == x)
				return true;
		temp.push_back(x);
		return false;}));
	return temp.size();
}

unsigned long make_int(int size)
{
	random_device rd;
	unsigned long mi = rd() + rd();
	vector<unsigned short> arroverlap, arrtemp;
	if (mi < ::pow(10, size))
		return 0;
	for (; mi; mi /= 10)
		arroverlap.push_back(mi % 10);
	arroverlap.erase(remove_if(arroverlap.begin(), arroverlap.end(), 
		[&](unsigned short x)->bool{
		for (auto temp : arrtemp)
			if (temp == x)
				return true;
		arrtemp.push_back(x);
		return false;}));
	if(arrtemp.size() >= size)
	{
		unsigned long ret = 0;
		if (arroverlap[0] == 0)
			return 0;
		for (auto tmp : arroverlap)
			if (!size--) return ret;
			else ret *= 10, ret += tmp;
	}
	return 0;
}

class new_random_device
	: public ::random_device
	{
public:
	size_t mod;

	explicit new_random_device(size_t mod) 
		: mod(mod)
		{
		}

	unsigned int operator()()
		{
		return __super::operator()() % mod;
		}

	};

// t에 포함된 숫자를 size만큼 무작위로 가져와 숫자를 만듬. 단, 맨 왼쪽의 숫자가 0일 경우 0을 반환
unsigned long make_int(vector<int> t, int size)
{
	//new_random_device rd(t.size());
	//random_shuffle(t.begin(), t.end(), rd);
	//auto engine = std::default_random_engine{};
	::random_shuffle(t.begin(), t.end(), [](int i)->int{ return ::rand() % i; });
	//::shuffle(t.begin(), t.end(), engine);
	unsigned long ret = 0;
	if (t[0] != 0)
		for (auto tmp : t)
			if (!size--) return ret;
			else ret *= 10, ret += tmp;
	return 0;
}

// user안에 포함된 모든 dest를 지운다.
void delete_in(vector<int>& user, int dest)
{
	user.erase(remove_if(user.begin(), user.end(),
		[&] (int s) -> bool {
			if (s == dest % 10)
				return true;
			else if (s == (dest / 10) % 10)
				return true;
			else
				return false;
		}));
}

void put_in(vector<int>& user, int dest)
{
	user.push_back(dest % 10);
	user.push_back((dest / 10) % 10);
}

template<typename _ty> vector<_ty>& get_dup(vector<_ty> left, vector<_ty> right)
{
	vector<_ty> ret;
	copy_if(left.begin(), left.end(), ret.begin(), 
		[&](_ty s)->bool {
			for (auto tmp : right)
				if (tmp == s)
					return true;
			return false;
		});
	return ret;
}

int make_user2(vector<int>& user, vector<int>& ball, vector<int>& strike)
{
	delete_dup(ball);
	delete_dup(strike);
	vector<int> dup = get_dup(ball, strike);
	if (dup.size() >= 2)
		return dup[0] + dup[1] * 10;
	else if (dup.size() == 1)
		return dup[0] * 10 + user[0];
	else if (dup.size() == 0)
		return user[1] * 10 + user[0];
	return 0;
}

// 벡터 x에 that이 포함된 경우 true를 출력, 아니면 x에 that을 삽입하고 false를 출력
bool if_in(vector<unsigned long>& x, unsigned long that)
{
	for (auto x_temp : x)
		if (x_temp == that)
			return true;
	x.push_back(that);
	return false;
}

#ifndef _COMPUTER_PVP
int main()
{
NEW_GAME:
	int rule;
	int length;
	cout << "숫자야구<0~9의 숫자>" << endl
		<< "방식 : 1. 나 vs 컴퓨터    2. 컴퓨터 vs 나   3. 컴퓨터 vs 컴퓨터" << endl;
RE_READ:
	cin >> rule;
	if (rule < 1 || rule > 3) {
		cout << "알 수 없는 방식!";
		goto RE_READ;
	}
	/////////////////////////////////////////////////////////////
RE_SET:
	cout << "숫자길이 : ";
	cin >> length;
	if(length > 8) {
		cerr << "숫자길이를 8이하로 설정하십시오." << endl;
		goto RE_SET;
	}
	else if(length < 1) {
		cerr << "숫자길이를 1이상으로 설정하십시오." << endl;
		goto RE_SET;
	}
	unsigned long real;
	for (; !(real = make_int(length));)
		;
#ifdef _DEBUG
	cout << real;
#endif

	if (rule == 1)
		goto COMPUTER;
	else if (rule == 2)
		goto USER;
	else if (rule == 3)
		goto CVS;
	/////////////////////////////////////////////////////////////
	// 나 vs 컴퓨터
COMPUTER:
	unsigned long save;
	int sido=0;
	for(;;){
		cout << endl << "예측한 숫자 : ";
		cin >> save;
		if (real == save)
			break;
		int ball=0, strike=0;
		for (int i=0, rmp=real, smp=save; smp && rmp; smp /= 10, rmp /= 10,i++)
			for (int tmp = real, j=0; tmp; tmp /= 10,j++)
				if(smp % 10 == tmp % 10)
				{
					if (i == j)
						strike++;
					else
						ball++;
					break;
				}
		if(ball)
			cout << "볼 : " << ball << "개" << endl;
		if(strike)
			cout << "스크라이크 : " << strike << "개" << endl;
		if (!ball && !strike)
			cout << "아웃!" << endl;
		sido++;
	}
	cout << "게임이 끝났습니다.";
	cout << "시도횟수 : " << sido;
	goto NEW_GAME;
	return 0;

	// 컴퓨터 vs 나
USER:
	if (length == 2)
	{
		vector<int> user1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, balls, strikes;
		cout << "아웃이면 o를, 스트라이크면 s횟수, 볼이면 b횟수를 입력하세요" << endl
			<< "ex) 2볼 2스트라이크면 b1s2 또는 s2 b1을 입력" << endl << endl;
		for (int count = 1;; count++){
			cout << "컴퓨터가 " << count << "번째로 내놓은 숫자 : " << real << endl << "";
			int ball = 0, strike = 0;
			char input[6];
			cin >> input;
			for(int i=0; i < 5;) {
				if (input[i] == 'o')
					break;
				else if (input[i] == 's')
					strike = input[i++ + 1] & 0xf;
				else if (input[i] == 'b')
					ball = input[i++ + 1] & 0xf;
				else
					i++;
			}
			////////////////////////////////////////////////////
			/*if (strike == 2)
				break;
			else if (ball == 2)
				real = user1[1] * 10 + user1[0];
			else if (ball == 1)
				put_in(balls, real);
			else if(strike == 1)
				put_in(strikes, real);
			else */if(ball == 0 && strike == 0)
				delete_in(user1, real);
			////////////////////////////////////////////////////
			real = make_user2(user1, balls, strikes);
		}
	}
	else
		cout << length << "자릿수는 현재 지원하지 않습니다." << endl << endl;
	cout << "게임이 끝났습니다." << endl << endl << endl;
	goto NEW_GAME;
	return 0;

	// 컴퓨터 vs 컴퓨터
CVS:
	goto NEW_GAME;
	return 0;
}
#else
int main()
{
	::srand ( unsigned ( ::time(0) ) );
	int repeate, c1win = 0, c2win = 0, mu=0, g=0, itgx=0,re;
	vector<int> computer1;
	vector<int> computer2;
RE_SET:
	int length;
	cout << "숫자길이 : ";
	cin >> length;
	if(length > 8) {
		cerr << "숫자길이를 8이하로 설정하십시오." << endl;
		goto RE_SET;
	}
	else if(length < 1) {
		cerr << "숫자길이를 1이상으로 설정하십시오." << endl;
		goto RE_SET;
	}
	cout << " 몇 번 돌릴거임? : ";
	cin >> repeate;
	for(re = repeate; repeate; repeate--){
#ifdef _NO_DRAW
	DRAW_RE_GAME:
#endif
		unsigned long c1, c2;
		vector<unsigned long> in1, in2;
		computer1={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		computer2={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (; !(c1 = make_int(computer1, length));)
			;
		for (; !(c2 = make_int(computer2, length));)
			;
#ifdef _DEBUG
		cout << "첫째값 : " << c1 << "  둘째값 : " << c2 << endl;
#endif
		//system("pause");
#ifdef _IN_THREE_GAME
		int itg = 0;
#endif
		bool cx = false;
		bool c1check = false, c2check = false;
		bool c1prewin = false, c2prewin = false;
		for(;;g++){
			if (cx)
			{
#ifdef _IN_THREE_GAME
			if (itg > 2)
				{
					itgx++;
					break;
				}
			itg++;
#endif
#ifdef _DEBUG
				cout << "	c1 get order" << endl;
#endif
				unsigned long rand;
				for(;;)
					{
					for (; !(rand = make_int(computer1, length));)
						;
					if (!if_in(in1, rand))
						break;
					}
#ifdef _DEBUG
				cout << "		c1 ask to c2 number : " << rand << endl;
#endif

				unsigned long ball=0, strike=0;
				for (unsigned long i=0, rmp=c1, smp=rand; smp && rmp; smp /= 10, rmp /= 10,i++)
					for (int tmp = c1, j=0; tmp; tmp /= 10,j++)
						if(smp % 10 == tmp % 10)
						{
							if (i == j)
								strike++;
							else
								ball++;
							break;
						}

				//////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
				cout << "		c2 repeate result" << endl;
				if(ball)
					cout << "			ball : " << ball << endl;
				if(strike)
					cout << "			strike : " << strike << endl;
				if (!ball && !strike)
					cout << "			out!" << endl;
				cout << "	c1 end order" << endl;
#endif
				if(strike == length || c1check)
				{
					if (c2prewin)
					{
#ifdef _DEBUG
					cout << "draw!!" << endl;
#endif
#ifndef	_NO_DRAW
						mu++;
#else
						goto DRAW_RE_GAME;
#endif
						break;
					}
					if (!c1prewin)
						c1prewin = true;
					else
					{
#ifdef _DEBUG
					cout << "c1 WIN!!" << endl;
#endif
						c1win++;
						break;
					}
				}
				else if (ball == length)
					c1check = true;
#ifndef _NO_MENUAL_C1
				else if (!ball && !strike)		// out인경우
					delete_in(computer1, rand);
#endif
				cx = false;
			}
			else
			{
#ifdef _DEBUG
				cout << "	c2 get order" << endl;
#endif
				unsigned long rand;
				for(;;)
					{
					for (; !(rand = make_int(computer2, length));)
						;
					if (!if_in(in2, rand))
						break;
					}
#ifdef _DEBUG
				cout << "		c2 ask to c1 number : " << rand << endl;
#endif

				unsigned long ball=0, strike=0;
				for (unsigned long i=0, rmp=c2, smp=rand; smp && rmp; smp /= 10, rmp /= 10,i++)
					for (int tmp = c2, j=0; tmp; tmp /= 10,j++)
						if(smp % 10 == tmp % 10)
						{
							if (i == j)
								strike++;
							else
								ball++;
							break;
						}
				
				
				//////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
				cout << "		c2 repeate result" << endl;
				if(ball)
					cout << "			ball : " << ball << endl;
				if(strike)
					cout << "			strike : " << strike << endl;
				if (!ball && !strike)
					cout << "			out!" << endl;
				cout << "	c2 end order" << endl;
#endif
				if(strike == length || c2check)
				{
					if (c1prewin)
					{
#ifdef _DEBUG
					cout << "draw!!" << endl;
#endif
#ifndef	_NO_DRAW
						mu++;
#else
						goto DRAW_RE_GAME;
#endif
						break;
					}
					if (!c2prewin)
						c2prewin = true;
					else
					{
#ifdef _DEBUG
					cout << "c2 WIN!!" << endl;
#endif
						c2win++;
						break;
					}
				}
				else if (ball == length)
					c2check = true;
#ifndef _NO_MENUAL_C2
				else if (!ball && !strike)
					delete_in(computer2, rand);
#endif
				cx = true;
			}
		}
	}
	cout << "컴퓨터1 이 승리한 횟수 : " << c1win << endl
		<< "컴퓨터2 가 승리한 횟수 : " << c2win << endl 
#ifndef _NO_DRAW
		<< "무승부 횟수 : " << mu << endl
#endif
#ifdef _IN_THREE_GAME
		<< "3번안에 끝나지 않은 경기 횟수 : " << itgx << endl
#endif
		<< "경기 횟수 : " << g << endl
		<< "컴퓨터1이 이길 확률 : " << c1win / (double)re << endl
		<< "컴퓨터2가 이길 확률 : " << c2win / (double)re;
	system("pause");
	return 0;
}
#endif