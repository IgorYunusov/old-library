// rollrat v string
#ifndef vstirng
#define vstirng
#include "vector.h"
_X_LIB_BEGIN

template<class _Ty0> inline
    int strlen(_Ty0 that)
    { // strlen
    for( int i = 0; ; )
        if(!that[++i])
            return i;
    }

template<typename _Ty0>
    _Ty0*& itoas(int i)
    { // itoa
    static _Ty0 buf[21];
    _Ty0 *p = buf + 19 + 1;
    if (i >= 0) 
        {while (i != 0)
            *--p = '0' + (i % 10), i /= 10;
        return p;}
    else{while (i != 0)
            *--p = '0' - (i % 10), i /= 10;
        *--p = '-';}
    return p;
    }
 
template<class _String_Element = char>
    class string
    { // string class
 
    vector<_String_Element> str;
    bool reverses;
 
    public:
 
        string()
            : reverses(false)
            { }
 
        string(_String_Element* _valuable_char)
            : reverses(false)
            { // entry
            char_put(_valuable_char);
            }
 
        string(const _String_Element* _const_char)
            : reverses(false)
            { // entry
            char_put(const_cast<_String_Element*> (_const_char));
            }
 
        inline _String_Element& operator[](int pos)
            { // operator[]
            if(!reverses)
                return str[pos];
            else
                return str(pos);
            }
 
        inline void reverse()
            { // str reverse
            reverses = true;
            }
 
        inline int lenth()
            { // length
            return str.size();
            }
 
        _String_Element* operator*()
            { // operator *
            int len = lenth();
            _String_Element *ret = new _String_Element[len];
            if(!reverses)
                for(int n = 0; n < len; n++)
                    ret[n] = str[n]->_DATA;
            else
                for(int n = 0; n < len; n++)
                    ret[n] = str(n)->_DATA;
            ret[len] = 0;
            return ret;
            }
 
        inline void operator+=(_String_Element* _valuable_char)
            { // operator +=
            char_put(_valuable_char);
            }
 
        inline void operator+=(const _String_Element* _const_char)
            { // operator +=
            char_put(const_cast<_String_Element*> (_const_char));
            }
 
        inline void operator+=(int _valuable_int)
            { // operator +=
            char_put(itoas(_valuable_int));
            }
 
        inline vector<_String_Element> &ch_n()
            { // vector return
            return str;
            }
 
        string<_String_Element> &operator<(_String_Element *get)
            { // operator +=
            char_put(get);
            return *this;
            }
 
        string<_String_Element> &operator<(const _String_Element *get)
            { // operator +=
            char_put(const_cast<_String_Element*> (get));
            return *this;
            }
 
        string<_String_Element> &operator<(string<_String_Element> &get)
            { // operator +=
            char_put(*get);
            return *this;
            }
 
        string<_String_Element> &operator>(_String_Element *get)
            { // operator +=
            char_put_r(get);
            return *this;
            }
 
        string<_String_Element> &operator>(const _String_Element *get)
            { // operator +=
            char_put_r(const_cast<_String_Element*> (get));
            return *this;
            }
 
        string<_String_Element> &operator>(string<_String_Element> &get)
            { // operator +=
            char_put_r(*get);
            return *this;
            }

    private:
 
        inline void char_put(_String_Element *_char)
            { // char put
            int f = strlen(_char);
            if(!reverses)
                for(int i = 0; i < f; i++)
                    str.push_back(_char[i]);
            else
                for(int i = 0; i < f; i++)
                    str.push_front(_char[i]);
            }
 
        inline void char_put_r(_String_Element *_char)
            { // char put
            int f = strlen(_char);
            if(!reverses)
                for(int i = 0; i < f; i++)
                    str.push_front(_char[i]);
            else
                for(int i = 0; i < f; i++)
                    str.push_back(_char[i]);
            }
 
    };

_X_LIB_END

#endif