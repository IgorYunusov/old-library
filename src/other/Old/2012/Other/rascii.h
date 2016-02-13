/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Header : <rascii.h>      												   ********
 ********										                                           ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

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