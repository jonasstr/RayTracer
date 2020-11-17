#include "MultiJittered.h"


MultiJittered::MultiJittered()
        : Sampler() {}

MultiJittered::MultiJittered(int numSamples)
        : Sampler(numSamples) {
    generateSamples();
}

void MultiJittered::generateSamples() {

    const int n = (int) sqrt(numSamples);
    const float subCellWidth = 1.0 / numSamples;

    Vec2 dummyPoint{};
    // Create dummy points to enable access via [].
    for (int i = 0; i < numSets * numSamples; i++) {
        samples.push_back(dummyPoint);
    }

    for (int p = 0; p < numSets; p++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                // Add random offset within cell.
                samples[n * x + y + p * numSamples].x =
                        (n * x + y) * subCellWidth + (drand48() * subCellWidth);
                samples[n * x + y + p * numSamples].y =
                        (n * y + x) * subCellWidth + (drand48() * subCellWidth);
            }
        }
    }

    // Shuffle x coordinates
    for (int p = 0; p < numSets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int k = randInt(j, n - 1);
                float t = samples[i * n + j + p * numSamples].x;
                samples[i * n + j + p * numSamples].x = samples[i * n + k + p * numSamples].x;
                samples[i * n + k + p * numSamples].x = t;
            }

    // Shuffle y coordinates
    for (int p = 0; p < numSets; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int k = randInt(j, n - 1);
                float t = samples[j * n + i + p * numSamples].y;
                samples[j * n + i + p * numSamples].y = samples[k * n + i + p * numSamples].y;
                samples[k * n + i + p * numSamples].y = t;
            }
        }
    }
}
