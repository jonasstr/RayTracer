#pragma once

#include <vector>
#include <random>

#include "Vec2.h"
#include "Vec3.h"

class Sampler {

public:

    Sampler();

    explicit Sampler(int numSamples);

    virtual ~Sampler() = default;

    virtual Vec2 nextSquareSample() final;

    virtual Vec2 nextDiskSample() final;

    virtual void mapSamplesToUnitDisk() final;

    virtual void mapSamplesToHemisphere(float e) final;

    inline int getNumSamples() { return numSamples; }

protected:

    int numSamples; // The number of sample points in a pattern.
    int numSets; // The number of patterns stored.
    std::vector<Vec2> samples; // Sample points on a unit square.
    std::vector<Vec2> diskSamples; // Sample points on a unit disk.
    std::vector<Vec3> hemisphereSamples; // Sample points on a hemisphere.
    std::vector<int> shuffledIndices; // Shuffled sample indices.
    unsigned long count; // The current number of sample points used.
    int jump; // Random index jump.

    /**
    * Generates sample patterns in a unit square.
    */
    virtual void generateSamples() = 0;

    void setupShuffledIndices();

    void shuffleYCoordinates();

    void shuffleXCoordinates();

    virtual int randInt(int max) final;

    virtual int randInt(int min, int max) final;

private:

    std::mt19937 mt;

};
