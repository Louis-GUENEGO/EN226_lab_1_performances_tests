#include "exercices.h"

static void PrintFloatToFile( FILE * file, double f ) {
	char buf[32];
	char * pch;
	sprintf( buf, "%f\n", f );
	pch = strchr( buf, '.' );
	*pch = ',';
	fprintf( file, buf );
}

static int DoSomething( int a, int b ) {
	return a + b;
}

static int DoSomethingA( int a ) {
	return 3 * a;
}

static int DoSomethingB( int a ) {
	return a / 10;
}

void Go1( unsigned int count, unsigned int stride ) { // count=nbr de mul par 17, stride=saut de case 1=toutes les cases, 2 une case sur deux

	const unsigned int arrSize = 64 * 1024 * 1024; // 2^26
	int * ary = (int *)malloc( sizeof( int ) * arrSize ); // malloc de 2^26 ints

	StartTimer();

	for ( unsigned int i = 0; i < count; ++i ) { // on réitère la boucle (exposant 17)
		for ( unsigned int j = 0; j < arrSize; j += stride ) { // compteur du nombre de cases (2^26)
			ary[j] *= 17; // on multiplie chaque case
		}
	}

	double t = GetTimer();

	PrintFloatToFile( pPerf1, t );

	printf( "(II) Executed in %f ms\n", t );

	free( ary );
}

void Go2( unsigned int steps, unsigned int arrSize, unsigned int clSize ) {

	int * ary = (int *)malloc( sizeof( int ) * arrSize );
	unsigned int asm1 = arrSize - 1;

	StartTimer();

	for ( unsigned int i = 0; i < steps; ++i) {
		ary[ ( i * clSize ) & asm1 ]++; // incrémente toutes les clSize case (saut de clSize) (asm1 protege des overflows)
	}

	double t = GetTimer();

	PrintFloatToFile( pPerf2, ( ( steps * clSize * 4 ) ) / t*1000 /1024/1024 ); // nombre de pas * nombre de donné * nbr de octect par mot / temps
																																					  // Mo/s

	printf( "(II) Executed in %f ms\n", t );

	free( ary );
}

void Go3() {
	for ( int i = 0; i < 1000; i++ ) {
		for ( int j = 0; j < 1000; j++ ) {
			if ( j % 2 == 0 ) {
				DoSomething( i, j );
			}
		}
	}
}

void Go4() {

	int steps = 256 * 1024 * 1024;
	int * a = (int *) malloc( sizeof( int ) * 2 );

	StartTimer();

	for ( int i = 0; i < steps; i++ ) { a[0]++; a[0]++; }

	double t = GetTimer();

	printf( "(II) Executed in %f ms\n", t );

	StartTimer();

	for ( int i = 0; i < steps; i++ ) { a[0]++; a[1]++; }

	t = GetTimer();

	printf( "(II) Executed in %f ms\n", t);
}


void Go5() {

	StartTimer();

	for ( int i = 0; i < 100000000; ++i ) {
		DoSomethingA( i );
	}

	printf( "(II) Executed in %f ms\n", GetTimer() );

	StartTimer();

	for ( int i = 0; i < 100000000; i += 2 ) {
		DoSomethingA( i );
		DoSomethingA( i + 1 );
	}
	
	printf( "(II) Executed in %f ms\n", GetTimer() );

	StartTimer();
	
	for ( int i = 0; i < 100000000; i += 3 ) {
		DoSomethingA( i );
		DoSomethingA( i + 1 );
		DoSomethingA( i + 3 );
	}
	
	printf( "(II) Executed in %f ms\n", GetTimer() );
	
	StartTimer();
	
	for ( int i = 0; i < 100000000; i += 4 ) {
		DoSomethingA( i );
		DoSomethingA( i + 1 );
		DoSomethingA( i + 3 );
		DoSomethingA( i + 4 );
	}
	
	printf( "(II) Executed in %f ms\n", GetTimer() );
	
	StartTimer();
	
	for ( int i = 0; i < 100000000; i += 5 ) {
		DoSomethingA( i );
		DoSomethingA( i + 1 );
		DoSomethingA( i + 3 );
		DoSomethingA( i + 4 );
		DoSomethingA( i + 5 );
	}
	
	printf( "(II) Executed in %f ms\n", GetTimer() );
}

void Go6() {

	int a1, a2;

	StartTimer();

	for ( int j = 0; j < 10; j++ ) {
		for ( int i = 0; i < 100000000; i += 2 ) {
			DoSomethingA( i );
			DoSomethingB( i );
			DoSomethingA( i + 1 );
			DoSomethingB( i + 1 );
		}
	}

	printf( "(II) Executed in %f ms\n", GetTimer() );

	StartTimer();

	for ( int j = 0; j < 10; j++ ) {
		for ( int i = 0; i < 100000000; i += 2 ) {
			a1 = DoSomethingA( i );
			DoSomethingB( a1 );
			a2 = DoSomethingA( i + 1 );
			DoSomethingB( a2 );
		}
	}

	printf( "(II) Executed in %f ms\n", GetTimer() );

	StartTimer();

	for ( int j = 0; j < 10; j++ ) {
		for ( int i = 0; i < 100000000; i += 2 ) {
			a1 = DoSomethingA( i );
			a2 = DoSomethingA( i + 1 );
			DoSomethingB( a1 );
			DoSomethingB( a2 );
		}
	}

	printf( "(II) Executed in %f ms\n", GetTimer() );
}
