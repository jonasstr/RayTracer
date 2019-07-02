#include "Camera.h"

Camera::Camera()
        : eye(0, 0, 500),
          lookAt(0),
          up(0, 1, 0),
          u(1, 0, 0),
          v(0, 1, 0),
          w(0, 0, 1),
          exposureTime(1) {

    computeUVW();
}

void Camera::computeUVW() {

    w = (eye - lookAt).normalize();
    u = (up ^ w).normalize();
    v = (w ^ u);
}
