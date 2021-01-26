//------------------------------------------------------------------------------
//  freecamerautil.cc
//  (C) 2012-2020 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "render/stdneb.h"
#include "topdowncamerautil.h"
#include "io/console.h"

namespace RenderUtil
{
using namespace Math;

//------------------------------------------------------------------------------
/**
*/
TopdownCameraUtil::TopdownCameraUtil() :
    defaultEyePos(0, 0, 0),
    defaultPitch(-N_PI/2),
    defaultYaw(-1),
    rotationSpeed(0.01f),
    moveSpeed(0.01f),
    cameraTransform(mat4()),
    rotateButton(false),
    accelerateButton(false),
    forwardsKey(false),
    backwardsKey(false),
    leftStrafeKey(false),
    rightStrafeKey(false),
    upKey(false),
    downKey(false)

{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
void 
TopdownCameraUtil::Setup(float height, float pitch, float yaw)
{
    this->defaultEyePos = defaultEyePos;
    this->position = this->defaultEyePos;
    this->defaultPitch = pitch;
    this->defaultYaw = yaw;
    this->height = height;
    this->viewAngles.set(this->defaultYaw, this->defaultPitch);
    this->Update();
}

//------------------------------------------------------------------------------
/**
*/
void 
TopdownCameraUtil::Reset()
{
    this->viewAngles.set(this->defaultYaw, this->defaultPitch);
    this->position = this->defaultEyePos;
    this->Update();
}

//------------------------------------------------------------------------------
/**
*/
void 
TopdownCameraUtil::Update()
{
    if (this->rotateButton)
    {
        this->viewAngles.rho += this->mouseMovement.x * rotationSpeed;
        this->viewAngles.theta += this->mouseMovement.y * rotationSpeed;
    }

    if (this->viewAngles.theta >= N_PI) {
        this->viewAngles.theta = N_PI;
    }
    if (this->viewAngles.theta <= 2) {
        this->viewAngles.theta = 2;
    }

    mat4 xMat = rotationx(this->viewAngles.theta - (N_PI * 0.5f));
    mat4 yMat = rotationy(this->viewAngles.rho);
    this->cameraTransform = xMat * yMat;

    float currentMoveSpeed = moveSpeed;
    if(this->accelerateButton)
    {
        currentMoveSpeed *= 20;
    }
    vec4 translation = vec4(0,0,0,0);
    if (forwardsKey)
    {
        translation.z -= currentMoveSpeed;
    }
    if (backwardsKey)
    {
        translation.z += currentMoveSpeed;
    }
    if (rightStrafeKey)
    {
        translation.x += currentMoveSpeed;
    }
    if (leftStrafeKey)
    {
        translation.x -= currentMoveSpeed;
    }
    if (upKey)
    {
        this->height += currentMoveSpeed;
    }
    if (downKey)
    {
        this->height -= currentMoveSpeed;
    }

    translation = rotationy(-this->viewAngles.rho) * -translation;
    this->position.x += translation.x;
    this->position.z += translation.z;

    float hypo = -this->height / Math::cos(this->viewAngles.theta);

   

    IO::Console::Instance()->Print("%f", this->viewAngles.theta);
    this->cameraTransform = Math::translation(this->position.vec) * yMat * xMat * Math::translation(0, 0, -hypo);

}
} // namespace RenderUtil