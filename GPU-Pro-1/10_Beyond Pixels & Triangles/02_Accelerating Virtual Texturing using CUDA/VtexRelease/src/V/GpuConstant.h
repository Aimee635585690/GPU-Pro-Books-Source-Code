/**
 *
 *  This software module was originally developed for research purposes,
 *  by Multimedia Lab at Ghent University (Belgium).
 *  Its performance may not be optimized for specific applications.
 *
 *  Those intending to use this software module in hardware or software products
 *  are advized that its use may infringe existing patents. The developers of 
 *  this software module, their companies, Ghent Universtity, nor Multimedia Lab 
 *  have any liability for use of this software module or modifications thereof.
 *
 *  Ghent University and Multimedia Lab (Belgium) retain full right to modify and
 *  use the code for their own purpose, assign or donate the code to a third
 *  party, and to inhibit third parties from using the code for their products. 
 *
 *  This copyright notice must be included in all copies or derivative works.
 *
 *  For information on its use, applications and associated permission for use,
 *  please contact Prof. Rik Van de Walle (rik.vandewalle@ugent.be). 
 *
 *  Detailed information on the activities of
 *  Ghent University Multimedia Lab can be found at
 *  http://multimedialab.elis.ugent.be/.
 *
 *  Copyright (c) Ghent University 2004-2009.
 *
 **/

#pragma once

/**
    This wraps constant memory on the gpu
    i.e. globals declared with __constant__
*/
template <class Type> class klGpuConstantWrapper {
    Type cpuShadow;
    char *name;
public:

    klGpuConstantWrapper(const char *name) {
        this->name = _strdup(name);
        cudaError_t error;
        size_t size;
        error = cudaGetSymbolSize(&size, name);
        if ( error == cudaErrorInvalidSymbol ) {
            klFatalError("Symbol '%s' not found\n");
        } else if ( error != cudaSuccess ) {
            klFatalError("Unspecified error wrapping '%s'\n");
        }
        assert( size = sizeof(Type) );
    }

    ~klGpuConstantWrapper(void) {
        free(name);
    }

    Type &get() {
        return cpuShadow;
    }


    void update(void) {
        klCudaError(cudaMemcpyToSymbol(name, &cpuShadow, sizeof(cpuShadow), 0, cudaMemcpyHostToDevice));
    }
};
