/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Header : <rdefasc.h>      												   ********
 ********										                                           ********
 ********       Copyright ⓒ ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/
/*

      Define of ASCII and GOTO(cardinal points north, south, east, and west)

      RollRat Header << rnum.h >>
	   
	    Impormation

		     The define ASCII code

			     Null text    0x00

				 Space Text   0x32

			     Punctuation  0x21 ~ 0x41 , 0x5B ~ 0x7E

			     Alphabet     0x41 ~ 0x5A , 0x61 ~ 0x7A

				 Number       0x30 ~ 0x39

				    Other (Disappear Code)

					    Binary	    Oct	Dec	Hex	Abbr[a]	[b]	[c]	Name
					    000 0000	000	0	00	NUL	␀	^@	\0	Null character
					    000 0001	001	1	01	SOH	␁	^A		Start of Header
					    000 0010	002	2	02	STX	␂	^B		Start of Text
					    000 0011	003	3	03	ETX	␃	^C		End of Text
					    000 0100	004	4	04	EOT	␄	^D		End of Transmission
					    000 0101	005	5	05	ENQ	␅	^E		Enquiry
					    000 0110	006	6	06	ACK	␆	^F		Acknowledgment
					    000 0111	007	7	07	BEL	␇	^G	\a	Bell
					    000 1000	010	8	08	BS	␈	^H	\b	Backspace[d][e]
					    000 1001	011	9	09	HT	␉	^I	\t	Horizontal Tab[f]
					    000 1010	012	10	0A	LF	␊	^J	\n	Line feed
					    000 1011	013	11	0B	VT	␋	^K	\v	Vertical Tab
					    000 1100	014	12	0C	FF	␌	^L	\f	Form feed
					    000 1101	015	13	0D	CR	␍	^M	\r	Carriage return[g]
					    000 1110	016	14	0E	SO	␎	^N		Shift Out
					    000 1111	017	15	0F	SI	␏	^O		Shift In
					    001 0000	020	16	10	DLE	␐	^P		Data Link Escape
					    001 0001	021	17	11	DC1	␑	^Q		Device Control 1 (oft. XON)
					    001 0010	022	18	12	DC2	␒	^R		Device Control 2
					    001 0011	023	19	13	DC3	␓	^S		Device Control 3 (oft. XOFF)
					    001 0100	024	20	14	DC4	␔	^T		Device Control 4
					    001 0101	025	21	15	NAK	␕	^U		Negative Acknowledgement
					    001 0110	026	22	16	SYN	␖	^V		Synchronous idle
					    001 0111	027	23	17	ETB	␗	^W		End of Transmission Block
					    001 1000	030	24	18	CAN	␘	^X		Cancel
					    001 1001	031	25	19	EM	␙	^Y		End of Medium
					    001 1010	032	26	1A	SUB	␚	^Z		Substitute
					    001 1011	033	27	1B	ESC	␛	^[	\e[h]	Escape[i]
					    001 1100	034	28	1C	FS	␜	^\		File Separator
					    001 1101	035	29	1D	GS	␝	^]		Group Separator
					    001 1110	036	30	1E	RS	␞	^^[j]		Record Separator
					    001 1111	037	31	1F	US	␟	^_		Unit Separator
					    111 1111	177	127	7F	DEL	␡	^?		Delete[k][e]

				    Other (Appear Code)
					    
						Binary	    Oct	Dec	Hex	Glyph
						010 0000	040	32	20	 
						010 0001	041	33	21	!
						010 0010	042	34	22	"
						010 0011	043	35	23	#
						010 0100	044	36	24	$
						010 0101	045	37	25	%
						010 0110	046	38	26	&
						010 0111	047	39	27	'
						010 1000	050	40	28	(
						010 1001	051	41	29	)
						010 1010	052	42	2A	*
						010 1011	053	43	2B	+
						010 1100	054	44	2C	,
						010 1101	055	45	2D	-
						010 1110	056	46	2E	.
						010 1111	057	47	2F	/
						011 0000	060	48	30	0
						011 0001	061	49	31	1
						011 0010	062	50	32	2
						011 0011	063	51	33	3
						011 0100	064	52	34	4
						011 0101	065	53	35	5
						011 0110	066	54	36	6
						011 0111	067	55	37	7
						011 1000	070	56	38	8
						011 1001	071	57	39	9
						011 1010	072	58	3A	:
						011 1011	073	59	3B	;
						011 1100	074	60	3C	<
						011 1101	075	61	3D	=
						011 1110	076	62	3E	>
						011 1111	077	63	3F	?
						100 0000	100	64	40	@
						100 0001	101	65	41	A
						100 0010	102	66	42	B
						100 0011	103	67	43	C
						100 0100	104	68	44	D
						100 0101	105	69	45	E
						100 0110	106	70	46	F
						100 0111	107	71	47	G
						100 1000	110	72	48	H
						100 1001	111	73	49	I
						100 1010	112	74	4A	J
						100 1011	113	75	4B	K
						100 1100	114	76	4C	L
						100 1101	115	77	4D	M
						100 1110	116	78	4E	N
						100 1111	117	79	4F	O
						101 0000	120	80	50	P
						101 0001	121	81	51	Q
						101 0010	122	82	52	R
						101 0011	123	83	53	S
						101 0100	124	84	54	T
						101 0101	125	85	55	U
						101 0110	126	86	56	V
						101 0111	127	87	57	W
						101 1000	130	88	58	X
						101 1001	131	89	59	Y
						101 1010	132	90	5A	Z
						101 1011	133	91	5B	[
						101 1100	134	92	5C	\
						101 1101	135	93	5D	]
						101 1110	136	94	5E	^
						101 1111	137	95	5F	_
						110 0000	140	96	60	`
						110 0001	141	97	61	a
						110 0010	142	98	62	b
						110 0011	143	99	63	c
						110 0100	144	100	64	d
						110 0101	145	101	65	e
						110 0110	146	102	66	f
						110 0111	147	103	67	g
						110 1000	150	104	68	h
						110 1001	151	105	69	i
						110 1010	152	106	6A	j
						110 1011	153	107	6B	k
						110 1100	154	108	6C	l
						110 1101	155	109	6D	m
						110 1110	156	110	6E	n
						110 1111	157	111	6F	o
						111 0000	160	112	70	p
						111 0001	161	113	71	q
						111 0010	162	114	72	r
						111 0011	163	115	73	s
						111 0100	164	116	74	t
						111 0101	165	117	75	u
						111 0110	166	118	76	v
						111 0111	167	119	77	w
						111 1000	170	120	78	x
						111 1001	171	121	79	y
						111 1010	172	122	7A	z
						111 1011	173	123	7B	{
						111 1100	174	124	7C	|
						111 1101	175	125	7D	}
						111 1110	176	126	7E	~

		     Find
			     
				 Resource

				     Wikipedia     Address{http://en.wikipedia.org/wiki/ASCII}
			     
				 GOTO
				     
					 UP 72, DOWN 80, RIGHT 77, LEFT 75

			     Type
				    
					 CHAR, int, gotoxy

		Version

		    Since 1968 (ASCII CODE MADE)

		USEABLE
		    
			Visual C++, TurboC, TurboC++, BorlandC, BorlandC++, Object C, GCC, G++, etc.

		UNUSEABLE

		    WIN16 bit, solaris, etc.

		2012-10-13 

 */
#if !defined RNUM
#define RNUM
#if !defined ASCII
#define ASCII
#if !defined(R_ASC_FF)
#  define /*  '' */ _NULL 0x00
#  define /* ' ' */ SPACE 0x20
#else 
#  define ERROR
#endif
#define NONE_ERROR_FF
#if !defined(R_ASC_FE)
#  define /* '0' */ NUM_0 0x30
#  define /* '1' */ NUM_1 0x31
#  define /* '2' */ NUM_2 0x32
#  define /* '3' */ NUM_3 0x33
#  define /* '4' */ NUM_4 0x34
#  define /* '5' */ NUM_5 0x35
#  define /* '6' */ NUM_6 0x36
#  define /* '7' */ NUM_7 0x37
#  define /* '8' */ NUM_8 0x38
#  define /* '9' */ NUM_9 0x39
#else
#  define ERROR_FE
#endif
#define NONE_ERROR_FE
#if !defined(R_ASC_FA)
#  define /* '!' */ A_1   0x21
#  define /* '"' */ A_2   0x22
#  define /* '#' */ A_3   0x23
#  define /* '$' */ A_4   0x24
#  define /* '%' */ A_5   0x25
#  define /* '&' */ A_6   0x26
#  define /* ''' */ A_7   0x27
#  define /* '(' */ A_8   0x28
#  define /* ')' */ A_9   0x29
#  define /* '*' */ A_10  0x2A
#  define /* '+' */ A_11  0x2B
#  define /* ',' */ A_12  0x2C
#  define /* '-' */ A_13  0x2D
#  define /* '.' */ A_14  0x2E
#  define /* '/' */ A_15  0x2F
#  define /* ':' */ A_16  0x3A
#  define /* ';' */ A_17  0x3B
#  define /* '<' */ A_18  0x3C
#  define /* '=' */ A_19  0x3D
#  define /* '>' */ A_20  0x3E
#  define /* '?' */ A_21  0x3F
#  define /* '@' */ A_22  0x40
#  define /* '[' */ A_23  0x5B
#  define /* '\' */ A_24  0x5C
#  define /* ']' */ A_25  0x5D
#  define /* '^' */ A_26  0x5E
#  define /* '_' */ A_27  0x5F
#  define /* '`' */ A_28  0x60
#  define /* '{' */ A_29  0x7B
#  define /* '|' */ A_30  0x7C
#  define /* '}' */ A_31  0x7D
#  define /* '~' */ A_32  0x7E
#else
#  define ERROR_FA
#endif
#define NONE_ERROR_FA
#if !defined(R_ASC_FB)
#  define /* 'A' */ A_A   0x41
#  define /* 'B' */ A_B   0x42
#  define /* 'C' */ A_C   0x43
#  define /* 'D' */ A_D   0x44
#  define /* 'E' */ A_E   0x45
#  define /* 'F' */ A_F   0x46
#  define /* 'G' */ A_G   0x47
#  define /* 'H' */ A_H   0x48
#  define /* 'I' */ A_I   0x49
#  define /* 'J' */ A_J   0x4A
#  define /* 'K' */ A_K   0x4B
#  define /* 'L' */ A_L   0x4C
#  define /* 'M' */ A_M   0x4D
#  define /* 'N' */ A_N   0x4E
#  define /* 'O' */ A_O   0x4F
#  define /* 'P' */ A_P   0x50
#  define /* 'Q' */ A_Q   0x51
#  define /* 'R' */ A_R   0x52
#  define /* 'S' */ A_S   0x53
#  define /* 'T' */ A_T   0x54
#  define /* 'U' */ A_U   0x55
#  define /* 'V' */ A_V   0x56
#  define /* 'W' */ A_W   0x57
#  define /* 'X' */ A_X   0x58
#  define /* 'Y' */ A_Y   0x59
#  define /* 'Z' */ A_Z   0x5A
#  define /* 'a' */ A_a   0x61
#  define /* 'b' */ A_b   0x62
#  define /* 'c' */ A_c   0x63
#  define /* 'd' */ A_d   0x64
#  define /* 'e' */ A_e   0x65
#  define /* 'f' */ A_f   0x66
#  define /* 'g' */ A_g   0x67
#  define /* 'h' */ A_h   0x68
#  define /* 'i' */ A_i   0x69
#  define /* 'j' */ A_j   0x6A
#  define /* 'k' */ A_k   0x6B
#  define /* 'l' */ A_l   0x6C
#  define /* 'm' */ A_m   0x6D
#  define /* 'n' */ A_n   0x6E
#  define /* 'o' */ A_o   0x6F
#  define /* 'p' */ A_p   0x70
#  define /* 'q' */ A_q   0x71
#  define /* 'r' */ A_r   0x72
#  define /* 's' */ A_s   0x73
#  define /* 't' */ A_t   0x74
#  define /* 'u' */ A_u   0x75
#  define /* 'v' */ A_v   0x76
#  define /* 'w' */ A_w   0x77
#  define /* 'x' */ A_x   0x78
#  define /* 'y' */ A_y   0x79
#  define /* 'z' */ A_z   0x7A
#else
#  define ERROR_FB
#endif
#define NONE_ERROR_FB
#else
#  define ERROR
#endif
#define EXCUSE ASCII NONE_ERROR_FF NONE_ERROR_FE NONE_ERROR_FA NONE_ERROR_FB \
	ERROR ERROR_FB ERROR_FA ERROR_FE /* Developers Annotation */
#ifndef GOTO
#  define Up    72
#  define Down  80
#  define Left  75
#  define Right 77
#else
#  define ERROR_GOTO
#endif
#else
#  if NONE
#    define ERROR_G
#    define ERROR_FINE
#    define ERROR
#    define ERROR_GOTO
#    define NONE
#    define ERROR_FE
#    define ERROR_FB
#    define ERROR_FA
#  else
#    define Err
#  endif
#endif
#define /* Developers Annotation */ DEFINE_RNUM EXCUSE
