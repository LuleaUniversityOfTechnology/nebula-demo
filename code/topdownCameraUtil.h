#pragma once
//------------------------------------------------------------------------------
/**
    @class RenderUtil::TopdownCameraUtil

    Implements a free camera

    @copyright
    (C) 2012-2020 Individual contributors, see AUTHORS file
*/
#include "math/mat4.h"
#include "math/vec2.h"
#include "math/polar.h"
#include "math/scalar.h"

//------------------------------------------------------------------------------
namespace RenderUtil
{
    class TopdownCameraUtil
    {
    public:
        /// constructor
        TopdownCameraUtil();

        /// sets up free camera
        void Setup(float height, float defaultPitch, float defaultYaw);
        /// resets free camera to default values
        void Reset();
        /// updates camera matrix
        void Update();
        /// gets camera transform
        const Math::mat4& GetTransform() const;

        /// sets the state of the rotate button
        void SetRotateButton(bool state);
        /// sets the state of the accelerate button
        void SetAccelerateButton(bool state);
        /// sets the mouse movement
        void SetMouseMovement(Math::vec2 movement);
        /// sets the rotation speed
        void SetRotationSpeed(float speed);
        /// sets the movement speed
        void SetMovementSpeed(float speed);

        /// sets the forward movement key
        void SetForwardsKey(bool state);
        /// sets the backward movement key
        void SetBackwardsKey(bool state);
        /// sets the left strafe key
        void SetLeftStrafeKey(bool state);
        /// sets the right strafe key
        void SetRightStrafeKey(bool state);
        /// sets the up movement key
        void SetUpKey(bool state);
        /// sets the down movement key
        void SetDownKey(bool state);

    private:
        Math::point defaultEyePos;
        float defaultPitch;
        float defaultYaw;
        float height;
        Math::vec2 mouseMovement;

        Math::polar viewAngles;
        Math::point position;
        Math::mat4 cameraTransform;

        float rotationSpeed;
        float moveSpeed;

        bool rotateButton;
        bool accelerateButton;

        bool forwardsKey;
        bool backwardsKey;
        bool leftStrafeKey;
        bool rightStrafeKey;
        bool upKey;
        bool downKey;
    };


    //------------------------------------------------------------------------------
    /**
    */
    inline const Math::mat4&
        TopdownCameraUtil::GetTransform() const
    {
        return this->cameraTransform;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetRotateButton(bool state)
    {
        this->rotateButton = state;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetAccelerateButton(bool state)
    {
        this->accelerateButton = state;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetMouseMovement(Math::vec2 movement)
    {
        this->mouseMovement = movement;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetRotationSpeed(float speed)
    {
        this->rotationSpeed = speed;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetMovementSpeed(float speed)
    {
        this->moveSpeed = speed;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetForwardsKey(bool state)
    {
        this->forwardsKey = state;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetBackwardsKey(bool state)
    {
        this->backwardsKey = state;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetLeftStrafeKey(bool state)
    {
        this->leftStrafeKey = state;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetRightStrafeKey(bool state)
    {
        this->rightStrafeKey = state;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetUpKey(bool state)
    {
        this->upKey = state;
    }

    //------------------------------------------------------------------------------
    /**
    */
    inline void
        TopdownCameraUtil::SetDownKey(bool state)
    {
        this->downKey = state;
    }

} // namespace RenderUtil
//------------------------------------------------------------------------------