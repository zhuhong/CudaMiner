#ifndef TITAN_KERNEL_H
#define TITAN_KERNEL_H

#include "salsa_kernel.h"

class TitanKernel : public KernelInterface
{
public:
    TitanKernel();

    virtual void set_scratchbuf_constants(int MAXWARPS, uint32_t** h_V);
    virtual bool run_kernel(dim3 grid, dim3 threads, int WARPS_PER_BLOCK, int thr_id, cudaStream_t stream, uint32_t* d_idata, uint32_t* d_odata, bool interactive, bool benchmark, int texture_cache);

    virtual char get_identifier() { return 'T'; };
    virtual int get_major_version() { return 1; }
    virtual int get_minor_version() { return 0; }
    virtual int max_warps_per_block() { return 24; };
    virtual int get_texel_width() { return 4; };
    virtual bool no_textures() { return true; };
    virtual cudaSharedMemConfig shared_mem_config() { return cudaSharedMemBankSizeEightByte; }
};

#endif // #ifndef TITAN_KERNEL_H
