/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   main.cpp

Project:

   Perceptron Example
   
Abstract:

------
   AUTHOR: HyunJun Jeong  2015-02-09

***************************************************************************/

#include <iostream>
#include <random>
#include <vector>
#include <cmath>

using namespace std;

class perceptron {

	double *weight_vector;
	size_t weight_vector_size;
	const double learning_constant;
	double threshold;

public:

	perceptron(size_t weight_vector_size, double learning_constant) : 
		weight_vector_size(weight_vector_size), 
		learning_constant(learning_constant)
	{
		random_device rd;
		mt19937_64 rnd(rd());
		uniform_real_distribution<> dist( -1.0f, 1.0f );

		weight_vector = new double[weight_vector_size];

		// 초기화
		for (int i = 0; i < weight_vector_size; i++)
			weight_vector[i] = dist(rnd);

		// w0초기화
		threshold = dist(rnd);
	}

	double feedforward(const double inputs[])
	{
		double feedforward_sum = 0.0f;
		for (int i = 0; i < weight_vector_size; i++)
			feedforward_sum += inputs[i] * weight_vector[i];
		return activation_function(feedforward_sum);
	}
	
	//
	//	Single-Layer Perceptron
	//
	void train(const double inputs[], double predict)
	{
		double feedforward_value = feedforward(inputs);

		if (feedforward_value != predict) {
			double error_bound = predict - feedforward_value;
			for (int i = 0; i < weight_vector_size; i++)
				weight_vector[i] += inputs[i] * learning_constant * error_bound;
			threshold -= learning_constant * error_bound;
		}
	}

	double activation_function(double value) 
	{
		return value >= threshold;
	}
};

class two_perceptron {

	// [3][3]
	// [0]: predict layer
	// [1]: hidden-layer1
	// [2]: hidden-layer2
	double **weight_vector;
	size_t weight_vector_size;
	const double learning_constant;

	// hidden layer 복사층
	double *w1, *w2;

public:

	two_perceptron(double learning_constant) : 
		weight_vector_size(3),
		learning_constant(learning_constant)
	{
		random_device rd;
		mt19937_64 rnd(rd());
		uniform_real_distribution<> dist( 0.0f, 1.0f );

		weight_vector = new double*[weight_vector_size];
		w1 = new double[weight_vector_size];
		w2 = new double[weight_vector_size];

		// 초기화
		for (int i = 0; i < weight_vector_size; i++) {
			weight_vector[i] = new double[3];
			for(int j = 0; j < 3; j++) {
				weight_vector[i][j] = dist(rnd);
			}
		}
	}
	
	double sigmoid_function(double t)
	{
		return 1 / ( 1 + ::exp( -t ) );
	}

	//
	//	Two-Layer Perceptron
	//
	double feedforward(const double inputs[])
	{
		// bias 설정
		w1[0] = w2[0] = 1;

		w1[1] = inputs[0];
		w1[2] = inputs[1];

		// hidden-layer summary
		auto get_sigmoidw1 = [&](int num) -> double {
			double sum = 0.f;
			for (int i = 0; i < 3; i++)
				sum += w1[i] * weight_vector[num][i];
			return sigmoid_function(sum);
		};

		w2[1] = get_sigmoidw1(1);
		w2[2] = get_sigmoidw1(2);

		double sum = 0.f;
		for (int i = 0; i < 3; i++)
			sum += w2[i] * weight_vector[0][i];
		sum = sigmoid_function(sum);
		return sum;
	}

	void train(const double inputs[], double predict)
	{
		double z = feedforward(inputs);

		double z1 = z*(1-z)*(predict-z);
		double z2 = w2[1]*(1-w2[1])*weight_vector[0][1]*z1;
		double z3 = w2[2]*(1-w2[2])*weight_vector[0][2]*z1;

		auto sum_to_weight = [&](int num, double arr[], double z) {
			for (int i = 0; i < 3; i++)
				weight_vector[num][i] += arr[i] * z * learning_constant;
		};

		sum_to_weight(0, w2, z1);
		sum_to_weight(1, w1, z2);
		sum_to_weight(2, w1, z3);
	}

};

int main()
{
	//
	//	선형 분리 테스트 ( SLP )
	//
	perceptron pAnd(2, 0.5f);
	perceptron  pOr(2, 0.5f);
	
	//
	//	비선형 분리 테스트 ( MLP-TWO )
	//
	two_perceptron mpXor(0.5f);

	// 포인트
	const double _zz[] = {0, 0};
	const double _zo[] = {0, 1};
	const double _oz[] = {1, 0};
	const double _oo[] = {1, 1};

	cout << "------------Before----------" << endl;

	// train전
	cout << "and" << endl;
	cout << pAnd.feedforward(_zz) << endl;
	cout << pAnd.feedforward(_zo) << endl;
	cout << pAnd.feedforward(_oz) << endl;
	cout << pAnd.feedforward(_oo) << endl << endl;
	
	cout << "or" << endl;
	cout << pOr.feedforward(_zz) << endl;
	cout << pOr.feedforward(_zo) << endl;
	cout << pOr.feedforward(_oz) << endl;
	cout << pOr.feedforward(_oo) << endl << endl;
	
	cout << "xor" << endl;
	cout << (mpXor.feedforward(_zz) >= 0.5f) << endl;
	cout << (mpXor.feedforward(_zo) >= 0.5f) << endl;
	cout << (mpXor.feedforward(_oz) >= 0.5f) << endl;
	cout << (mpXor.feedforward(_oo) >= 0.5f) << endl << endl;

	for(int i = 0; i < 16; i++) {
		pAnd.train(_zz, 0);
		pAnd.train(_zo, 0);
		pAnd.train(_oz, 0);
		pAnd.train(_oo, 1);

		pOr.train(_zz, 0);
		pOr.train(_zo, 1);
		pOr.train(_oz, 1);
		pOr.train(_oo, 1);
	}

	for(int i = 0; i < 2500; i++) {
		mpXor.train(_zz, 0);
		mpXor.train(_zo, 1);
		mpXor.train(_oz, 1);
		mpXor.train(_oo, 0);
	}

	cout << "------------After----------" << endl;

	// train후
	cout << "and" << endl;
	cout << pAnd.feedforward(_zz) << endl;
	cout << pAnd.feedforward(_zo) << endl;
	cout << pAnd.feedforward(_oz) << endl;
	cout << pAnd.feedforward(_oo) << endl << endl;
	
	cout << "or" << endl;
	cout << pOr.feedforward(_zz) << endl;
	cout << pOr.feedforward(_zo) << endl;
	cout << pOr.feedforward(_oz) << endl;
	cout << pOr.feedforward(_oo) << endl << endl;

	cout << "xor" << endl;
	cout << (mpXor.feedforward(_zz) >= 0.5f) << endl;
	cout << (mpXor.feedforward(_zo) >= 0.5f) << endl;
	cout << (mpXor.feedforward(_oz) >= 0.5f) << endl;
	cout << (mpXor.feedforward(_oo) >= 0.5f) << endl << endl;

	return 0;
}