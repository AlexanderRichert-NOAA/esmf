
/**
 *  wrappers_mpi.h
 *
 *  !! DO NOT EDIT !!
 *  This file was generated by gen_wrappers_mpi.py.
 *  !! DO NOT EDIT !!
 *
 *  Wrappers for MPI calls so we can trace them.
 *  These are linked statically into the executable using
 *  --wrap=SYMBOL flags to the linker.
 *
 */

#ifndef _WRAPPERS_MPI_H
#define _WRAPPERS_MPI_H

#ifndef ESMF_MPIUNI

#include <mpi.h>

#ifdef MPICH2_CONST
#define ESMF_MPI_CONST MPICH2_CONST
#else
#define ESMF_MPI_CONST const
#endif

extern "C" {
  
  int __wrap_MPI_Allreduce(ESMF_MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
  
  int __wrap_MPI_Barrier(MPI_Comm comm);
  
  int __wrap_MPI_Wait(MPI_Request *request, MPI_Status *status);
  

  
  void FTN_X(__wrap_mpi_allgather)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_allgatherv)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_allreduce)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_alltoall)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_alltoallv)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_alltoallw)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_barrier)(MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_bcast)(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_exscan)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_gather)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_gatherv)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_recv)(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_reduce)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_reduce_scatter)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_scatter)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_scatterv)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_scan)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_send)(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_wait)(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_waitall)(MPI_Fint *count, MPI_Fint *reqs, MPI_Fint *stats, MPI_Fint *ierr);
  
  void FTN_X(__wrap_mpi_waitany)(MPI_Fint *count, MPI_Fint *reqs, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr);
  
}

#endif
#endif