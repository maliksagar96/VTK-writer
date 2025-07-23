# 📝 VTK Writer Library

A lightweight C++ library for writing `.vtk` files (ASCII format) for **all-triangle** and **all-quad** mesh types using [VTK](https://vtk.org/).  
This tool enables easy export of geometry and simulation data, ideal for scientific visualization in **electromagnetics**, **CFD**, and **FEM** workflows.

---

## 📦 Features

- ✅ Write `.vtk` files in **UnstructuredGrid** format
- ✅ Support for:
  - Point coordinates (`set_points`)
  - Cell connectivity for triangle/quad meshes (`set_cells`)
  - Scalar fields (e.g., pressure, temperature) (`add_scalar`)
  - Vector fields (e.g., velocity, E-field) (`add_vector`)
- ✅ Object-oriented design using modern C++ (RAII, smart pointers)
- ✅ Extensible via base class `VTKUnstructuredWriter`

---

## 🔧 Writers Available

- `VTKTriangleWriter` — writes triangle-only meshes  
- `VTKQuadWriter` — writes quad-only meshes

---

## 📁 What's Inside?

### 🔹 `vtkWriter.h` / `vtkWriter.cpp`

- Provides a base class `VTKUnstructuredWriter` for writing `.vtk` files in UnstructuredGrid format
- Derived classes:
  - `VTKTriangleWriter` – handles triangle-only meshes
  - `VTKQuadWriter` – handles quad-only meshes
- Key functions:
  - `set_points()` – Set mesh point coordinates
  - `set_cells()` – Set cell connectivity (tri/quad)
  - `add_scalar()` – Add scalar fields (e.g., pressure, temperature)
  - `add_vector()` – Add vector fields (e.g., velocity, electric field)
  - `write_vtk()` – Write everything to a `.vtk` file

### 🔹 `main.cpp`

- A sample test program demonstrating usage of the writer classes

---

## 🧱 Project Structure

VTK-writer/  
├── include/  
│└── vtkWriter.h  
├── src/  
│├── main.cpp  
│└── vtkWriter.cpp  
├── CMakeLists.txt  
└── README.md

---

## ⚙️ Dependencies

- [VTK](https://vtk.org/) (tested with 9.x)
- CMake ≥ 3.10
- C++11 or later

### ✅ Install VTK (Ubuntu)

```bash
sudo apt update
sudo apt install libvtk9-dev

# Clone this repository
git clone https://github.com/maliksagar96/VTK-writer.git
cd VTK-writer

# Create build directory
mkdir build && cd build

# Run CMake
cmake ..

# Build the project
make



🧪 Sample Usage

Here’s a sample program to demonstrate reading a .vtk PolyData file:

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
```
