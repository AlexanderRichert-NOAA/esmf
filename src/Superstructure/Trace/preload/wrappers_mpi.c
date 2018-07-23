
/**
 *  wrappers_mpi.c
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

#ifndef ESMF_MPIUNI
#include <mpi.h>

#include "ESMCI_Macros.h"
#include "ESMCI_Trace.h"
#include "preload.h"
#include "wrappers_mpi.h"

extern "C" {

  static int insideMPIRegion = 0;
  
  /*
   * C MPI functions
   */

  
    extern int __real_MPI_Allreduce(ESMF_MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);    

    int __wrap_MPI_Allreduce(ESMF_MPI_CONST void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_MPI_Allreduce (C)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        int ret = __real_MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
        return ret;
      }
      else {
        return __real_MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
      }
    }
  
    extern int __real_MPI_Barrier(MPI_Comm comm);    

    int __wrap_MPI_Barrier(MPI_Comm comm) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_MPI_Barrier (C)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        int ret = __real_MPI_Barrier(comm);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
        return ret;
      }
      else {
        return __real_MPI_Barrier(comm);
      }
    }
  
    extern int __real_MPI_Wait(MPI_Request *request, MPI_Status *status);    

    int __wrap_MPI_Wait(MPI_Request *request, MPI_Status *status) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_MPI_Wait (C)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        int ret = __real_MPI_Wait(request, status);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
        return ret;
      }
      else {
        return __real_MPI_Wait(request, status);
      }
    }
  

  /*
   * Fortran MPI functions
   */

  
    extern void FTN_X(__real_mpi_allgather)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_allgather)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_allgather_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_allgather)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_allgather)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_allgatherv)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_allgatherv)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_allgatherv_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_allgatherv)(sendbuf, sendcount, sendtype, recvbuf, recvcount, displs, recvtype, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_allgatherv)(sendbuf, sendcount, sendtype, recvbuf, recvcount, displs, recvtype, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_allreduce)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_allreduce)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_allreduce_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_allreduce)(sendbuf, recvbuf, count, datatype, op, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_allreduce)(sendbuf, recvbuf, count, datatype, op, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_alltoall)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_alltoall)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_alltoall_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_alltoall)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_alltoall)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_alltoallv)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_alltoallv)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_alltoallv_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_alltoallv)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_alltoallv)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_alltoallw)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_alltoallw)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *sdispls, MPI_Fint *sendtypes, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *rdispls, MPI_Fint *recvtypes, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_alltoallw_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_alltoallw)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_alltoallw)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_barrier)(MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_barrier)(MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_barrier_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_barrier)(comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_barrier)(comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_bcast)(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_bcast)(MPI_Fint *buffer, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_bcast_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_bcast)(buffer, count, datatype, root, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_bcast)(buffer, count, datatype, root, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_exscan)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_exscan)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_exscan_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_exscan)(sendbuf, recvbuf, count, datatype, op, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_exscan)(sendbuf, recvbuf, count, datatype, op, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_gather)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_gather)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_gather_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_gather)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_gather)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_gatherv)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_gatherv)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *displs, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_gatherv_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_gatherv)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_gatherv)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_recv)(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_recv)(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_recv_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_recv)(buf, count, datatype, source, tag, comm, status, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_recv)(buf, count, datatype, source, tag, comm, status, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_reduce)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_reduce)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_reduce_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_reduce)(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_reduce)(sendbuf, recvbuf, count, datatype, op, root, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_reduce_scatter)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_reduce_scatter)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_reduce_scatter_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_reduce_scatter)(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_reduce_scatter)(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_scatter)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_scatter)(MPI_Fint *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_scatter_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_scatter)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_scatter)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_scatterv)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_scatterv)(MPI_Fint *sendbuf, MPI_Fint *sendcounts, MPI_Fint *displs, MPI_Fint *sendtype, MPI_Fint *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_scatterv_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_scatterv)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_scatterv)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_scan)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_scan)(MPI_Fint *sendbuf, MPI_Fint *recvbuf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_scan_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_scan)(sendbuf, recvbuf, count, datatype, op, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_scan)(sendbuf, recvbuf, count, datatype, op, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_send)(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_send)(MPI_Fint *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_send_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_send)(buf, count, datatype, dest, tag, comm, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_send)(buf, count, datatype, dest, tag, comm, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_wait)(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_wait)(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_wait_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_wait)(request, status, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_wait)(request, status, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_waitall)(MPI_Fint *count, MPI_Fint *reqs, MPI_Fint *stats, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_waitall)(MPI_Fint *count, MPI_Fint *reqs, MPI_Fint *stats, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_waitall_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_waitall)(count, reqs, stats, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_waitall)(count, reqs, stats, ierr);
      }
    }
  
    extern void FTN_X(__real_mpi_waitany)(MPI_Fint *count, MPI_Fint *reqs, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr);    

    void FTN_X(__wrap_mpi_waitany)(MPI_Fint *count, MPI_Fint *reqs, MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierr) {
      if (c_esmftrace_isinitialized() == 1 && insideMPIRegion == 0) {
        //printf("__wrap_mpi_waitany_ (Fortran)\n");
        insideMPIRegion = 1;
        ESMCI::TraceMPIWaitStart();
        FTN_X(__real_mpi_waitany)(count, reqs, index, status, ierr);
        ESMCI::TraceMPIWaitEnd();
        insideMPIRegion = 0;
      }
      else {
        FTN_X(__real_mpi_waitany)(count, reqs, index, status, ierr);
      }
    }
  

}
#endif