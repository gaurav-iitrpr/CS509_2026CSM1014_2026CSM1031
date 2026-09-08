#include "kmeans.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <limits>
#include <algorithm>

using namespace std;
using namespace chrono;

static double squaredDistance(
    const vector<double>& a,
    const vector<double>& b)
{
    double sum = 0.0;

    for (size_t i = 0; i < a.size(); i++)
    {
        double d = a[i] - b[i];
        sum += d * d;
    }

    return sum;
}

KMeansResult kMeans(
    const vector<vector<double>>& points,
    int k,
    int maxIterations,
    double tolerance)
{
    int n = (int)points.size();
    int d = (int)points[0].size();

    KMeansResult result;
    result.assignments.assign(n, -1);
    result.centroids.assign(k, vector<double>(d, 0.0));
    result.wcss = 0.0;
    result.iterations = 0;
    result.converged = false;

    for (int c = 0; c < k; c++)
    {
        result.centroids[c] = points[c];
    }

    vector<int> oldAssignments(n, -1);

    for (int iteration = 1; iteration <= maxIterations; iteration++)
    {
        for (int i = 0; i < n; i++)
        {
            double bestDistance = numeric_limits<double>::max();
            int bestCluster = 0;

            for (int c = 0; c < k; c++)
            {
                double distance = squaredDistance(points[i], result.centroids[c]);

                if (distance < bestDistance)
                {
                    bestDistance = distance;
                    bestCluster = c;
                }
            }

            result.assignments[i] = bestCluster;
        }

        vector<vector<double>> sums(k, vector<double>(d, 0.0));
        vector<int> counts(k, 0);

        for (int i = 0; i < n; i++)
        {
            int c = result.assignments[i];
            counts[c]++;

            for (int j = 0; j < d; j++)
            {
                sums[c][j] += points[i][j];
            }
        }

        double maxShift = 0.0;

        for (int c = 0; c < k; c++)
        {
            if (counts[c] == 0)
            {
                continue;
            }

            vector<double> newCentroid(d);

            for (int j = 0; j < d; j++)
            {
                newCentroid[j] = sums[c][j] / counts[c];
            }

            double shift = sqrt(squaredDistance(
                result.centroids[c],
                newCentroid
            ));

            maxShift = max(maxShift, shift);
            result.centroids[c] = newCentroid;
        }

        result.iterations = iteration;

        bool sameAssignments = true;

        for (int i = 0; i < n; i++)
        {
            if (oldAssignments[i] != result.assignments[i])
            {
                sameAssignments = false;
                break;
            }
        }

        oldAssignments = result.assignments;

        if (sameAssignments || maxShift <= tolerance)
        {
            result.converged = true;
            break;
        }
    }

    result.wcss = 0.0;

    for (int i = 0; i < n; i++)
    {
        result.wcss += squaredDistance(
            points[i],
            result.centroids[result.assignments[i]]
        );
    }

    return result;
}

void runKMeans(const string& filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Error: Unable to open input file." << endl;
        return;
    }

    int n, d, k;
    fin >> n >> d >> k;

    if (!fin || n <= 0 || d <= 0 || k <= 0 || k > n)
    {
        cout << "Error: Invalid K-Means input." << endl;
        return;
    }

    vector<vector<double>> points(n, vector<double>(d));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            fin >> points[i][j];
        }
    }

    string label;
    int maxIterations;
    double tolerance;

    fin >> label >> maxIterations;
    fin >> label >> tolerance;

    if (!fin || maxIterations <= 0 || tolerance <= 0.0)
    {
        cout << "Error: Invalid K-Means parameters." << endl;
        return;
    }

    auto start = high_resolution_clock::now();

    KMeansResult result = kMeans(
        points,
        k,
        maxIterations,
        tolerance
    );

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n=====================================\n";
    cout << "          K-MEANS CLUSTERING\n";
    cout << "=====================================\n";
    cout << "Input File : " << filename << endl;
    cout << "K : " << k << endl;

    cout << "\nPoint assignments:\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << result.assignments[i] << endl;
    }

    cout << "\nFinal centroids:\n";

    for (int c = 0; c < k; c++)
    {
        cout << c << ":";

        for (int j = 0; j < d; j++)
        {
            cout << " " << result.centroids[c][j];
        }

        cout << endl;
    }

    cout << "WCSS: " << result.wcss << endl;
    cout << "Iterations: " << result.iterations << endl;
    cout << "Converged: " << (result.converged ? "true" : "false") << endl;
    cout << "Execution time: " << duration.count() / 1000.0 << " ms" << endl;
}
