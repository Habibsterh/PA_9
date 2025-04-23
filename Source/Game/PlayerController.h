#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Physics/Colliders/CharacterController.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Physics/Colliders/Collider.h"
#include "Engine/Core/Collections/Array.h"
#include "Engine/Core/Types/Pair.h"
#include "Engine/Audio/Audio.h"
#include "Engine/Audio/AudioSource.h"
#include <queue>


API_CLASS() class GAME_API PlayerController : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(PlayerController);

public:
    API_FIELD() ScriptingObjectReference<CharacterController> _characterController;
    API_FIELD() ScriptingObjectReference<Actor> _cameraContainer;
    API_FIELD() ScriptingObjectReference<Actor> _playerBody;
    API_FIELD() ScriptingObjectReference<AudioSource> _splatSource;
    API_FIELD() ScriptingObjectReference<AudioSource> _jumpSource;
    API_FIELD() ScriptingObjectReference<AudioSource> _loseSource;
    API_FIELD() float _movementSpeed = 600.0;
    API_FIELD() float _airMovementAcceleration = 1000.0;
    API_FIELD() float _groundMovementAcceleration = 2000.0;
    API_FIELD() float _gravity = 1000.0;
    API_FIELD() float _rotationSmoothing = 20.0;
    API_FIELD() float _jumpSpeed = 1000.0;

    API_FIELD() float _jumpNormalForce = 1000.0;
    API_FIELD() float _jumpVerticalForce = 1000.0;

    
    // Retrieves player status
    static PlayerController* GetInstance(); 
    Vector3 GetVelocity();

    // Fires shotgun and adjusts physics according to recoil power
    void FireShotgun(float recoilPower);

    // Handles camera positioning
    Quaternion GetCameraOrientation();
    Vector3 GetCameraPosition();

    // Picks up items
    void HandlePickup(int pickupType);


private:
    
    std::queue<Pair<float, Vector3>> _activeContacts;

    void OnEnable() override;
    void OnDisable() override;

    void OnAwake() override;
    void OnUpdate() override;
    void OnStart() override;
    void Reset();

    enum State
    {
        Air,
        Ground
    };

    Vector3 _currentVelocity = Vector3::Zero;

    static PlayerController* _instance;

    float _bodyRotation = 0;
    float _startingBodyRotation = 0;

    float _cameraPitch = 0;
    float _startingCameraPitch = 0;

    Vector3 _startingPosition = { 0.0,0.0,0.0 };

    float _timeLastGrounded = -9999.9;
    float _timeJumpLastPressed = -9999.9;
    State _state = Air;

    float _frameRecoil = 0.0;

    bool _dead = false;
    bool _isLookingBackward = false;
    bool _awaitingReset = false;

    // Allows character movements
    void HandleMovement();

    // Determines status of player (on ground vs. in air) for movement
    void EvaluateState();

    // Adjusts camera angle according to movement
    void PitchCamera();

    // Rotate body according to cursor
    void RotateBody();

    // Determine movement
    void HandleHorizontalMovement();
    void HandleVerticalMovement();

    // Moves character
    void ApplyMovement();

    // Does jump math
    void EvaluateJump();

    // Handles death
    void Die();

    // Handles shooting
    void HandleShooting();

    // Collision physics
    void OnTriggerEnter(PhysicsColliderActor* other);
    void OnCollisionEnter(const Collision& collision);
};
