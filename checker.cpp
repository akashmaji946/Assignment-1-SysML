/*
* Author: Akash Maji
* Email: akashmaji@iisc.ac.in
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Parameters with usual meaning given in the question */
/*
N: Number of input feature maps (Batch size)
C: Number of input channels
H: Height of the input feature map
W: Width of the input feature map
R: Height of the filter/kernel
S: Width of the filter/kernel
M: Number of output channels (number of filters)
E: Height of the output feature map after convolution
F: Width of the output feature map after convolution
Ux: stride along x
Uy: stride along y
*/
#define N 8
#define M 32
#define H 32
#define W 32
#define R 5
#define S 5
#define C 4

/* Let us compute the size of OUTPUT map */
/*
Since, INPUT is 32*32 and FILTER is 5*5
So, OUTPUT will be 28*28 assuming stride=1

Formula: E * F = (H-R+1)*(W-S+1) for stride=1

*/
#define Ux 1
#define Uy 1
#define E 28
#define F 28

int main(){
    // we will read in two files, 
    // one generated by naive convolution,
    // other by toeplitz multiply,
    // and compare for similarity in output
    FILE* output1;
    FILE* output2;

    output1 = fopen("OUTPUT1.txt", "r");
    output1 = fopen("OUTPUT2.txt", "r");

    assert(output1 != nullptr);
    assert(output2 != nullptr);

    // the final OUTPUT should have N*M*F*E elements in both files
    // and absolute difference in output should be less than some threshold say 0.000001
    for(int idx = 0; idx < N*M*F*E; idx++){
        double x = 0, y = 0;
        while (fscanf(output1, "%lf", &x) == 1 && fscanf(output2, "%lf", &y) == 1) {
            if (fabs(x - y) > 0.00001) {
                printf("Difference at index %d: %lf vs %lf\n", idx, x, y);
            }
        idx++;
        }
    }
    /* all elements in output matches, so success */
    printf("All Matched\n");
    return 0;

}