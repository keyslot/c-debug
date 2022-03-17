#include "debug.h"

FILE *__debug_file__ = NULL;


int
__debug_point_line__(int macro)
{
	return macro;
}

int
__debug_point__(char *process,int line,char *status,FILE *out) 
{	
	fprintf(out,"\n%s\tprocces_name=%s,code_line=%d,current_file=%s,status=%s",
	                          __DEBUG_MSG__,
	                                process,
			                   line,
		                         status,
	                  __DEBUG_ERROR_INFO__);
	
	return __debug_point_line__(line);
}

void
__debug_close_log__(void)
{	
	if(__debug_file__ && fclose(__debug_file__) == EOF)
           perror("Error");
	__debug_file__ = NULL;
}

void
__debug_open_log__(char *path, char *mode) 
{	
	if(__debug_file__) 
		return;
        FILE *new = fopen(path,mode);
	if(!new) 
	   return perror(path);
	__debug_file__ = new;
	fprintf(__debug_file__,"\n---\n");
	fprintf(__debug_file__,"%s\n\n",path);
	fflush(__debug_file__);
}

void 
__debug_write_error__(char *type,char *expr,
                      char *process,char *in,int line, 
		      FILE *out)
{
	fputs("\b\n",out);
	fprintf(out,"%sevaluate_if(%s),process_name=",type,expr);
	fprintf(out, "%s,code_line=%d,current_file=%s,status=%s:\t%s",
	                              process,
				         line,
				           in,
		         __DEBUG_ERROR_INFO__,
		         __DEBUG_WARNG_MSG__);
  
	errno = 0;
}






