#include "debug.h"
#include "test_function.h"

void 
call(void)
{
    int stop = 0;
    while(stop++ < 10) 
          dprintf("%d",sum(stop,stop + 1));   
    
    dpoint();
}

int main(void) {
	dset("test.log","w");
	call();
        dwarning_if(!fopen(NULL,"r"));
	dpoint();
	dclose();

	return 0;
}


