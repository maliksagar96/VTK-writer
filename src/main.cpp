#include <iostream>
#include "vtkWriter.h"
#include <vector> 

using namespace std;

int main() {
  vector<double> coords = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0};
  vector<int> connectivity = {0, 1, 2, 1,3,2};
  vector<double> scalara = {1.0, 2.0};
  vector<vector<double>> electricField = {{1.0, 0.0, 0.0}, {2, 0, 0}};

  writeVTK_unstructured* vtk2elements = new writeVTK_unstructured();
  vtk2elements->set_points(coords);
  vtk2elements->set_cells(connectivity);
  vtk2elements->add_scalar(scalara, "MyScalar");
  // vtk2elements->add_vector(electricField, "EField");
  vtk2elements->write_vtk("out.vtk");

  return 0;
}