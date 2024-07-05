#include <stdio.h>
#include<cstdlib>
#include <complex>

#include "wnr_cnpy.h"
#include <vector>

int main(int argc, char** argv) {
    size_t num_vals;
    size_t word_size;
    std::vector<size_t> shape;
    char data_type;

    char* pd = cnpy::npyarray_to_char(argv[1], data_type, word_size, shape, num_vals);

#if 1
    char* px = pd;

    for (int i = 0; i < num_vals; i++) {
        if (data_type == 'i' && word_size == 4) {
            int* p = reinterpret_cast<int*>(px);
            printf("%d ", p[i]);
        }
        if (data_type == 'i' && word_size == 8) {
            long long* p = reinterpret_cast<long long*>(pd);
            printf("%lld ", p[i]);
        }
        if (data_type == 'f' && word_size == 4) {
            float* p = reinterpret_cast<float*>(pd);
            printf("%f ", p[i]);
        }
        if (data_type == 'f' && word_size == 8) {
            double* p = reinterpret_cast<double*>(pd);
            printf("%lf ", p[i]);
        }
    }
    printf("\n");
#endif

#if 0
	int type = atoi(argv[1]);
	if (type == 0) {
		long long* ptr = arr.data<long long>();
		for (int i = 0; i < arr.num_vals;i++) {
			printf("%lld ", ptr[i]);
		}printf("\n");
	} else if (type == 1) {
    	double* ptr = arr.data<double>();
	    for (int i = 0; i < arr.num_vals;i++) {
		    printf("%lf ", ptr[i]);
	    }printf("\n");
    } else if (type == 2) {
		int* ptr = arr.data<int>();
		for (int i = 0; i < arr.num_vals;i++) {
			printf("%d ", ptr[i]);
		}printf("\n");
    } else if (type == 3) {
        std::complex<double>* ptr = arr.data<std::complex<double>>();
		for (int i = 0; i < arr.num_vals;i++) {
			printf("%f_%fj ", ptr[i].real(), ptr[i].imag());
		}printf("\n");

    }
#endif


}
