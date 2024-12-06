#include <iostream>
#include <math.h>
#include <string.h>

void Print_Menu();

void PrintOperatorsMenu();

void PrintSaveResultMenu();

void PrintWhereSaveResultMenu();

int get_variant(int count);

void WorkWithMatrix(Matrix* matrix_);

void WorkWithOperators(Matrix* matrix_);

void WorkWithSaving(Matrix* matrix_, Matrix& matrixSave_);

void WorkWhereSaving(Matrix* matrix_, Matrix& matrixSave_);

void YesNo(bool res_);

void PrintMenuSquare();

void WorkWithSquareMatrix(SquareMatrix* matrix_);

void WorkWithOperatorsOfSquareMatrix(SquareMatrix* matrix_);

void PrintOperatorsMenuForSquareMatrix();

void WorkWithSavingForSquare(SquareMatrix* matrix_, SquareMatrix& matrixSave_);

void WorkWhereSavingForSquare(SquareMatrix* matrix_, SquareMatrix& matrixSave_);