#include <cmath>
#include "Regular.h"

Regular::Regular()
        : Sampler() {}

Regular::Regular(int numSamples)
        : Sampler(numSamples) {

    generateSamples();
}

void Regular::generateSamples() {

    const int n = (int) sqrt(numSamples);

    for (int p = 0; p < numSets; p++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                // Create a sample point in the center of the grid element within a pixel.
                samples.emplace_back((x + 0.5) / n, (y + 0.5) / n);
            }
        }
    }
}
