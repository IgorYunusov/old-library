/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/


#ifndef __APVL_GRAPH
#define __APVL_GRAPH

#ifdef  __cplusplus
#define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
#else
#define _ADDRESSOF(v)   ( &(v) )
#endif

#define UIGraphMemberSet	static
typedef unsigned long long	UIGraphHandle;

#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

#define UIGraph_Error					0x7000000F

typedef unsigned short UIGraphVersion;
typedef unsigned long UIGraphLVersion;

// Must Cast Before !!
#define UIGraphVersionCheck( vs1, vs2 ) \
	(UIGraphLVersion)(vs1) << 4 | (UIGraphVersion)(vs2)


// Rollrat Unlimited Intervene Graph Library 1.0
// [ FIRST I ]

#define FIUI_Version	UIGraphVersionCheck( 0x00, 0x01 )

#define FI_UIGraphVersionCheckSuccess	0x80000002

typedef unsigned long FI_UIGraphRequest;
typedef struct _tag_REQUEST_edc
{ // request
	FI_UIGraphRequest		HighMessage;
	FI_UIGraphRequest		LowMessage;
} FIUIG_Request,	*PFIUIG_Request;

#define UIGraphRequestErrorM		0x0007
#define UIGraphRequestLocked		0x001B
#define UIGraphRequestHighSuccess	0x001F
#define UIGraphRequestLowSuccess	0x0023

#define FI_UIGraphRequestGet	(FI_UIGraphRequest)(0x10000000)
#define FI_UIGraphRequestSet	(FI_UIGraphRequest)(0x20000000)
#define FI_UIGraphRequestState	(FI_UIGraphRequest)(0x30000000)
#define FI_UIGraphRequestForce	(FI_UIGraphRequest)(0x40000000)

#define FIUIG_ReportMe			(FI_UIGraphRequest)(0x01000000)
#define FIUIG_Last				(FI_UIGraphRequest)(0x02000000)
#define FIUIG_First				(FI_UIGraphRequest)(0x03000000)
#define FIUIG_Replay			(FI_UIGraphRequest)(0x04000000)
#define FIUIG_Only				(FI_UIGraphRequest)(0x05000000)

#define FIUIG_LVersionAccept	(FI_UIGraphRequest)(0x00000001)
#define FIUIG_HAlloc			(FI_UIGraphRequest)(0x00000002)
#define FIUIG_HConnect			(FI_UIGraphRequest)(0x00000003)
#define FIUIG_HError			(FI_UIGraphRequest)(0x00000004)
#define FIUIG_HPannel			(FI_UIGraphRequest)(0x00000005)
#define FIUIG_HEquation			(FI_UIGraphRequest)(0x00000006)
#define FIUIG_HCalculation		(FI_UIGraphRequest)(0x00000007)
#define FIUIG_LAcceptAllow		(FI_UIGraphRequest)(0x00000008)

namespace UIGraphServe
{
	class FI_UIGraphServe
	{
	public:

		UIGraphMemberSet UIGraphLVersion UIGraphVersionK(UIGraphLVersion x)
		{
			// Set Manual Graph Version
			// MiniV : 0.01
			// MaxV  : 0.23
			if(x >> 4 || (UIGraphVersion)(x > 23))
				return UIGraph_Error;
	
			// Other Version
			return FI_UIGraphVersionCheckSuccess;
		}



	};
	
	// RollRat UIGraph Request Service
	class FI_UIGraphRequestService
	{
	public:

		UIGraphMemberSet void UIGraphRequest(UIGraph::FI_UIGraph& Served, 
			PFIUIG_Request gxReq, FI_UIGraphRequest req, ... )
		{
			switch( req & 0xf0000000 )
			{
			case FI_UIGraphRequestGet:
				switch( req & 0x0f000000 )
				{
				case FIUIG_ReportMe:
					break;
				case FIUIG_Last:
					break;
				case FIUIG_First:
					break;
				case FIUIG_Replay:
					break;
				case FIUIG_Only:
					break;
				default:
					gxReq->LowMessage = UIGraphRequestErrorM;
					gxReq->HighMessage = UIGraphRequestErrorM;
				}
				return;
			case FI_UIGraphRequestSet:
				switch( req & 0x0f000000 )
				{
				case FIUIG_ReportMe:
					break;
				case FIUIG_Last:
					break;
				case FIUIG_First:
					break;
				case FIUIG_Replay:
					break;
				case FIUIG_Only:
					break;
				default:
					gxReq->LowMessage = UIGraphRequestErrorM;
					gxReq->HighMessage = UIGraphRequestErrorM;
				}
				return;
			case FI_UIGraphRequestState:
				switch( req & 0x0f000000 )
				{
				case FIUIG_ReportMe:
					break;
				case FIUIG_Last:
					break;
				case FIUIG_First:
					break;
				case FIUIG_Replay:
					break;
				case FIUIG_Only:
					break;
				default:
					gxReq->LowMessage = UIGraphRequestErrorM;
					gxReq->HighMessage = UIGraphRequestErrorM;
				}
				return;
			case FI_UIGraphRequestForce:
				switch( req & 0x0f000000 )
				{
				case FIUIG_ReportMe:
					break;
				case FIUIG_Last:
					break;
				case FIUIG_First:
					break;
				case FIUIG_Replay:
					break;
				case FIUIG_Only:
					break;
				default:
					gxReq->LowMessage = UIGraphRequestErrorM;
					gxReq->HighMessage = UIGraphRequestErrorM;
				}
				return;
			default:
				gxReq->LowMessage = UIGraphRequestErrorM;
				gxReq->HighMessage = UIGraphRequestErrorM;
			}
			return;
		}

		UIGraphMemberSet bool RequestLocked(UIGraph::FI_UIGraph& Served, bool Accept)
		{
			FIUIG_Request ExPercit;
			UIGraphServe::FI_UIGraphRequestService::UIGraphRequest(Served, &ExPercit, 
				FI_UIGraphRequestState | FIUIG_ReportMe | FIUIG_LAcceptAllow);
			if(ExPercit.LowMessage == UIGraphRequestLowSuccess)
				return !Accept;
			return true;
		}
	};
}

namespace UIGraph
{

	typedef struct _tag_GRAPH_xyz
	{
		double x, y, z;
	}	UIGraphPH, *PUIGraphPH;

	typedef struct _tag_GRAPH_direction
	{
		UIGraphHandle Handle;
		UIGraphPH *xyz;
	}	UIGraphDirection, *PUIGraphDirection;

	class FI_UIGraph
	{
	public:

		FI_UIGraph(UIGraphLVersion x)
		{
			// Must 'false' init !
			// Cus' Incorrect versions are interrupted.
			Accept = false;

			// Version Check
			gVersion = x;

			if(UIGraphServe::FI_UIGraphServe::UIGraphVersionK(gVersion) == FI_UIGraphVersionCheckSuccess)
				Accept = true;

			// Zero Handle
			Handle = 0;
		}
		
		template<typename _Func> 
			void DrawGraph(_Func& func)
		{
			// DrawGraph
			// Must Read Me!
			// Func Type 'func(x1, x2, y1, y2)'
			if(!UIGraphServe::FI_UIGraphRequestService::RequestLocked(*this, Accept))
				return;

		}

	private:

		UIGraphDirection	Direction;
		UIGraphLVersion		gVersion;
		UIGraphHandle		Handle;
		bool Accept;

	};
}

#endif