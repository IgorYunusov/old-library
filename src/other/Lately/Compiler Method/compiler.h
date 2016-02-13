#ifndef _COMPILER_
#define _COMPILER_

#include <string>

class Tag {
public: static const int
			AND = 256, BAISC = 257, BREAK = 258, DO = 259, ELSE = 260,
			EQ = 261, _FALSE = 262, GE = 263, ID = 264, IF = 265,
			INDEX = 266, LE = 267, MINUS = 268, NE = 269, NUM = 270,
			OR = 271, REAL = 272, TEMP = 273, _TRUE = 274, WHILE = 275;
};

class Token {
public:
	const int tag;
	Token(const int t) : tag(t) {}
	std::string toString(){ return "" + (char)tag; }
};

class Num :
	public Token {
public:
	const int value;
	Num(int v) :value(v), Token(Tag::NUM) {}
	std::string toString(){ return "" + value; }
};

//class Word :
//	public Token {
//public:
//	typedef class Word _MyC;
//	std::string lexeme = "";
//	Word(std::string s, int tag) :Token(tag), lexeme(s){}
//	std::string toString() { return lexeme; }
//	static const _MyC *and = new _MyC("&&", Tag::AND)//, or = new Word("||", Tag::OR)
//		;
//};

#endif