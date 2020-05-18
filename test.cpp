#include <mex.h>
#include "matrix.h"

void convec(mxArray * x, mxArray * y, mxArray * z,
            size_t nx, size_t ny)
{
    mwSize i,j;

    /* get pointers to the complex arrays */
    mxComplexDouble * xc = mxGetComplexDoubles(x);
    mxComplexDouble * yc = mxGetComplexDoubles(y);
    mxComplexDouble * zc = mxGetComplexDoubles(z);
    zc[0].real = 0;
    zc[0].imag = 0;
    /* perform the convolution of the complex vectors */
    for(i=0; i<nx; i++) {
        for(j=0; j<ny; j++) {
            zc[i+j].real =
            zc[i+j].real + xc[i].real * yc[j].real - xc[i].imag * yc[j].imag;

            zc[i+j].imag =
            zc[i+j].imag + xc[i].real * yc[j].imag + xc[i].imag * yc[j].real;
        }
    }
}

/* The gateway routine. */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
    /* check for the proper number of arguments */
    if(nrhs != 2)
      mexErrMsgIdAndTxt( "MATLAB:convec:invalidNumInputs",
              "Two inputs required.");
    if(nlhs > 1)
      mexErrMsgIdAndTxt( "MATLAB:convec:maxlhs",
              "Too many output arguments.");
    
    size_t rows, cols;
    size_t nx, ny;

    /* get the length of each input vector */
    nx = mxGetN(prhs[0]);
    ny = mxGetN(prhs[1]);

    rows = 1; 
    cols = nx + ny - 1;
    
    plhs[0] = mxCreateDoubleMatrix( (mwSize)rows, (mwSize)cols, mxCOMPLEX);
    
    return;
}