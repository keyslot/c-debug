# debug-header

Simple header to follow your c code. 

## Use

These functions return nothing. Except dpoint, which is a int method and returns the current line runing of your code. 
Also dprintf, that returns a call to fprintf.  

| Method          | Description                                                                                                                 | 
|-----------------|-----------------------------------------------------------------------------------------------------------------------------|
|dset(path,mode); | Sets a log_file, similar to call fopen. i.e. dset("./test.log","a+").                                                       | 
|dauto();         | Sets a log_file automatically from the call source and save it at the same path of the source C file. The mode used is "a+".|
|dpoint();        | Marks a point of code runing.                                                                                               |
|dprintf(...);    | Call to fprintf using the log_file (if it's open),  i.e. dprintf("Value of x %d",x).                                        |  
|dclose();        | Close a log_file if was opened.                                                                                             | 
|dexit_if(e);     | Exit if the logic expr e, save the log_file and call an `EXIT_FAILURE`.                                                     |
|dwarning_if(e);  | Shows a warning if the logic expr e, save the log_file.                                                                     |

The log_file is a FILE *; 

### Include and config.

1. Use \#include \<"debug.h"\>. where you want to use this. 
2. In debug.h, set the macro DEBUG(1) or DEBUG (0) to enable/disable the debug mode. If you enable it, don't forget to set the log_file. 

When you define DEBUG(0) all prints except dexit_if and dwarning_if are excluded.  
This's a hard-code. Is faster avoid ask when use the methods, in other words, avoid conditionals abuse. 

## Compile a Test

1. Use the Makefile to create test.exe. from the source in the dir. test. 
1. Run test.exe. 
1. See test.log. 

## Security 

This proyect is an experimental code and is insecure using with threads.
Please implement a mutex.  
Adapt this header for you proyect.  

You can change the methods in src/debug/


