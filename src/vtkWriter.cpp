#include "vtkWriter.h"
#include <vector> 
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridWriter.h>
#include <vtkTriangle.h>
#include <vtkCellArray.h>
#include <vtkDoubleArray.h> 
#include <vtkCellData.h>


void writeVTK_unstructured::init() {
  points = vtkSmartPointer<vtkPoints>::New();
  cells = vtkSmartPointer<vtkCellArray>::New();
  grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
}

void writeVTK_unstructured::set_points(std::vector<double>& coordinates) {
  points = vtkSmartPointer<vtkPoints>::New();
  for (std::size_t i = 0; i + 2 < coordinates.size(); i += 3) {
      points->InsertNextPoint(coordinates[i], coordinates[i + 1], coordinates[i + 2]);
  }
  grid->SetPoints(points);
}

void writeVTK_unstructured::set_cells(std::vector<int>& connectivity) {
  cells = vtkSmartPointer<vtkCellArray>::New();
  for(int i = 0;i<connectivity.size();i++) {
    cells->InsertNextCell(3);
    cells->InsertCellPoint(connectivity[i]); cells->InsertCellPoint(connectivity[i+1]); cells->InsertCellPoint(connectivity[i+2]);
  }    
}


void writeVTK_unstructured::add_scalar(std::vector<double>& scalar, std::string scalarName) {
  vtkSmartPointer<vtkDoubleArray> dataArray = vtkSmartPointer<vtkDoubleArray>::New();
  dataArray->SetName(scalarName.c_str());
  dataArray->SetNumberOfComponents(1);
  dataArray->SetNumberOfTuples(scalar.size());

  for (vtkIdType i = 0; i < scalar.size(); ++i) {
    dataArray->SetValue(i, scalar[i]);
  }

  grid->GetCellData()->AddArray(dataArray);
}

void writeVTK_unstructured::add_vector(std::vector<std::vector<double>>& vect, std::string vectName) {
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

void writeVTK_unstructured::write_vtk(std::string fname){
  grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
  grid->SetCells(VTK_TRIANGLE, cells);  // Use correct cell type like VTK_TRIANGLE

  return;
}