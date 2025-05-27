#include <iostream>
#include "vtkWriter.h"
#include <vector> 

using namespace std;

int main() {
/**Test Code to generate an all Tri file **/

  // vector<double> coords = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0};
  // vector<int> connectivity = {0, 1, 2, 1,3,2};
  // vector<double> scalara = {1.0, 2.0};
  // vector<vector<double>> electricField = {{1.0, 0.0, 0.0}, {2, 0, 0}};

  // VTKTriangleWriter vtk2elements;
  // vtk2elements.set_points(coords);
  // vtk2elements.set_cells(connectivity);
  // vtk2elements.add_scalar(scalara, "MyScalar");
  // vtk2elements.add_vector(electricField, "EField");
  // vtk2elements.write_vtk("tri.vtk");

  /** Test code to generate an all Quad File **/
  vector<double> coords = {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 2,0,0, 2,1,0};
  vector<int> connectivity = {0, 1, 2, 3, 1, 4, 5, 2};
  vector<double> scalara = {1.0, 2.0};
  vector<vector<double>> electricField = {{1.0, 0.0, 0.0}, {2.0, 0.0, 0.0}};

  VTKQuadWriter vtk2elements;
  vtk2elements.set_points(coords);
  vtk2elements.set_cells(connectivity);
  vtk2elements.add_scalar(scalara, "MyScalar");
  vtk2elements.add_vector(electricField, "EField");
  vtk2elements.write_vtk("quad.vtk");

  return 0;
}