#include "Random.h"

Random::Random()
        : Sampler() {}

Random::Random(int numSamples)
        : Sampler(numSamples) {

    generateSamples();
}

void Random::generateSamples() {

    const int n = (int) sqrt(numSamples);

    for (int p = 0; p < numSets; p++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                // Create a random sample point.
                samples.emplace_back(drand48(), drand48());
            }
        }
    }
}
