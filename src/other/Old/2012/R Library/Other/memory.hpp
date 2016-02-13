//apvl private package [UNRELEASED PROJECT]
//
//ROLLRAT MEMORY.hpp
#ifndef __APVL_MEMORY
#define __APVL_MEMORY

template<class _operator_type> class
	__udt_block
	{ // {Unlimited intervene Dest To} String
    _operator_type _stp;
public:
	void operator()(_operator_type rl)
		{ // put all
			_stp = rl;
		}
	_operator_type& operator*()
		{ // get all
			return _stp;
		}
	template<class _operator_type_address>
		_operator_type_address operator&()
		{ // get address
			return &reinterpret_cast<const char &>(_stp);
		}
	};

#endif