#include <cmath>
#include "Jittered.h"

Jittered::Jittered()
        : Sampler() {}

Jittered::Jittered(const int numSamples)
        :Sampler(numSamples) {

    generateSamples();
}

void Jittered::generateSamples() {

    const int n = (int) sqrt(numSamples);

    for (int p = 0; p < numSets; p++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                // Create a sample point between [0,1) with a random offset on each axis.
                samples.emplace_back((x + drand48()) / n, (y + drand48()) / n);
            }
        }
    }
}
