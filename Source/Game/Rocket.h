#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Level/Actor.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Physics/Actors/RigidBody.h"
#include "PlayerController.h"
#include "Engine/Physics/Colliders/Collider.h"
#include "GameManager.h"
#include "Engine/Audio/AudioSource.h"
API_CLASS() class GAME_API Rocket : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(Rocket);

// [Script]
void OnEnable() override;
void OnDisable() override;
void OnUpdate() override;
PlayerController* _followPlayer = nullptr;

// Sets target player
void FindPlayer();

void OnReset();

// Handles missile death through getting shot
void GetShot();

public:
    API_FIELD() ScriptingObjectReference<RigidBody> _rb;
    API_FIELD() ScriptingObjectReference<Collider> _col;
    API_FIELD() ScriptingObjectReference<AudioSource> _audioSource;
    API_FIELD() float _thrustPower;

    // Physics for colliding with other objects
    void OnTriggerEnter(PhysicsColliderActor* other);

    // Sets intial velocity magnitude and direction
    void SetInitialVelocity(Vector3 force);
};
