#include <random>

#include <cstdlib>
#include <random>
#include <algorithm>
#include <Constants.h>

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

Vec2 Sampler::nextSquareSample() {

    if (count % numSamples == 0) { // Start of a new pixel
        jump = randInt(numSets) * numSamples;
    }
    return samples[jump + shuffledIndices[jump + count++ % numSamples]];
}

Vec2 Sampler::nextDiskSample() {

    if (count % numSamples == 0) { // Start of a new pixel
        jump = (randInt(numSets)) * numSamples;
    }
    return diskSamples[jump + shuffledIndices[jump + count++ % numSamples]];
}

void Sampler::mapSamplesToUnitDisk() {

    const int size = samples.size();
    float r, phi; // Polar coordinates
    float x, y; // Sample point coordinates

    diskSamples.reserve(size);

    for (int i = 0; i < size; i++) {

        // Map sample point from [0,1] to [-1,1]
        x = 2.0 * samples[i].x - 1.0;
        y = 2.0 * samples[i].y - 1.0;

        if (x > -y) {
            if (x > y) { // Sector 1
                r = x;
                phi = y / x;
            } else { // Sector 2
                r = y;
                phi = 2 - x / y;
            }
        } else {
            if (x < y) { // Sector 3
                r = -x;
                phi = 4 + y / x;
            } else { // Sector 4
                r = -y;
                phi = y != 0 ? 6 - x / y : 0; // Avoid division by zero at origin
            }
        }
        phi *= QUARTER_PI;
        diskSamples[i].x = r * cos(phi);
        diskSamples[i].y = r * sin(phi);
    }
}

void Sampler::mapSamplesToHemisphere(const float e) {

    const int size = samples.size();
    hemisphereSamples.reserve(numSets * numSamples);

    for (int i = 0; i < size; i++) {
        float cosPhi = cos(TWO_PI * samples[i].x);
        float sinPhi = sin(TWO_PI * samples[i].x);
        float cosTheta = pow((1.0 - samples[i].y), 1.0 / (e + 1.0));
        float sinTheta = sqrt(1.0 - cosTheta * cosTheta); // Since sin²(a)+cos²(a) = 1
        float pU = sinTheta * cosPhi;
        float pV = sinTheta * sinPhi;
        float pW = cosTheta;
        hemisphereSamples.emplace_back(pU, pV, pW);
    }
}

int Sampler::randInt(const int max) {
    std::uniform_int_distribution<int> dist(0, max - 1);
    return dist(mt);
}

void Sampler::shuffleXCoordinates() {

    for (int p = 0; p < numSets; p++) {
        for (int i = 0; i < numSamples - 1; i++) {

            const int targetPosition = randInt(numSamples) + p * numSamples;
            // Transform 2D (p|i) position to 1D array index
            float temp = samples[i + p * numSamples + 1].x;
            // Swap target with current position
            samples[i + p * numSamples + 1].x = samples[targetPosition].x;
            samples[targetPosition].x = temp;
        }
    }
}

void Sampler::shuffleYCoordinates() {

    for (int p = 0; p < numSets; p++) {
        for (int i = 0; i < numSamples - 1; i++) {

            const int targetPosition = randInt(numSamples) + p * numSamples;
            // Transform 2D (p|i) position to 1D array index
            float temp = samples[i + p * numSamples + 1].y;
            // Swap target with current position
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
        // Create an array of indices
        indices.push_back(i);
    }
    for (int p = 0; p < numSets; p++) {
        shuffle(indices.begin(), indices.end(), mt);
        for (int i = 0; i < numSamples; i++) {
            shuffledIndices.push_back(indices[i]);
        }
    }
}
