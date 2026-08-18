#include "gradient_descent.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;
using namespace chrono;


double evaluatePolynomial(
    const vector<double>& coefficients,
    double x)
{
    if (coefficients.empty())
    {
        return 0.0;
    }

    double result = coefficients.back();

    for (int i = (int)coefficients.size() - 2; i >= 0; i--)
    {
        result = result * x + coefficients[i];
    }

    return result;
}


double evaluateDerivative(
    const vector<double>& coefficients,
    double x)
{
    int degree = (int)coefficients.size() - 1;

    if (degree <= 0)
    {
        return 0.0;
    }

    double result = degree * coefficients[degree];

    for (int i = degree - 1; i >= 1; i--)
    {
        result = result * x + i * coefficients[i];
    }

    return result;
}


GradientResult gradientDescent(
    const vector<double>& coefficients,
    double initialX,
    double learningRate,
    double tolerance,
    int maxIterations)
{
    double x = initialX;

    int iterations = 0;
    bool converged = false;

    while (iterations < maxIterations)
    {
        double derivative =
            evaluateDerivative(coefficients, x);

        if (fabs(derivative) <= tolerance)
        {
            converged = true;
            break;
        }

        x = x - learningRate * derivative;

        iterations++;
    }

    if (!converged)
    {
        double derivative =
            evaluateDerivative(coefficients, x);

        if (fabs(derivative) <= tolerance)
        {
            converged = true;
        }
    }

    GradientResult result;

    result.finalX = x;
    result.finalValue =
        evaluatePolynomial(coefficients, x);

    result.iterations = iterations;
    result.converged = converged;

    return result;
}


void runGradientDescent(const string& filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Error: Unable to open file "
             << filename << endl;

        return;
    }

    string label;

    int degree;

    vector<double> coefficients;

    double initialX;
    double learningRate;
    double tolerance;

    int maxIterations;


    
    fin >> label >> degree;

    if (degree < 1)
    {
        cout << "Error: Invalid degree." << endl;
        return;
    }


    fin >> label;

    coefficients.resize(degree + 1);

    for (int i = 0; i <= degree; i++)
    {
        fin >> coefficients[i];
    }


  
    fin >> label >> initialX;


    fin >> label >> learningRate;


    fin >> label >> tolerance;


    fin >> label >> maxIterations;


    if (learningRate <= 0)
    {
        cout << "Error: Learning rate must be positive."
             << endl;

        return;
    }

    if (tolerance <= 0)
    {
        cout << "Error: Tolerance must be positive."
             << endl;

        return;
    }

    if (maxIterations <= 0)
    {
        cout << "Error: MAX_ITERATIONS must be positive."
             << endl;

        return;
    }

    fin.close();


    auto start =
        high_resolution_clock::now();


    GradientResult result =
        gradientDescent(
            coefficients,
            initialX,
            learningRate,
            tolerance,
            maxIterations
        );


    auto stop =
        high_resolution_clock::now();


    auto duration =
        duration_cast<microseconds>(
            stop - start
        );


    cout << "\n=====================================\n";
    cout << "          GRADIENT DESCENT\n";
    cout << "=====================================\n";

    cout << "Input File : "
         << filename << endl;

    cout << "Degree : "
         << degree << endl;

    cout << fixed << setprecision(10);

    cout << "Final x : "
         << result.finalX << endl;

    cout << "Final f(x) : "
         << result.finalValue << endl;

    cout << "Iterations : "
         << result.iterations << endl;

    cout << "Converged : "
         << (result.converged ? "true" : "false")
         << endl;

    cout << "Execution Time : "
         << duration.count()
         << " microseconds"
         << endl;
}