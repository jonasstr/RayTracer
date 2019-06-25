
#include "ShadeRec.h"

#include "Constants.h"

ShadeRec::ShadeRec(Scene *scene)
        : hitAnyObject(false), localHitPoint(), normal(), color(black), scene(scene) {}