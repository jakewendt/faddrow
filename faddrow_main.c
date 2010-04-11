/*****************************************************************************
  Component : faddrow
  Developer : Jake
              Integral Science Data Center
        
  Purpose   : Add a row to a table

*****************************************************************************/

#include "faddrow.h"

int main( int argc, char *argv[]){
	int  mode = 0;
	int  status = ISDC_OK ;
	char inDol[PIL_LINESIZE]    = "";
	int  numrows = 1;
	fitsfile *fPtr              = NULL;

	/* Executable initialisation */
	mode = CommonInit(COMPONENT_NAME,COMPONENT_VERSION,argc,argv);
	if(mode != ISDC_SINGLE_MODE ){
		RILlogMessage(NULL,Error_1,"CommonInit: mode = %d ", mode); 
		mode=CommonExit(mode);
	}    
	
	status = get_parameters(inDol, &numrows, status);

	RILlogMessage ( NULL, Log_1, "About to add %d rows to %s.", numrows, inDol );

	if ( ! fits_open_file ( &fPtr, inDol, READWRITE, &status) ) {
		RILlogMessage ( NULL, Log_1, "inDol opened." );
/*		status = fits_insert_rows (fPtr, (fPtr->Fptr)->numrows, numrows, &status); */
/*		if ( fits_insert_rows (fPtr, (fPtr->Fptr)->numrows, numrows, &status) ) {	*/
		if ( fits_insert_rows (fPtr, 0, numrows, &status) ) {
			RILlogMessage ( NULL, Log_1, "fits_insert_rows failed." );
		}
		fits_close_file(fPtr, &status);
		RILlogMessage ( NULL, Log_1, "inDol closed." );
	} else {
		RILlogMessage ( NULL, Log_1, "inDol open failed." );
	}

	mode = CommonExit(status);
	return(mode); 
}

/* EOF */
