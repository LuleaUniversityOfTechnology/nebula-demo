//------------------------------------------------------------------------------
//  freecamerautil.cc
//  (C) 2012-2020 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "render/stdneb.h"
#include "topdowncamerautil.h"

namespace RenderUtil
{
using namespace Math;

//------------------------------------------------------------------------------
/**
*/
TopdownCameraUtil::TopdownCameraUtil() : 
    defaultEyePos(0,0,0),
    defaultEyeVec(0,0,1),
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
TopdownCameraUtil::Setup( const Math::point& defaultEyePos, const Math::vector& defaultEyeVec )
{
    this->defaultEyePos = defaultEyePos;
    this->defaultEyeVec = defaultEyeVec;
    this->position = this->defaultEyePos;
    this->viewAngles.set(this->defaultEyeVec);
    this->Update();
}

//------------------------------------------------------------------------------
/**
*/
void 
TopdownCameraUtil::Reset()
{
    this->viewAngles.set(this->defaultEyeVec);
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
    }

    mat4 xMat = rotationx(-(N_PI/2));
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
        translation.y += currentMoveSpeed;
    }
    if (backwardsKey)
    {
        translation.y -= currentMoveSpeed;
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
        translation.z += currentMoveSpeed;
    }
    if (downKey)
    {
        translation.z -= currentMoveSpeed;
    }

    translation = this->cameraTransform * translation;
    this->position += xyz(translation);

    this->cameraTransform.position = point(this->position);
}


} // namespace RenderUtil