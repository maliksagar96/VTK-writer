#ifndef VTK_ALL_TRI
#define VTK_ALL_TRI

#include "vtkWriter.h"

class all_tri::writeVTK_unstructured {
  void set_points(std::vector<double>&);
  void set_cells(std::vector<int>&);
  void add_scalar(std::vector<double>&, std::string);
  void add_vector(std::vector<std::vector<double>>&, std::string);
  void write_vtk(std::string);    

}

#endif