//
// Earth System Modeling Framework
// Copyright 2002-2007, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.

//
//-----------------------------------------------------------------------------
#ifndef ESMC_Search_h
#define ESMC_Search_h

#include <list>

#include <ESMC_MeshTypes.h>
#include <ESMC_MeshObj.h>
#include <ESMC_OctBox3d.h>
#include <vector>



namespace ESMC {

class Mesh;

// The return type from search.  A list of source grid node to
// destination grid element pairs
struct Search_node_result {
  const MeshObj *node;
  double pcoord[3];  // parametric coord of node in elem
};
struct Search_result {
  const MeshObj *elem;
  std::vector<Search_node_result> nodes;
  bool operator<(const Search_result &rhs) const {
    return elem->get_id() < rhs.elem->get_id();
  }
  bool operator==(const Search_result &rhs) const {
    return elem->get_id() == rhs.elem->get_id();
  }
  bool operator!=(const Search_result &rhs) const {
    return !(*this == rhs);
  }
};
typedef std::vector<Search_result*> SearchResult;


void Search(const Mesh &src, const Mesh &dest, UInt dst_obj_type, SearchResult &result,
            double stol = 1e-8, std::vector<const MeshObj*> *to_investigate = NULL);

void OctSearch(const Mesh &src, const Mesh &dest, UInt dst_obj_type, SearchResult &result,
            double stol = 1e-12, std::vector<const MeshObj*> *to_investigate = NULL, BOX3D *box = NULL);

void PrintSearchResult(const SearchResult &result);

void DestroySearchResult(SearchResult &sres);

} //namespace

#endif
