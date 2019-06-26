#pragma once

#include "Sampler.h"

class Jittered : public Sampler {

public:

    Jittered();

    explicit Jittered(int numSamples);

private:

    void generateSamples() override;
};
