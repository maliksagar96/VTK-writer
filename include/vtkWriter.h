#ifndef VTK_WRITER_H
#define VTK_WRITER_H

#include <iostream>
#include <vector> 
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridWriter.h>

class writeVTK_unstructured {
public:
  writeVTK_unstructured(std::string fileName){
    init();
  };
  ~writeVTK_unstructured(); 
  void write_vtk(std::string);    
  void set_points(std::vector<double>&);
  void set_cells(std::vector<int>&);
  void add_scalar(std::vector<double>&, std::string);
  void add_vector(std::vector<std::vector<double>>&, std::string);

private:
  void init();
  vtkSmartPointer<vtkPoints> points;
  vtkSmartPointer<vtkCellArray> cells;
  vtkSmartPointer<vtkUnstructuredGrid> grid;
};

#endif
