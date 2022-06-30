#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long unsigned int *gprime(int *nprime,long long unsigned int num  ){

	long long unsigned int *vec = malloc( sizeof(long long unsigned int ) * (num/2) );
	int i = 3,j,k,npr = 1;
	vec[0] = 3;
	
	up:
	i += 2;
	for(;i < num;i += 2){
        for(j = 0;vec[j] <  i;++j){
			if( !(i % vec[j])){ goto up; }
		}
		vec[npr++] = i;
	}
    *nprime = npr;
	return vec;
}

int main(int arg,char ** argv){

	long long unsigned num;
    sscanf(argv[1]," %llu",&num);
    //long long unsigned int num = 999999;
    clock_t start = clock();
    int numprim;
	long long unsigned int * vec = gprime(&numprim,num);
    clock_t end = clock();
	
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	//for(int i = 0;i < numprim;i += 100){ printf("%lld\n",vec[i]); }
	printf("TIME:%f\n",seconds);
    free(vec);
}
