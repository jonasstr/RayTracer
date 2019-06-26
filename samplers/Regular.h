#pragma once

#include "Sampler.h"

class Regular : public Sampler {

public:

    Regular();

    explicit Regular(int numSamples);

private:

    void generateSamples() override;
};
