#include "mpi_.hpp"

template<typename T>
void _cpp3_mpi_rank0(const mpi::communicator& comm, T *max, const T *a, const T *b)
{
    int num = comm.size();

    const unsigned long inc = (b - a)/num;     //size of work per node
    const unsigned long rest = (b - a) % num;

    mpi::request *req = new mpi::request[num-1];
    mpi::request *temp = req;

    const double *a_ = a + inc;
    for(int i = 1; i < num - 1; ++i, a_+=inc, ++temp)
        *temp = comm.isend(i, 0, a_, inc);

    *temp = comm.isend(num-1, 0, a_, inc + rest);
    *max = cpp3_serial(a, a + inc);

    mpi::wait_all(req, req + num - 1);

    mpi::reduce(comm, *max, *max, mpi::maximum<T>(), 0);
    delete[] req;
}

template<typename T>
void _cpp3_mpi_others(const mpi::communicator& comm)
{
    unsigned long size;
    mpi::status stat = comm.probe(0, 0);
    if(stat.count<unsigned long>()) size = *stat.count<unsigned long>();
    else comm.abort(11);

    T *a = (T*)malloc(sizeof(T)*size);
    comm.recv(0, 0, a, size);

    T max = cpp3_serial(a, a + size);
    mpi::reduce(comm, max, mpi::maximum<T>(), 0);
    free(a);
}

template<typename T>
void cpp3_mpi(const mpi::communicator& comm, T *max, const T *a, const T *b)
{
    int rank = comm.rank();
    const unsigned long size = b - a;

    if(size < CUTOFF3)
    {
        if(rank == 0) *max = cpp3_serial(a, b);
        return;
    }
    if(rank == 0) _cpp3_mpi_rank0(comm, max, a, b);
    else _cpp3_mpi_others<T>(comm);
}

template<typename T>
void _cpp3_mpi_rank0_tbb(const mpi::communicator& comm, T *max, const T *a, const T *b)
{
    int num = comm.size();

    const unsigned long inc = (b - a)/num;     //size of work per node
    const unsigned long rest = (b - a) % num;

    mpi::request *req = new mpi::request[num-1];
    mpi::request *temp = req;

    const double *a_ = a + inc;
    for(int i = 1; i < num - 1; ++i, a_+=inc, ++temp)
        *temp = comm.isend(i, 0, a_, inc);

    *temp = comm.isend(num-1, 0, a_, inc + rest);
    *max = cpp3_tbb_reduce(a, a + inc);

    mpi::wait_all(req, req + num - 1);

    mpi::reduce(comm, *max, *max, mpi::maximum<T>(), 0);
    delete[] req;
}

template<typename T>
void _cpp3_mpi_others_tbb(const mpi::communicator& comm)
{
    unsigned long size;
    mpi::status stat = comm.probe(0, 0);
    if(stat.count<unsigned long>()) size = *stat.count<unsigned long>();
    else comm.abort(11);

    T *a = (T*)malloc(sizeof(T)*size);
    comm.recv(0, 0, a, size);

    T max = cpp3_tbb_reduce(a, a + size);
    mpi::reduce(comm, max, mpi::maximum<T>(), 0);
    free(a);
}

template<typename T>
void cpp3_mpi_tbb(const mpi::communicator& comm, T *max, const T *a, const T *b)
{
    int rank = comm.rank();
    const unsigned long size = b - a;

    if(size < CUTOFF3)
    {
        if(rank == 0) *max = cpp3_serial(a, b);
        return;
    }
    if(rank == 0) _cpp3_mpi_rank0_tbb(comm, max, a, b);
    else _cpp3_mpi_others_tbb<T>(comm);
}