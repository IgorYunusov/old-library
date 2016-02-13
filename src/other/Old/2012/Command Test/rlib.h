///////////////////////////////////////
// rollrat library v1.0
///////////////////////////////////////
#pragma once
#ifndef _ROLLRAT_
#define _ROLLRAT_
#if defined(__cplusplus)

#define NOTE( _text )
#define REDEF( _text ) _text

#define DEBUG_READY_OPERATION
#define DEBUG_READY_OPERATE
#define LIBRARY_LOAD
#define LIBRARY_REACTION

#define _LIB_START			namespace rollrat{
#define _LIB_END			}

#define _STUCT				namespace structs{
#define _STRUCT_END			}

#define _GRAPHIC			namespace graphic{
#define _GRAPHIC_END		}

// standard C++ EXTERN_C
#define _EXTERN_C			extern "C" {
#define _END_EXTERN_C		}

_STUCT

	template<class _TN>
		class POSITION
		{
			//////////////////////////////
			//
			//	This class is based on RollRatOS 
			//	two-dimensional coordinates display 
			//	is the base class.
			//
			//////////////////////////////
		public:
			_TN X;
			_TN Y;
			_TN Width;
			_TN Height;
		protected:
			template<class _NTN>
				class POSITION_X
				{
					// Additional classes for the design of a three-dimensional matrix.
				public:
					_NTN X;
					_NTN Y;
					_NTN Z;
				};
		};

	template<class _TN>
		class SIZE
		{
			//////////////////////////////
			//
			//	This class is based on RollRatOS 
			//	two-dimensional coordinates display 
			//	is the base class.
			//
			//////////////////////////////
		public:
			_TN Width;
			_TN Height;
			template<class _NTN>
				class SIZE_X
				{
					// Windows programming for additional classes.
				public:
					_NTN X;
					_NTN Y;
					_NTN CX;
					_NTN CY;
					typedef struct TD_SIZE
					{
						// To reduce the size of the task structure.
						int X;
						int Y;
						int CX;
						int CY;
					} X_SIZE, *XL_SIZE;
					TD_SIZE INT_SIZE;
				};
		};

	template<class _TN>
		class t_MATRIX
		{
			//////////////////////////////
			//
			//	This class is based on RollRatOS 
			//	two-dimensional coordinates display 
			//	is the base class.
			//
			//////////////////////////////
		public:
			_TN Max_CFH;
			template<class _NTN>
				class LOW
				{
				public:
					_NTN lf_LowV;
				};
			template<class _NTN>
				class LINE
				{
				public:
					_NTN lf_LineV;
				};
			class x_MATRIX
			{
			public:
				LOW<char*> max_Low[3];
				LINE<char*> max_Line[3];
			};
			template<class _NTN>
				class x_t_MATRIX : public POSITION<_NTN>
				{
				public:
					POSITION<_NTN>::POSITION_X TripleMatrixValue[3];
					x_MATRIX Title[3];
				};
			class SOLVER
			{
				template<class _MAS>
					class adjoint
					{

					};
				template<class _MAS>
					class inverse
					{

					};
				template<class _MAS>
					class boolean
					{

					};
			};

			template<class _NTN>
				class MATRIX_X
				{
					class CREDIT_3D_MATRIX
					{
						x_t_MATRIX<_NTN> column[3];
						_NTN geta(){ return column.TripleMatrixValue; }
					};
				};
		};

_STRUCT_END 

_LIB_START

	template<class _RECURE, 
				class _TN
				>
		class Exper
		{
		public:
			Exper();
			~Exper();
			_RECURE PosSet(_RECURE, _RECURE);
		private:
			_RECURE Member[];
			_RECURE String[];
			_RECURE Number[];
			structs::POSITION<_TN> Pos[];
		};

_LIB_END

#endif
#endif