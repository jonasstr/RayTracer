#pragma once

#include "Sampler.h"

class NRooks : public Sampler {

public:

    NRooks();

    explicit NRooks(int numSamples);

private:

    void generateSamples() override;
};
