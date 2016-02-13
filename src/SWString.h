#pragma once
#include <tchar.h>
#include <iostream>
#include <string>
#include <memory.h>
#define wc wchar_t
#define sofw sizeof(wc)
#define on const
#define ons on wc
namespace Utility{
class StringReferencePutWith{};class sws final{wc*s;wc*l;size_t $;
StringReferencePutWith with;bool r=false;public:sws():$(0),s(nullptr),l(s){}
sws(ons*ptr){InitString(ptr);}sws(wc*ptr,size_t len):$(len),s(ptr),l(ptr+len-1),r(true){}
sws(wc*ptr, size_t len, StringReferencePutWith):$(len),s(ptr),l(ptr+len-1){}sws(ons*ptr,
size_t len):$(len){s=new wc[$+1];l=s+$-1;memcpy(s,ptr,$*sofw);l[1]=0;}sws(on sws&cnt):
sws((ons*)cnt.s,cnt.$){}sws(std::wstring&str):sws(&str[0],str.length()){}sws(on
std::wstring&wstr):sws(wstr.c_str(),wstr.length()){}~sws(){if(s!=nullptr&&!r){delete[]s;s=nullptr;}}inline 
size_t Length()on{return $;}inline bool Empty()on{return $==0;}inline bool Full()on{return $>0;}inline bool 
Null() on{return s==nullptr;}inline ons*Reference()on{return s;}static sws Concat(on
sws&t1,on sws& t2){if(t1.Empty()){if(t2.Empty()){return sws();}return sws((ons*)
t2.s,t2.$);}if (t2.Empty()){return sws((ons*)t1.s,t1.$);}size_t n=t1.$+t2.$;wc*m=new
wc[n+1];memcpy(m, t1.s, t1.$*sofw);memcpy(m+t1.$,t2.s,t2.$*sofw);m[n]=0;StringReferencePutWith with;
return sws(m,n,with);}static sws Concat(on sws&t1,on sws&t2,on sws&t3){if (t1.Empty()&&t2.Empty()
&&t3.Empty()){return sws();}size_t n=t1.$+t2.$+t3.$;wc*m;m=new wc[n+1];memcpy(m,t1.s,t1.$*sofw);
memcpy(m+t1.$,t2.s,t2.$*sofw);memcpy(m+t1.$+t2.$,t3.s, t3.$ * sofw);m[n]=0;StringReferencePutWith with;
return sws(m,n,with);}static sws Concat(on sws&t1,on sws&t2,on sws&t3,on sws&t4){if(t1.Empty()&&t2.Empty()
&&t3.Empty()&& t4.Empty()){return sws();}size_t n=t1.$+t2.$+t3.$+t4.$;wc*m;m=new wc[n+1];memcpy(m,
t1.s,t1.$*sofw);memcpy(m+t1.$,t2.s,t2.$*sofw);memcpy(m+t1.$+t2.$,t3.s,t3.$*sofw);memcpy(m+t1.$+t2.$+t3.$,t4.s,
t4.$* sofw);m[n]=0;StringReferencePutWith with;return sws(m,n,with);}inline bool Equal(on wc *str) 
on{size_t strlen=wcslen(str);if(strlen==$)return!memcmp(s,str,$*sofw);return false;}inline bool Equal(on 
sws&r)on{if(r.$!=this->$)return false;return!memcmp(s,r.s,$*sofw);}inline bool operator==(ons*ptr)on{
return Equal(ptr);}inline bool operator==(on sws&r)on{return Equal(r);}inline bool operator!=(ons *ptr)
on{return!Equal(ptr);}inline bool operator!=(on sws&r)on{return!Equal(r);}sws operator&(on sws&c){return
this->Concat(*this,c);}sws operator+(on sws&c){return this->Concat(*this,c);}inline bool operator>(on sws&e){
return wcscmp(s, e.s) > 0;}inline bool operator<(on sws&e){return wcscmp(s,e.s) < 0;}inline bool operator>=(
on sws&e){return!this->operator<(e);}inline bool operator<=(on sws&e){return !this->operator>(e);}inline 
wc *ToArray(){wc *ret=new wc[$+1];memcpy(ret,s,($+1)*sofw);return ret;}inline ons *ToArray()
on{wc *ret = new wc[$+1];memcpy(ret,s,($+1)*sofw);return ret;}friend std::wostream& operator<<(
std::wostream& os,const sws&refer);private:void InitString(ons*str){$=wcslen(str);s=new wc[$+1];
l=s+$-1;memcpy(s,str,($+1)*sofw);}};typedef sws SWString;}