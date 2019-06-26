#include "NRooks.h"

NRooks::NRooks()
        : Sampler() {}

NRooks::NRooks(const int numSamples)
        : Sampler(numSamples) {

    generateSamples();
}

void NRooks::generateSamples() {

    for (int p = 0; p < numSets; p++) {
        for (int i = 0; i < numSamples; i++) {
            // Generate samples along main diagonal.
            samples.emplace_back((i + drand48()) / numSamples, (i + drand48()) / numSamples);
        }
    }
    shuffleXCoordinates();
    shuffleYCoordinates();
}
