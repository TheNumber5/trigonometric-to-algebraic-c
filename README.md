A simple C program that converts complex numbers from trigonometric form to algebraic form (WIP - Might be buggy)
# Instructions

*Convert from file:* `trigonometrictoalgebraic.exe -f <input file name> <output file name>`
The input file must contain the modulus and argument in order. The output file contains the real and imaginary parts respective.

*Direct mode via terminal:* `trigonometrictoalgebraic.exe -d <modulus> <argument>`
Needs input like in the file mode. Will output to the console the algebraic form in `<real> <imaginary>`.

*Benchmark (experimental):* `trigonometrictoalgebraic.exe -b n`
This creates `n` complex numbers in trigonometric form and converts them into algebraic form. This function is only for testing the CPU, the numbers are not printed to the console because this will slow down the process. The time needed for the processing is then displayed in milliseconds.

# TODO
Make the algorithm more efficient, and add organized error-checking for bad input.
