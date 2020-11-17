#pragma once

#include "Sampler.h"

class MultiJittered : public Sampler {

public:

    MultiJittered();

    explicit MultiJittered(int numSamples);

protected:
    void generateSamples() override;

};
