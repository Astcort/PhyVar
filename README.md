# PhyVar

## Author(s)

* Mickaël Ly - ELAN team - Inria Grenoble Rhône-Alpes

## Short description
*PhyVar* is a short library using templates to manipulate physical variables *ie* to keep trace of the SI units affected to each variable.

A short support for compatibility with Eigen is also provided.

## How to use 

Just include all the following files of the the `include/Core` directory of this project to yours :
* `PhyVar.hpp`
* `PhyVar.tpp`
* `PhyVar.impl.pp`
* `Unit.tpp`

For the Eigen support, also include the content of `include/Eigen` :
* `PhyVarEigen.hpp`

## Getting started 

Take a look at the example in the `src` directory. To compile it :
```
mkdir build
cd build
cmake ..
make
```
## Todo 

* Implement units multiplier (kilo, milli, ...)
