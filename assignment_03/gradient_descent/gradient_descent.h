#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include <vector>
#include <string>

using namespace std;

struct GradientResult
{
    double finalX;
    double finalValue;
    int iterations;
    bool converged;
};

double evaluatePolynomial(
    const vector<double>& coefficients,
    double x
);

double evaluateDerivative(
    const vector<double>& coefficients,
    double x
);

GradientResult gradientDescent(
    const vector<double>& coefficients,
    double initialX,
    double learningRate,
    double tolerance,
    int maxIterations
);

void runGradientDescent(const string& filename);

#endif