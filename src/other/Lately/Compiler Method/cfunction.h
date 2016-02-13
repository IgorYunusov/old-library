/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _CFUNCTION_
#define _CFUNCTION_

char *_itoa(long val, char *buf)
{ // itoa
	char *p, *f, temp;
	unsigned bufs; // check point
	p = buf; // first point
	if (val < 0)
	{ // check signal of number
		*p++ = '-';
		// abs check
		val = ((unsigned long)(-(long)(val)));
	}
	f = p;
	do { // put all
		bufs = ((unsigned)(val % 10));
		val /= 10;
		*p++ = ((char)(bufs + '0'));
	} while (val > 0);

	*p-- = '\0'; // last \0 lit
	return buf;
}

char *_ftoa(double val, char *buf)
{ // float to char
	char *p, *f, temp;
	unsigned bufs;
	p = buf;
	if (val < 0)
	{ // check signal of number
		*p++ = '-';
		// abs check
		val = ((double)(-(double)(val)));
	}
	f = p;
	do { // put digit
		bufs = (unsigned(val) % 10);
		val /= 10;
		*p++ = ((char)(bufs + '0'));
	} while (val > 0);
	*p-- = '\0'; // last \0 lit
	return buf;
}

typedef int (*PUTC_PTR)(int);

typedef char * va_list;

#ifdef  __cplusplus
#define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
#else
#define _ADDRESSOF(v)   ( &(v) )
#endif

#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

#define _EOFSETUP		0

#define _NONE_ACTIVE	;

#define _VALIATED_RETURN( val, set, x ) \
	if(!val) return set ? 0 : x

#define _U	unsigned


int sprintf_r(
	char * str,
	const char * format, 
	... 
	)
/* Print Formatted String */
{
	int i;		/*	ptr counter			*/
	int valid;	/*	integer temp		*/
_U	int uvalid;	/*	uinteger temp		*/
	int tp;		/*	con-valid value		*/
_U	int utp;	/*	ucon-valid value	*/
	int pd;		/*	format option		*/
	int pt;		/*	str count			*/
	int sign;	/*	integer sign		*/
	int ps;		/*	minus sign			*/
	int n;		/*	n counter			*/
	int px;		/*	zero sign			*/
	int num;	/*	number system		*/
	va_list _VAL;
	char *sptr;
	const char * _temp;
	const char * _ptr;

	_VALIATED_RETURN( ( _ptr = format ), _EOFSETUP, (-1) ) ;

	i = 0;
	sign = 0;
	ps = 0;
	n = 0;
	px = 0;
	num = 0;
	sptr = str;

	va_start( _VAL, format ) ;

#define put(x) n++, *(sptr++) = x

#define forward (_ptr + i + 1)

/* printf-format-strings */
	while(_ptr[i] != '\0' && *_ptr)
	{
		switch(_ptr[i])
		{
		case '\\':

			put(_ptr[++i]);
			break;

		case '%':
			
gb_s:
			switch(_ptr[i + 1])
			{
			case '\#':
				sprintf_r(sptr, "0x");
				n += 2;
				goto gb_t;
			case '\+':
				sign = 1;
				goto gb_t;
			case '\-':
				ps = 1;
				goto gb_t;
			case '0':
				px = 1;
gb_t:
				i++;
				goto gb_s;
			}

			for(pd = 0 ; *forward; i++)
				if( '0' <= *forward && *forward <= '9' )
					pd = pd * 10 + *forward - '0';
				else
				{
					i++;
					break;
				}

			switch(_ptr[i])
			{
			case 'd': /* STD Output of Integer */
				num = 8;
			case 'b': /* STD Output of Binary */
				num ^= 10;
			case 'o': /* STD Output of Octal Digit */
				num ^= 8;

				valid = va_arg( _VAL, int );

				if(!valid)
				{
					put('0');
					break;
				}

				for( tp = 0, pt = 0; valid; valid /= num, pt++ )
					tp = tp * num + valid % num;
				
				if(sign)
				{
					if( tp > 0 )
						put('+');
					else if( tp < 0 )
						put('-');
					sign = 0;
				}

				if(!pd)
					for( ; pt; tp /= num, pt-- )
						put((char)(tp % num + '0'));
				else
					if(pt > pd)
					{
						for( ; pt; tp /= num, pt--)
							if(!(pt > pd))
								put((char)(tp % num + '0'));
					}
					else if(pt <= pd)
					{
						if(ps && pt != pd)
						{
							for( ; pt; tp /= num, pt--, pd--)
								put((char)(tp % num + '0'));
							if(!px)
								for( ; pd; pd--)
									put(' ');
							else
								for( ; pd; pd--)
									put('0');
							ps = 0;
						}
						else
						{
							if(!px)
								for( ; pt != pd; pd--)
									put(' ');
							else
								for( ; pt != pd; pd--)
									put('0');
							for( ; pd; tp /= num, pd--)
								put((char)(tp % num + '0'));
						}
					}
					
				num = 0;

				break;
				
			case 'u': /* EX-STD Output of UInteger */
			case 'D': /* EX-STD Output of UInteger */
				num = 8;
			case 'B': /* EX-STD Output of UBinary */
				num ^= 10;
			case 'O': /* EX-STD Output of UOctal Digit */
				num ^= 8;

				uvalid = va_arg( _VAL, unsigned int );

				if(!uvalid)
				{
					put('0');
					break;
				}

				for( utp = 0, pt = 0; uvalid; uvalid /= num, pt++ )
					utp = utp * num + uvalid % num;
				
				if(sign)
				{
					if( utp > 0 )
						put('+');
					else if( utp < 0 )
						put('-');
					sign = 0;
				}

				if(!pd)
					for( ; pt; utp /= num, pt-- )
						put((char)(utp % num + '0'));
				else
					if(pt > pd)
					{
						for( ; pt; utp /= num, pt--)
							if(!(pt > pd))
								put((char)(utp % num + '0'));
					}
					else if(pt <= pd)
					{
						if(ps && pt != pd)
						{
							for( ; pt; utp /= num, pt--, pd--)
								put((char)(utp % num + '0'));
							if(!px)
								for( ; pd; pd--)
									put(' ');
							else
								for( ; pd; pd--)
									put('0');
							ps = 0;
						}
						else
						{
							if(!px)
								for( ; pt != pd; pd--)
									put(' ');
							else
								for( ; pt != pd; pd--)
									put('0');
							for( ; pd; utp /= num, pd--)
								put((char)(utp % num + '0'));
						}
					}
					
				num = 0;

				break;

			case 'c': /* STD Output of Character */

				valid = va_arg( _VAL, char );

				put(valid);

				break;

			case 's': /* STD Output of String */
				
				_temp = va_arg( _VAL, char * );

				if(!pd)
					for( ; *_temp; _temp++)
						put(*_temp);
				else
				{
					for(pt = 0; _temp[pt]; pt++)
						;
					if(pt > pd)
					{
						for( ; pt && *_temp; _temp++, pt--)
							if(!(pt > pd))
								put(*_temp);
					}
					else if(pt <= pd)
					{
						for( ; pt != pd; pd--)
							put(' ');
						for( ; *_temp; _temp++)
							put(*_temp);
					}
				}

				break;

			case 'x': /* STD Output of Integer to Hex */

				valid = va_arg( _VAL, int );

				if(!valid)
				{
					put('0');
					break;
				}

				if(sign)
				{
					if( tp > 0 )
						put('+');
					else if( tp < 0 )
						put('-');
					sign = 0;
				}
				
				for( tp = 0, pt = 0; valid; valid /= 16, pt++ )
					tp = tp * 16 + valid % 16;
				
				if(!pd)
					for( ; pt; tp /= 16, pt-- )
						put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));
				else
					if(pt > pd)
					{
						for( ; pt; tp /= 16, pt--)
							if(!(pt > pd))
								put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));
					}
					else if(pt <= pd)
					{
						if(ps && pt != pd)
						{
							for( ; pt; tp /= 16, pt--, pd--)
								put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));
							if(!px)
								for( ; pd; pd--)
									put(' ');
							else
								for( ; pd; pd--)
									put('0');
							ps = 0;
						}
						else
						{
							if(!px)
								for( ; pt != pd; pd--)
									put(' ');
							else
								for( ; pt != pd; pd--)
									put('0');
							for( ; pd; tp /= 16, pd--)
								put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));
						}
					}

				break;

			case 'n': /* EX-STD Write value of Current string length  */

				*va_arg( _VAL, int * ) = n;
				
				break;

			case 'p': /* STD Output of Pointer to Hex */

				valid = va_arg( *&_VAL, int );
				
				n += sprintf_r(sptr, "%x", valid);

				break;

			default:
				_NONE_ACTIVE
			}

			break;

		default:
			put(_ptr[i]);
		}
		i++;
	}

	va_end( _VAL) ;
	
	return n;
}

#endif