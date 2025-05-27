#ifndef VTK_WRITER_H
#define VTK_WRITER_H

#include <iostream>
#include <vector> 
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridWriter.h>

class VTKUnstructuredWriter {
public:
  VTKUnstructuredWriter(){
    init();
  };
  ~VTKUnstructuredWriter();
   
  virtual void set_points(std::vector<double>&);
  virtual void set_cells(std::vector<int>&);
  virtual void add_scalar(std::vector<double>&, std::string);
  virtual void add_vector(std::vector<std::vector<double>>&, std::string);
  virtual void write_vtk(std::string);    

protected:
  void init();
  vtkSmartPointer<vtkPoints> points;
  vtkSmartPointer<vtkCellArray> cells;
  vtkSmartPointer<vtkUnstructuredGrid> grid;
};

class VTKTriangleWriter : public VTKUnstructuredWriter {
public:
  void set_cells(std::vector<int>&) override;  
};

class VTKQuadWriter : public VTKUnstructuredWriter {
public:
  void set_cells(std::vector<int>&) override;  
};


#endif
