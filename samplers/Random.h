
#include "Sampler.h"

class Random : public Sampler {

public:

    Random();

    explicit Random(int numSamples);

protected:

    void generateSamples() override;
};
