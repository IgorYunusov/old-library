/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   psfunc.c

Purpose:

	Parse c function syntax.

Author:

   09-12-2015:   HyunJun Jeong, Creation

***/

#include <malloc.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "psfunc.h"

DEF_LIST *create_deflist()
{
	DEF_LIST *deflist = (DEF_LIST *)malloc(sizeof(DEF_LIST));
	deflist->next = 0;
	deflist->dal = 0;
	deflist->index = 0;
	deflist->processor = 0;
	return deflist;
}

DEF_ARG_LIST *create_defarglist()
{
	DEF_ARG_LIST *deflist = (DEF_ARG_LIST *)malloc(sizeof(DEF_ARG_LIST));
	deflist->index = 0;
	deflist->next = 0;
	return deflist;
}

DEF_GENERAL_LIST *create_defgenerallist()
{
	DEF_GENERAL_LIST *deflist = (DEF_GENERAL_LIST *)malloc(sizeof(DEF_GENERAL_LIST));
	deflist->next = 0;
	return deflist;
}

DEF_MACRO_LIST *create_macrolist()
{
	DEF_MACRO_LIST *macrolist = (DEF_MACRO_LIST *)malloc(sizeof(DEF_MACRO_LIST));
	macrolist->next = 0;
	macrolist->index = 0;
	macrolist->processor = 0;
	macrolist->ch = 0;
	return macrolist;
}

/*
	Parse define syntax
*/
PDEF_LIST parse_define(PLINE_LIST lines)
{
	LINE_LIST *current = lines;
	DEF_LIST *deflist = create_deflist();
	DEF_LIST *recentdef = deflist;
	bool def_first = false;
	char *pointerptr;
	int index = 0;

	//
	//	Search Define Structure
	//
	do 
	{
		const char *pointer = current->pointer;

		if (*pointer++ == '#')
		{
			const char *str_def = "define";
			
			//
			//	Skip White space
			//
			for( ; isspace(*pointer); pointer++)
				;

			for( ; *str_def; str_def++)
			{
				if (*str_def != *pointer++)
				{
					break;
				}
			}

			//
			//	This is not define format.
			//
			if (*str_def)
			{
				continue;
			}

			if (def_first)
			{
				recentdef->next = create_deflist();
				recentdef = recentdef->next;
				recentdef->index = ++index;
			}
			else
			{
				def_first = true;
			}

			for( ; isspace(*pointer); pointer++)
				;

			//
			//	Get name
			//
			for(pointerptr = recentdef->name ; isalnum(*pointer) ||
				   *pointer == '$'   ||
				   *pointer == '_'      ; pointer++)
			{
				*pointerptr++ = *pointer;
			}

			*pointerptr = 0;

			//
			//	Check macro
			//
			if (*pointer++ == '(')
			{
				DEF_ARG_LIST *dal = create_defarglist();
				DEF_ARG_LIST *recentdal = dal;
				bool dal_first = false;
				int index_dal = 0;

				recentdef->processor = 1;

				//
				//	Search argument
				//
				do
				{
					//
					//	Malloc-Free Error Checker
					//
					if (dal_first)
					{
						recentdal->next = create_defarglist();
						recentdal = recentdal->next;
						recentdal->index = ++index_dal;
					}

					for( ; isspace(*pointer); pointer++)
						;
					
					for(pointerptr = recentdal->name ; isalnum(*pointer) ||
						   *pointer == '$'   ||
						   *pointer == '_'      ; pointer++)
					{
						*pointerptr++ = *pointer;
					}

					*pointerptr = 0;

					for( ; isspace(*pointer); pointer++)
						;

					if (*pointer == ',')
						pointer++;

					dal_first = true;

				} while(*pointer != ')');

				recentdef->dal = dal;

				// skip ')'
				pointer++;

				for( ; isspace(*pointer); pointer++)
					;

				/*
					Parsing Define Format
				*/
				if (*pointer)
				{
					DEF_MACRO_LIST *dml = create_macrolist();
					DEF_MACRO_LIST *recentdml = dml;
					bool dml_first = false;
					int index_dml = 0;
					bool skip = false;

					for( ; *pointer; )
					{
						if (dml_first)
						{
							recentdml->next = create_macrolist();
							recentdml = recentdml->next;
						}
						else
						{
							dml_first = true;
						}

						if ((isalpha(*pointer) ||
						    *pointer == '$'    ||
						    *pointer == '_'      ) && !skip)
						{
							char arg_search[10];
							const char *t_pointer = pointer;
							int index;
							bool is_exist = false;

							for(pointerptr = arg_search ; isalnum(*pointer) ||
								   *pointer == '$'   ||
								   *pointer == '_'      ; pointer++)
							{
								*pointerptr++ = *pointer;
							}
							
							*pointerptr = 0;

							//
							//	Search argument
							//
							for (recentdal = dal;
								recentdal; recentdal = recentdal->next)
							{
								if (!strcmp(arg_search, recentdal->name))
								{
									is_exist = true;
									index = recentdal->index;
									break;
								}
							}

							if (true == is_exist)
							{
								recentdml->index = index;
								recentdml->processor = 1;

								if ( * (pointer + 0) == '#' &&
									 * (pointer + 1) == '#'    )
								{
									recentdml->processor = 3;
									pointer += 2;
								}
							}
							else
							{
								skip = true;
								pointer = t_pointer;
								goto NON_EXIST;
							}
						}
						else if (*pointer == '#')
						{
						PASTING_PROC:
							if (* (pointer + 1) == '#')
							{
								recentdml->processor = 2;
								pointer += 2;
							}
							skip = false;
						}
						else if (*pointer == '\\')
						/*
							Next Line
						*/
						{
							recentdml->ch = '\n';
							skip = false;
							current = current->next;
							pointer = current->pointer;
						}
						else
						{
						NON_EXIST:
							if (!(isalnum(*pointer) ||
								 *pointer == '$'    ||
								 *pointer == '_'      ))
							{
								skip = false;
							}
							recentdml->ch = *pointer++;
						}

					}
					recentdef->dml = dml;
				}
			}
			else
				// general macro
			{
				DEF_GENERAL_LIST *dgl = create_defgenerallist();
				DEF_GENERAL_LIST *recentdal = dgl;

				recentdef->processor = 0;
				
				for( ; isspace(*pointer); pointer++)
					;
				
				do
				{
					//
					//	Get data
					//
					for(pointerptr = recentdal->data ; 
						*pointer && *pointer != '\\'; pointer++)
					{
						*pointerptr++ = *pointer;
					}

					*pointerptr = 0;

					if (*pointer == '\\')
					{
						current = current->next;
						pointer = current->pointer;
						
						recentdal->next = create_defgenerallist();
						recentdal = recentdal->next;
					}
					else
					{
						break;
					}
				} while (true);

				recentdef->dgl = dgl;
			}

		}

	END_OF_TERM:

		free(recentdef->next);
		recentdef->next = 0;
		current = current->next;

	} while (current);

	return deflist;
}

void replace_defines(PDEF_LIST dl, const char *target, char *buffer)
{
	do {
		if ((isalpha(*target) ||
		    *target == '$'    ||
		    *target == '_'      ) )
		{
			char search_name[30];
			char *pointerptr;
			const char *pointer = target;
			PDEF_LIST pdl = dl;
			bool is_exist = false;
			
			for(pointerptr = search_name ; isalnum(*pointer) ||
				   *pointer == '$'   ||
				   *pointer == '_'      ; pointer++)
			{
				*pointerptr++ = *pointer;
			}

			*pointerptr = 0;
			
			for ( ; pdl; pdl = pdl->next)
			{
				if (!strcmp(search_name, pdl->name))
				{
					is_exist = true;
					break;
				}
			}

			if (is_exist)
			{
				if (*pointer == '(' && pdl->processor == 1)
				{
					DEF_ARG_LIST *dal = create_defarglist();
					DEF_ARG_LIST *recentdal = dal;
					bool dal_first = false;
					int paren = 0;
					
					pointer++;

					do
					{
						if (dal_first)
						{
							recentdal->next = create_defarglist();
							recentdal = recentdal->next;
						}

						for( ; isspace(*pointer); pointer++)
							;
						
						for(pointerptr = recentdal->name ; 
							*pointer && 
							((*pointer == ',' && paren) || *pointer != ','); pointer++)
						{
							if (*pointer == '(')
								paren++;
							if (*pointer == ')')
								if (!paren--)
									break;
							*pointerptr++ = *pointer;
						}

						*pointerptr = 0;

						for( ; isspace(*pointer); pointer++)
							;

						if (*pointer == ',')
							pointer++;

						dal_first = true;

					} while(*pointer != ')');

					target = pointer + 1;

					{
						DEF_MACRO_LIST *dml = pdl->dml;
						for (; dml; dml = dml->next)
						{
							if (dml->processor == 0)
							{
								*buffer = dml->ch;
								buffer++;
							}
							else if (dml->processor == 1 ||
								dml->processor == 3)
							{
								DEF_ARG_LIST *tdal = dal;
								int i = 0;

								for ( ; i < dml->index; i++)
								{
									//
									// elliptical part
									//
									if (tdal == 0)
									{
										goto EXIT;
									}

									tdal = tdal->next;
								}

								for (pointerptr = tdal->name; *pointerptr; pointerptr++)
								{
									*buffer = *pointerptr;
									buffer++;
								}
							}
						}
					}
				EXIT:
					;
				}
				else
				{
					if (pdl->processor == 0)
					{
						DEF_GENERAL_LIST *dgl = pdl->dgl;

						for (; dgl; dgl = dgl->next)
						{
							for (pointerptr = dgl->data; *pointerptr; pointerptr++)
							{
								*buffer = *pointerptr;
								buffer++;
							}
						}

					}
					else
					{
						DEF_MACRO_LIST *dml = pdl->dml;
						for (; dml; dml = dml->next)
						{
							if (dml->processor == 0)
							{
								*buffer = dml->ch;
								buffer++;
							}
						}
					}
					
					target = pointer - 1;
				}
			}
			else
			{
				for (pointerptr = search_name; *pointerptr; pointerptr++)
				{
					*buffer = *pointerptr;
					buffer++;
				}

				target = pointer - 1;
			}

		}
		else
		{
			*buffer = *target;
			buffer++;
		}
	} while (*target++);
	*buffer = 0;
}

LINE_LIST *set_line(const char *target)
{
	LINE_LIST *ll = (LINE_LIST *) malloc(sizeof(LINE_LIST));
	size_t len = strlen(target);

	ll->next = 0;
	ll->pointer = (char *)malloc(len + 1);

	strncpy_s(ll->pointer, len+1, target, len);

	return ll;
}

void put_line(PLINE_LIST ll, const char *target)
{
	PLINE_LIST last = ll;
	LINE_LIST *tt = (LINE_LIST *)malloc(sizeof(LINE_LIST));
	size_t len = strlen(target);

	tt->next = 0;
	tt->pointer = (char *)malloc(len + 1);

	strncpy_s(tt->pointer, len+1, target, len);

	for (; last->next; last = last->next)
		;

	last->next = tt;
}

int main()
{
	LINE_LIST *ll = 
	//set_line("#define ssss(asdf, abcf) abd##tfs ## abcf##dc abcf\\");
	set_line("#define ssss(asdf, abcf) abcf\\");
	put_line(ll, "asdf##crt");
	put_line(ll, "#define rollrat rollratset");
	DEF_LIST *dl = parse_define(ll);
	char buf[999];
	replace_defines(dl, "asdxc ssss(crt, (s,t))asdf rollrat()", buf);
	printf(buf);
}
