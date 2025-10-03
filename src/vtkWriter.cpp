/*
Simple use Cases.


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


*/




#include <vtkWriter.h>
#include <vector> 
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridWriter.h>
#include <vtkTriangle.h>
#include <vtkCellArray.h>
#include <vtkDoubleArray.h> 
#include <vtkCellData.h>
#include <iostream>


VTKUnstructuredWriter::~VTKUnstructuredWriter() = default;


void VTKUnstructuredWriter::init() {

  points = vtkSmartPointer<vtkPoints>::New();
  cells = vtkSmartPointer<vtkCellArray>::New();
  grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
}

void VTKUnstructuredWriter::set_points(std::vector<double>& coordinates) {
  points = vtkSmartPointer<vtkPoints>::New();
  for (std::size_t i = 0; i + 2 < coordinates.size(); i += 3) {
      points->InsertNextPoint(coordinates[i], coordinates[i + 1], coordinates[i + 2]);
  }
  grid->SetPoints(points);
}

void VTKUnstructuredWriter::set_cells(std::vector<int>& connectivity) {
  std::cout<<"No defualt definition.\n";
}

void VTKUnstructuredWriter::add_scalar(std::vector<double>& scalar, std::string scalarName) {
  vtkSmartPointer<vtkDoubleArray> dataArray = vtkSmartPointer<vtkDoubleArray>::New();
  dataArray->SetName(scalarName.c_str());
  dataArray->SetNumberOfComponents(1);
  dataArray->SetNumberOfTuples(scalar.size());

  for (vtkIdType i = 0; i < scalar.size(); ++i) {
    dataArray->SetValue(i, scalar[i]);
  }

  grid->GetCellData()->AddArray(dataArray);
}

void VTKUnstructuredWriter::add_vector(std::vector<std::vector<double>>& vect, std::string vectName) {
  if (vect[0].size() != 3) {
    throw std::runtime_error("Each vector must have exactly 3 components.");
  }

  vtkSmartPointer<vtkDoubleArray> vectorArray = vtkSmartPointer<vtkDoubleArray>::New();
  vectorArray->SetName(vectName.c_str());
  vectorArray->SetNumberOfComponents(3);
  vtkIdType numTuples = vect.size();
  vectorArray->SetNumberOfTuples(numTuples);

  for (vtkIdType i = 0; i < numTuples; ++i) {
    vectorArray->SetTuple3(i, vect[i][0], vect[i][1], vect[i][2]);
  }

  grid->GetCellData()->AddArray(vectorArray);
}

void VTKUnstructuredWriter::write_vtk(std::string fname){
  vtkSmartPointer<vtkUnstructuredGridWriter> writer = vtkSmartPointer<vtkUnstructuredGridWriter>::New();
  writer->SetFileName(fname.c_str());
  writer->SetInputData(grid);
  writer->Write();
  return;
}

/**********For Triangle Files**********/
void VTKTriangleWriter::set_cells(std::vector<int>& connectivity) {
  cells = vtkSmartPointer<vtkCellArray>::New();
  for(int i = 0;i+2<connectivity.size();i+=3) {
    cells->InsertNextCell(3);
    cells->InsertCellPoint(connectivity[i]); cells->InsertCellPoint(connectivity[i+1]); cells->InsertCellPoint(connectivity[i+2]);
  }
  grid->SetCells(VTK_TRIANGLE, cells);    
}

/**********For Quad Files**********/
void VTKQuadWriter::set_cells(std::vector<int>& connectivity) {
  for (int i = 0; i + 3 < connectivity.size(); i += 4) {
  cells->InsertNextCell(4);
  cells->InsertCellPoint(connectivity[i]);
  cells->InsertCellPoint(connectivity[i+1]);
  cells->InsertCellPoint(connectivity[i+2]);
  cells->InsertCellPoint(connectivity[i+3]);
}
grid->SetCells(VTK_QUAD, cells);
  
}



/************For Oct Files ************/
// void VTKOctWriter::set_connectivity(std::vector<int>& connectivity, int n0, int n1, int n2, int n3,
//                                     int n4, int n5, int n6, int n7) {
//   connectivity.push_back(n0); // bottom-left-front
//   connectivity.push_back(n1); // bottom-right-front
//   connectivity.push_back(n2); // bottom-right-back
//   connectivity.push_back(n3); // bottom-left-back
//   connectivity.push_back(n4); // top-left-front
//   connectivity.push_back(n5); // top-right-front
//   connectivity.push_back(n6); // top-right-back
//   connectivity.push_back(n7); // top-left-back
// }

void VTKOctWriter::set_cells(std::vector<int>& connectivity) {
  for (int i = 0; i + 7 < connectivity.size(); i += 8) {
    cells->InsertNextCell(8);          // 8 nodes for a hexahedron
    cells->InsertCellPoint(connectivity[i]);   // n0
    cells->InsertCellPoint(connectivity[i+1]); // n1
    cells->InsertCellPoint(connectivity[i+2]); // n2
    cells->InsertCellPoint(connectivity[i+3]); // n3
    cells->InsertCellPoint(connectivity[i+4]); // n4
    cells->InsertCellPoint(connectivity[i+5]); // n5
    cells->InsertCellPoint(connectivity[i+6]); // n6
    cells->InsertCellPoint(connectivity[i+7]); // n7
  }
  grid->SetCells(VTK_HEXAHEDRON, cells);
}
