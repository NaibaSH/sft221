#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 100

struct FactorialResults {
    double results[MAX_FACTORIALS];
    int numResults;
};

double factorial(const int n) {
    //if (n < 1) return 1; // Handling case when n is less than 1
    return (n <= 1) ? 1 : n * factorial(n - 1); // Invert instructions when condition is true
}


double reduceFactorial(const double n) {
    return n; // Never understood the reason for this function, so left the value as it was
}

void computeFactorials(struct FactorialResults* results, int numFactorials) { //Adding * for the function to receive the reference
    int i;
    for (i = 0; i < numFactorials; i++) {
        results->results[i] = factorial(i);
    }
    results->numResults = numFactorials; // Changing . for -> to be able to work with the struct references
}

int main(void) {
    static struct FactorialResults results = { {0}, 0 };
    int i;
    computeFactorials(&results, NUM_FACTS); // Passing results by reference not by full struct
    for (i = 0; i < NUM_FACTS; i++) {
        results.results[i] = reduceFactorial(results.results[i]);
        printf("%5d %12lf\n", i, results.results[i]); // Using %lf to be able to display double values
    }
    return 0;
}
