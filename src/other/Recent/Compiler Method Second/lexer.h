#ifndef _LEXER_
#define _LEXER_

#include <string>
#include <hash_map>
#include <functional>

typedef enum class _dummy_ {
    AND = 256,
    BASIC,
    BREAK,
    DO,
    ELSE,
    EQ,
    _FALSE,
    GE,
    ID,
    IF,
    INDEX,
    LE,
    MINUS,
    NE,
    NUM,
    OR,
    REAL,
    TEMP,
    _TRUE,
    WHILE,
}   TAG;

class Token
{
public:
    const TAG tag;
    Token(TAG t)  : tag(t) {}
    std::string to_string() { return std::to_string((int)tag); }
};

class Num
    : public Token
{
public:
    const int value;
    Num(int v) : Token(TAG::NUM), value(v) {}
    std::string to_string() { return std::to_string(value); }
};

class Word
    : public Token
{
public:
    std::string lexeme = "";
    Word(std::string s, TAG tag) : Token(tag), lexeme(s) {}
    std::string to_string() { return lexeme; }

};

static Word *and = new Word("&&", TAG::AND);
static Word *or = new Word("||", TAG::OR);
static Word *eq = new Word("==", TAG::EQ);
static Word *ne = new Word("!=", TAG::NE);
static Word *le = new Word("<=", TAG::LE);
static Word *ge = new Word(">=", TAG::GE);
static Word *minus = new Word("minus", TAG::MINUS);
static Word *_true = new Word("true", TAG::_TRUE);
static Word *_false = new Word("false", TAG::_FALSE);
static Word *temp = new Word("t", TAG::TEMP);

/////////////////////////////////////////////////////

class Real
    : public Token
{
public:
    const double value;
    Real(double v) : Token(TAG::REAL), value(v) {}
    std::string to_string() { return std::to_string(value); }
};

typedef struct _dstt_ {
    std::string lexeme;
    Word *w;
}   LexerHashtableNode;

class LexerHashtable
{
    std::hash_map<size_t, LexerHashtableNode *> map;
        std::hash<std::string> hash_func;
public:

    void put(Word *w)
    {
        LexerHashtableNode *vstt = new LexerHashtableNode;
        vstt->lexeme = w->lexeme;
        vstt->w = w;
        map.insert(std::hash_map<size_t, LexerHashtableNode *>::value_type
            (hash_func(w->lexeme), vstt));
    }

    bool isin(std::string lexeme)
    {
        if (map.find(hash_func(lexeme)) != map.end())
            return true;
        return false;
    }

    LexerHashtableNode *get(std::string lexeme)
    {
        auto find = map.find(hash_func(lexeme));
        if (find != map.end())
            return find->second;
        return nullptr;
    }
};

/////////////////////////////////////////////////////

class Lexer 
{
public:
    int line;
    char peek;

    LexerHashtable words;
    void reserve(Word *w) {words.put(w);}
    const char *peek_ptr;

    Lexer() {
        line = 1;
        peek = ' ';
        reserve(new Word("if", TAG::IF));
        reserve(new Word("else", TAG::ELSE));
        reserve(new Word("while", TAG::WHILE));
        reserve(new Word("do", TAG::DO));
        reserve(new Word("break", TAG::BREAK));
        reserve(_true);
        reserve(_false);
        //reserve(_int);
        //reserve(_char);
        //reserve(_bool);
        //reserve(_float);
    }
    void setpeek(const char *ptr) {peek_ptr = ptr;}
    void readch() { peek = *peek_ptr++; }
    bool readch(char c) {
        readch();
        if (peek != c)
            return false;
        peek = ' ';
        return true;
    }
    Token *scan() {
        for( ; ; readch()) {
            if (peek == ' ' || peek == '\t') continue;
            else if (peek == '\n') line++;
            else break;
        }
        switch(peek) {
        case '&':
            if (readch('&')) return and; else return new Token((TAG)'&');
        case '|':
            if (readch('|')) return or; else return new Token((TAG)'|');
        case '=':
            if (readch('=')) return eq; else return new Token((TAG)'=');
        case '!':
            if (readch('=')) return ne; else return new Token((TAG)'!');
        case '<':
            if (readch('=')) return le; else return new Token((TAG)'<');
        case '>':
            if (readch('=')) return ge; else return new Token((TAG)'>');
        }
        if(isdigit(peek)) {
            int v = 0;
            do {
                v *= 10;
                v += peek - '0';
                readch();
            } while (isdigit(peek));
            if (peek != '.') return new Num(v);
            double x = v; double d = 10.0f;
            for(;;) {
                readch();
                if (!isdigit(peek))
                    break;
                x += (peek - '0') / d;
                d *= 10.0f;
            }
            return new Real(x);
        }
        if(isalpha(peek)) {
            std::string str;
            do {
                str.push_back(peek);
                readch();
            } while (isalnum(peek));
            if (words.isin(str))
                return (Word *)words.get(str)->w;
            Word *n = new Word(str, TAG::ID);
            words.put(n);
            return n;
        }
        Token *tok = new Token((TAG)peek);
        peek = ' ';
        return tok;
    }
};


/////////////
/////////////
/////////////
/////////////
/////////////

//typedef struct _dstt_ {
//    Token *w;
//    Id *i;
//}   EnvHashtableNode;
//
//class EnvHashtable
//{
//    std::hash_map<size_t, EnvHashtableNode *> map;
//        std::hash<std::string> hash_func;
//public:
//
//    void put(Word *w)
//    {
//        EnvHashtableNode *vstt = new EnvHashtableNode;
//        vstt->lexeme = w->lexeme;
//        vstt->w = w;
//        map.insert(std::hash_map<size_t, EnvHashtableNode *>::value_type
//            (hash_func(w->lexeme), vstt));
//    }
//
//    bool isin(std::string lexeme)
//    {
//        if (map.find(hash_func(lexeme)) != map.end())
//            return true;
//        return false;
//    }
//
//    EnvHashtableNode *get(std::string lexeme)
//    {
//        auto find = map.find(hash_func(lexeme));
//        if (find != map.end())
//            return find->second;
//        return nullptr;
//    }
//};
//
//class Env 
//{
//    EnvHashtable table;
//protected: Env *prev;
//public:
//    Env(Env *n) : prev(n) { }
//    void put(Token w, Id i) {
//    }
//};

#endif