#ifndef DEBUG_CONFIG_H 
#define DEBUG_CONFIG_H
/**
----------------------------------------------------------------------------------------------+
| Simple dbug header                                                                          |
| author->keyslot                                                                             |
 ---------------------------------------------------------------------------------------------+
**/
#include <stdio.h>           /* I.O. streams                                                 */
#include <stdlib.h>          /* To call exit                                                 */
#include <string.h>          /* To get the last errno info                                   */
#include <stdarg.h>          /* To get __VA_ARGS__                                           */
#include <errno.h>           /* To get the last errno                                        */

#define __DEBUG_EXT__       ".log"
#define __DEBUG_AUTO_PATH__      __FILE__""__DEBUG_EXT__
#define __DEBUG_STREAM__    stderr
#define __DEBUG_MSG__ "Log"
#define __DEBUG_WARNG_MSG__ "Error!"
#define __DEBUG_ERROR_INFO__ strerror(errno)

/**-----------------------------------------------------------------------------------------**/
int   __debug_point_line__(int macro);
void  __debug_write_error__(char *type,char *expr,char *process,char *in,int line,FILE *out);
extern FILE * __debug_file__;
/**-----------------------------------------------------------------------------------------**/
#if DEBUG
    
    void __debug_close_log__(void);
    void __debug_open_log__(char *path,char *mode);
    int  __debug_point__(char *process,int line,char *status,FILE *out);

    #define dauto()            __debug_open_log__(__DEBUG_AUTO_PATH__,"a+")
    #define dset(file,mode)    __debug_open_log__(file,mode)
    #define dclose()           __debug_close_log__()
    
    #define dpoint()({\
	    __debug_write_point__(__debug_file__);\
	    __debug_write_point__(__DEBUG_STREAM__);\
	    })
    
    #define dprintf(...)(\
    {\
	    fprintf(__debug_file__,"\n"__DEBUG_MSG__"\tdprintf\t" __VA_ARGS__);\
    })

    #define __debug_write_point__(file)(\
    {\
	    __debug_point__(\
	    (char *)__func__,\
	    __LINE__,\
	    __FILE__,\
	    file\
	    );\
    })

#else
    #define dauto()      NULL
    #define dset(x,y)    NULL
    #define dclose()     NULL 
    #define dprintf(...) __debug_point_line__(0)
    #define dpoint()  __debug_point_line__(__LINE__)
#endif
/**-----------------------------------------------------------------------------------------**/
#ifndef __debug__lambda__
    #define __debug__lambda__(...) #__VA_ARGS__
#endif
/**-----------------------------------------------------------------------------------------**/
#ifndef __degug_write_error_code__
    #define __debug_write_error_code__(type,error,file)({\
	    __debug_write_error__(\
	    type,\
	    __debug__lambda__(error),\
	    (char *)__func__,\
	    __FILE__,\
	    __LINE__,\
	    file\
	    );\
    })
#endif
/**-----------------------------------------------------------------------------------------**/
#ifndef dexit_if
    #if DEBUG
        #define dexit_if(e)({\
	        if(e){\
	           __debug_write_error_code__(__DEBUG_MSG__"\texit_by_",e,__debug_file__);\
	           __debug_write_error_code__(__DEBUG_MSG__"\texit_by_",e,__DEBUG_STREAM__);\
	           exit(EXIT_FAILURE);\
	         }\
        })
  #else
        #define dexit_if(e)({\
 	        if(e){\
	           __debug_write_error_code__(__DEBUG_MSG__"\texit_by_",e,__DEBUG_STREAM__);\
	           exit(EXIT_FAILURE);\
	         }\
        })
  #endif
#endif
/**-----------------------------------------------------------------------------------------**/
#ifndef dwarning_if
  #if DEBUG
      #define dwarning_if(e)( {\
              if(e) {\
	 	 __debug_write_error_code__(__DEBUG_MSG__"\twarning_by_",e,__debug_file__);\
	 	 __debug_write_error_code__(__DEBUG_MSG__"\twarning_by_",e,__DEBUG_STREAM__);\
              }\
})
  #else
      #define dwarning_if(e)( {\
              if(e) {\
		__debug_write_error_code__(__DEBUG_MSG__"\twarning_by_",e,__DEBUG_STREAM__);\
              }\
})
  #endif
#endif 
/**-----------------------------------------------------------------------------------------**/

#endif /* EOF */

