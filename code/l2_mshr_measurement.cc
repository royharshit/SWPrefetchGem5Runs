#include <unistd.h>
#include <asm/unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdint>
#include <cinttypes>


#include <gem5/m5ops.h>


const size_t memsize = 128 * 1024 * 1024;
const size_t elems = memsize / sizeof(uint32_t);
const int DISTANCE = 16;

int hash(int data) {
    return 9*data % 17;
}

uint32_t time_nonprefetch_h0(uint32_t *data) {
    uint32_t sum = 0;
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += data[i];
    }
    m5_work_end(0, 0);
    return sum;
}

uint32_t time_prefetch_h0(uint32_t *data) {
    uint32_t sum = 0;
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += data[i];
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += data[i];
    }
    m5_work_end(0, 0);
    return sum;
}

uint32_t time_nonprefetch_h1(uint32_t *data) {
    uint32_t sum = 0;
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(data[i]);
    }
    m5_work_end(0, 0);
    return sum;
}

uint32_t time_prefetch_h1(uint32_t *data) {
    uint32_t sum = 0;
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(data[i]);
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(data[i]);
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_nonprefetch_h2(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(data[i]));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h2(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(data[i]));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(data[i]));
    }
    m5_work_end(0, 0);
    return sum;
}

uint32_t time_nonprefetch_h3(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(hash(data[i])));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h3(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(hash(data[i])));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(hash(data[i])));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_nonprefetch_h4(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(hash(hash(data[i]))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h4(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(hash(hash(data[i]))));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(hash(hash(data[i]))));
    }
    m5_work_end(0, 0);
    return sum;
}

uint32_t time_nonprefetch_h5(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(data[i])))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h5(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(hash(hash(hash(data[i])))));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(data[i])))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_nonprefetch_h6(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(data[i]))))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h6(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(hash(hash(hash(hash(data[i]))))));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(data[i]))))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_nonprefetch_h7(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(hash(data[i])))))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h7(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(hash(hash(hash(hash(hash(data[i])))))));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(hash(data[i])))))));
    }
    m5_work_end(0, 0);
    return sum;
}

uint32_t time_nonprefetch_h8(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(hash(hash(data[i]))))))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h8(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(hash(hash(hash(hash(hash(hash(data[i]))))))));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(hash(hash(data[i]))))))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_nonprefetch_h9(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(hash(hash(hash(data[i])))))))));
    }
    m5_work_end(0, 0);
    return sum;
}


uint32_t time_prefetch_h9(uint32_t *data) {
    uint32_t sum = 0; 
    m5_work_begin(0, 0);
    for (int i = 0; i < elems - DISTANCE; i++) {
	__builtin_prefetch(&data[i + DISTANCE]);
    	sum += hash(hash(hash(hash(hash(hash(hash(hash(hash(data[i])))))))));
    }
    for (int i = elems - DISTANCE; i < elems; i++) {
    	sum += hash(hash(hash(hash(hash(hash(hash(hash(hash(data[i])))))))));
    }
    m5_work_end(0, 0);
    return sum;
}


int main() {

    uint32_t* data = (uint32_t*)malloc(memsize);
    uint64_t sum1, sum2;

    for (uint32_t i = 0; i < elems; i++) {
    	data[i] = i;
    }

    int32_t N = 0;

        while (N < 8) { 
            if (N == 0) {
		printf("Non Prefetch H0\n");
		m5_reset_stats(100000,0);
		sum1 = time_nonprefetch_h0(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H0 sum %lu\n", sum1);
            }
            if (N == 1) {
		printf("Non Prefetch H1\n");
		m5_reset_stats(100000,0);
                sum1 = time_nonprefetch_h1(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H1 sum %lu\n", sum1);
            }
            else if (N == 2) {
		printf("Non Prefetch H2\n");
		m5_reset_stats(100000,0);
                sum1 = time_nonprefetch_h2(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H2 sum %lu\n", sum1);
	    }
            else if (N == 3) {
		printf("Non Prefetch H3\n");
		m5_reset_stats(1000000,0);
                sum1 = time_nonprefetch_h3(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H3 sum %lu\n", sum1);
	    }
            else if (N == 4) {
		printf("Non Prefetch H4\n");
		m5_reset_stats(1000000,0);
                sum1 = time_nonprefetch_h4(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H4 sum %lu\n", sum1);
	    }
            else if (N == 5) {
		printf("Non Prefetch H5\n");
		m5_reset_stats(1000000,0);
                sum1 = time_nonprefetch_h5(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H5 sum %lu\n", sum1);
	    }
            else if (N == 6) {
		printf("Non Prefetch H6\n");
		m5_reset_stats(10000000,0);
                sum1 = time_nonprefetch_h6(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H6 sum %lu\n", sum1);
	    }
            else if (N == 7) {
		printf("Non Prefetch H7\n");
		m5_reset_stats(10000000,0);
                sum1 = time_nonprefetch_h7(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H7 sum %lu\n", sum1);
	    }
            else if (N == 8) {
		printf("Non Prefetch H8\n");
		m5_reset_stats(10000,0);
                sum1 = time_nonprefetch_h8(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H8 sum %lu\n", sum1);
	    }
            else if (N == 9) {
		printf("Non Prefetch H9\n");
		m5_reset_stats(10000,0);
                sum1 = time_nonprefetch_h9(data);
		m5_dump_stats(0, 0);
		printf("Non Prefetch H9 sum %lu\n", sum2);
	    }
            if (N == 0) {
		printf("Prefetch H0\n");
		m5_reset_stats(10000,0);
            	sum2 = time_prefetch_h0(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H0 sum %lu\n", sum2);
	    }
            if (N == 1) {
		printf("Prefetch H1\n");
		m5_reset_stats(10000,0);
            	sum2 = time_prefetch_h1(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H1 sum %lu\n", sum2);
	    }
            else if (N == 2) {    
		printf("Prefetch H2\n");
		m5_reset_stats(10000,0);
            	sum2 = time_prefetch_h2(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H2 sum %lu\n", sum2);
	    }
            else if (N == 3) {
		printf("Prefetch H3\n");
		m5_reset_stats(50000,0);
            	sum2 = time_prefetch_h3(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H3 sum %lu\n", sum2);
	    }
            else if (N == 4) {
		printf("Prefetch H4\n");
		m5_reset_stats(100000,0);
            	sum2 = time_prefetch_h4(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H4 sum %lu\n", sum2);
	    }
            else if (N == 5) {
		printf("Prefetch H5\n");
		m5_reset_stats(1000000,0);
            	sum2 = time_prefetch_h5(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H5 sum %lu\n", sum2);
	    }
            else if (N == 6) {
		printf("Prefetch H6\n");
		m5_reset_stats(1000000,0);
            	sum2 = time_prefetch_h6(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H6 sum %lu\n", sum2);
	    }
            else if (N == 7) {
		printf("Prefetch H7\n");
		m5_reset_stats(10000000,0);
            	sum2 = time_prefetch_h7(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H7 sum %lu\n", sum2);
	    }
            else if (N == 8) {
		printf("Prefetch H8\n");
		m5_reset_stats(10000,0);
            	sum2 = time_prefetch_h8(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H8 sum %lu\n", sum2);
	    }
            else if (N == 9) {
		printf("Prefetch H9\n");
		m5_reset_stats(10000,0);
            	sum2 = time_prefetch_h9(data);
		m5_dump_stats(0, 0);
		printf("Prefetch H9 sum %lu\n", sum2);
	    }
            N++;

        }
}

