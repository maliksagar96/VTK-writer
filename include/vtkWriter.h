#ifndef VTK_WRITER_H
#define VTK_WRITER_H

#include <iostream>
#include <vector> 
#include <vtkPoints.h>
#include <vtkSmartPointer.h>

class writeVTK_unstructured {
  public:
    writeVTK_unstructured(std::string fileName);  // Constructor
    ~writeVTK_unstructured(); 
    void write_vtk(std::string);
    void set_points(std::vector<double>&);

    vtkSmartPointer<vtkPoints> points;
};

#endif
