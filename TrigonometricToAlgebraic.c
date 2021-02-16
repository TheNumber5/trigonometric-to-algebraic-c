#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> //TODO: Use less libraries

typedef struct algebraic_complex {
    float real;
    float imaginary;
} algebraic_cmp;

typedef struct trigonometric_complex {
    float modulus;
    float argument;
    //TODO: make better names for these
} trigonometric_cmp;

void convert_to_algebraic(float modulus, float argument, unsigned int mode, FILE* out_file) {
    trigonometric_cmp trig_num;
    trig_num.modulus = modulus;
    trig_num.argument = argument;
    algebraic_cmp algeb_num;
    algeb_num.real = trig_num.modulus*cos(trig_num.argument);
    algeb_num.imaginary = trig_num.modulus*sin(trig_num.argument);
    if(mode==0) {
        printf("%f %f", algeb_num.real, algeb_num.imaginary);
    }
    else if(mode==1) {
        fprintf(out_file, "%f %f\n", algeb_num.real, algeb_num.imaginary);
    }
}

int main(int argc, char** argv) {
    float modulus, argument;
    if(!strcmp("-d", argv[1])) {
        modulus = atof(argv[2]);
        argument = atof(argv[3]);
        convert_to_algebraic(modulus, argument, 0, 0);
    }
    else if(!strcmp("-f", argv[1])) {
        FILE *in_file, *out_file;
        in_file = fopen(argv[2], "wb");
        out_file = fopen(argv[3], "rb");
        do {
            fscanf(in_file, "%f", &modulus);
            fscanf(in_file, "%f", &argument);
            convert_to_algebraic(modulus, argument, 1, out_file);
        } while(!feof(in_file));
        fclose(in_file);
        fclose(out_file);
    }
    else if(!strcmp("-b", argv[1])) {
        clock_t tick = clock();
        for(int i=0; i<atoi(argv[2]); i++) {
            modulus = rand()%1000000;
            argument = rand()%1000000;
            convert_to_algebraic(modulus, argument, 2, 0);
        }
        clock_t tock = clock();
        double benchmark_time = (double)(tock-tick)/CLOCKS_PER_SEC;
        printf("Benchmark time: %fms", benchmark_time);
        //Very exotic way of benchmarking a computer
    }
return 0;
}
