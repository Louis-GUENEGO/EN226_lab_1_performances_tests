#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <math.h>

#include "exercices.h"

FILE * pPerf1 = NULL;
FILE * pPerf2 = NULL;

int main( int argc, char ** argv ) {

	pPerf1 = fopen( "perfgo1", "w" ); // creation et ecrasement de perfgo1
	pPerf2 = fopen( "perfgo2", "w" );

	if ( argc == 2 ) {

		if ( strcmp( argv[1], "Go1" ) == 0 ) {

			printf( "(II) --------------------\n" );
			printf( "(II) Now running Go1 test\n" );
			printf( "(II) --------------------\n" );

			for ( unsigned int i = 0; i <= 27; i++ ) {
				Go1( 10, (unsigned int)pow( 2.0, (double)i ) );
			}

		}else if ( strcmp( argv[1], "Go2" ) == 0 ) {

			printf( "(II) --------------------\n" );
			printf( "(II) Now running Go2 test\n" );
			printf( "(II) --------------------\n" );

			for ( unsigned int i = 0; i <= 27; i++ ) {
				Go2( 100000000, (unsigned int)pow( 2.0, (double)i ), 16 ); //steps, nbr mots,
			}

		}else if ( strcmp( argv[1], "Go3" ) == 0 ) {

			printf( "(II) --------------------\n" );
			printf( "(II) Now running Go3 test\n" );
			printf( "(II) --------------------\n" );

			Go3();

		}else if ( strcmp( argv[1], "Go4" ) == 0 ) {

			printf( "(II) --------------------\n" );
			printf( "(II) Now running Go4 test\n" );
			printf( "(II) --------------------\n" );

			Go4();

		}else if ( strcmp( argv[1], "Go5" ) == 0 ) {

			printf( "(II) --------------------\n" );
			printf( "(II) Now running Go5 test\n" );
			printf( "(II) --------------------\n" );

			Go5();

		}else if ( strcmp( argv[1], "Go6" ) == 0 ) {

			printf( "(II) --------------------\n" );
			printf( "(II) Now running Go6 test\n" );
			printf( "(II) --------------------\n" );

			Go6();

		}

	}else {
		printf( "Bad usage\n" );
	}

	fclose( pPerf1 );
	fclose( pPerf2 );

	return 1;
}
