/* 

*/

#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

#include <SFML/Graphics.hpp>

using namespace std;

class Matrix
{
	public:
		//CONSTRUCTORS
		Matrix();
		Matrix(int input_width, int input_height);
		~Matrix();
		//OPERATORS
		Matrix operator+(const Matrix&) const;
		Matrix operator-(const Matrix&) const;
		Matrix operator*(const Matrix&) const;
		Matrix operator/(const Matrix&) const;
		void operator=(const Matrix&);
		//PUBLIC FUNCTIONS
		void init(int input_width, int input_height);
		void init(int input);
		void randomize();
		void mutate();
		void randomize_greyscale();
		void mutate_greyscale();
		string to_string();
		int width;
		int height;
		int **matrix;
};

//EXTERNAL FUNCTIONS
double frobenius(Matrix &A);
vector<Matrix> NMFactorize(Matrix &A, int k, int factor);
Matrix NMMultiply(Matrix &X, Matrix &Y);
Matrix mutate(Matrix &A);

#endif
