
#include "faddrow.h"

/******************************************************************************
	
	get_parameters
	
 ******************************************************************************/
int get_parameters(
			char  *inDol, 
			int   *numrows, 
			int    status ) {
	
	if (status != ISDC_OK) { return(status); }

	/* Index of prepared science window group */
	if (status == ISDC_OK) { status = PILGetDOL("inDol", inDol); }
	if(strlen(inDol) == 0){ 
		RILlogMessage(NULL,Error_1," inDol parameter empty! ");
		return(status);
	}

	/* versioning */
	if (status == ISDC_OK) { status = PILGetInt("numrows", numrows); }
	
	return(status);
}









