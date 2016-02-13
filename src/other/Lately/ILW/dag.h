/*************************************************************************
 *
 * FILE NAME : dag.h - Directed acyclic graph
 *
 * Interactive Legibility Works
 *
 *
 * CREATION : 2014.11.17
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _DAG_
#define _DAG_

#include "ilw.h"
#include <vector>

namespace ILW {
	
	namespace Control {

		typedef unsigned int	DAGKEY, *PDAGKEY;


		ILW_ANCOMP("option:start")
		// automaton machine start position
		class start_automaton {
		};

		ILW_ANCOMP("option:end")
		// automaton machine end position
		class end_automaton {
		};

		ILW_ANCOMP("option:std")
		// automaton machine middle position
		class std_automaton {
		};

		// pure automaton
		class _automaton {
		};


		template<class _AutomatonT> class _automaton_machine_base {
		public:
			_AutomatonT *automata;
			DAGKEY key;
		};
		
		// base automaton node
		template<class _Ty, class _Automatonopt> class _automaton_node
			: public _automaton_machine_base<_automaton_node<_Ty, _Automatonopt>> {
		};
		
		ILW_ANCOMP("option:start")
		template<class _Ty> class _automaton_node<_Ty, start_automaton> 
			: public _automaton_machine_base<_automaton_node<_Ty, start_automaton>> {
		public:
			typedef _automaton_node<_Ty, start_automaton> type;
			_automaton_node<_Ty, std_automaton> *next;
		};
			
		ILW_ANCOMP("option:end")
		template<class _Ty> class _automaton_node<_Ty, end_automaton> 
			: public _automaton_machine_base<_automaton_node<_Ty, end_automaton>> {
		public:
			typedef _automaton_node<_Ty, end_automaton> type;
			_automaton_node<_Ty, std_automaton> *prev;
		};
			
		ILW_ANCOMP("option:std")
		template<class _Ty> class _automaton_node<_Ty, std_automaton> 
			: public _automaton_machine_base<_automaton_node<_Ty, std_automaton>> {
		public:
			typedef _automaton_node<_Ty, std_automaton> type;
			size_t size;
			_REF vector<_automaton_machine_base<type *>> automata;
		};

		template<class _Ty> class automaton_base {
		public:
			bool	expandable;
			size_t	fit;
		};

			// template Automaton Machine class
		template<class _Func> class automaton : public automaton_base<_Func> {
		public:
			typedef automaton<_Func> CType;
			typedef _automaton_node<_Func, _automaton> auto_node;
			typedef _automaton_node<_Func, std_automaton> auto_std;
			typedef _automaton_node<_Func, start_automaton> auto_start;
			typedef _automaton_node<_Func, end_automaton> auto_end;

			// S, E automaton circle
			auto_start	*start;
			auto_end	*end;

			// automaton in between S and E
			_REF vector<auto_std *> last;

			size_t count;

			automaton() {
				auto_std *tmp_std = new auto_std;

				tmp_std->size = 0;

				start = new auto_start;
				start->next = tmp_std;

				end = new auto_end;
				end->prev = tmp_std;

				last.push_back(tmp_std);

				this->expandable = true;
			}

			automaton(size_t fit) {
				if (fit > ARRAY_MAXSIZE)
					_ILW ErrorHandler(L"Automaton size is too large.").assert_error();

				automaton();

				this->fit = fit;
				this->expandable = false;
			}

			~automaton() {
				delete end;
				delete start;
			}

				// non-fit cast
			explicit automaton(const CType& this_type) {
				start = this_type.start;
				last = this_type.last;
				end = this_type.end;
				this_type.~automaton();
			}

			explicit automaton(CType&) = delete;


			// ========================================================
			//
			//		Automaton Module
			//
			// ========================================================

			void new_node(_Func& func) {
				auto_node *tmp_std = new auto_node;
				tmp_std->automata = func;
				tmp_std->key = count++;
				last.push_back(tmp_std);
			}


		};


		ILW_ANCOMP("dag:tool assist:graph")
		template<class _DAGopt> class _dag_base {

		};

	}

}

#endif