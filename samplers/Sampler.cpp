#include <random>

#include <cstdlib>
#include <random>
#include <algorithm>

#include "Sampler.h"

Sampler::Sampler()
        : numSamples(1),
          numSets(83),
          count(0),
          jump(0),
          mt(std::random_device()()) {

    samples.reserve(numSets * numSamples);
    setupShuffledIndices();
}

Sampler::Sampler(const int numSamples)
        : numSamples(numSamples),
          numSets(83),
          count(0),
          jump(0),
          mt(std::random_device()()) {

    samples.reserve(numSets * numSamples);
    setupShuffledIndices();
}

Vec2 Sampler::nextSample() {

    if (count % numSamples == 0) { // Start of a new pixel
        jump = (randInt(numSets)) * numSamples;
    }
    return samples[jump + shuffledIndices[jump + count++ % numSamples]];
}

int Sampler::randInt(const int max) {
    std::uniform_int_distribution<int> dist(0, max);
    return dist(mt);
}

void Sampler::shuffleXCoordinates() {

    for (int p = 0; p < numSets; p++) {
        for (int i = 0; i < numSamples - 1; i++) {

            const int targetPosition = randInt(numSamples) + p * numSamples;
            // Transform 2D (p|i) position to 1D array index.
            float temp = samples[i + p * numSamples + 1].x;
            // Swap target with current position.
            samples[i + p * numSamples + 1].x = samples[targetPosition].x;
            samples[targetPosition].x = temp;
        }
    }
}

void Sampler::shuffleYCoordinates() {

    for (int p = 0; p < numSets; p++) {
        for (int i = 0; i < numSamples - 1; i++) {

            const int targetPosition = randInt(numSamples) + p * numSamples;
            // Transform 2D (p|i) position to 1D array index.
            float temp = samples[i + p * numSamples + 1].y;
            // Swap target with current position.
            samples[i + p * numSamples + 1].y = samples[targetPosition].y;
            samples[targetPosition].y = temp;
        }
    }
}

void Sampler::setupShuffledIndices() {

    shuffledIndices.reserve(numSets * numSamples);
    std::vector<int> indices;
    indices.reserve(numSamples);

    for (int i = 0; i < numSamples; i++) {
        // Create an array of indices.
        indices.push_back(i);
    }
    for (int p = 0; p < numSets; p++) {
        shuffle(indices.begin(), indices.end(), mt);
        for (int i = 0; i < numSamples; i++) {
            shuffledIndices.push_back(indices[i]);
        }
    }
}
