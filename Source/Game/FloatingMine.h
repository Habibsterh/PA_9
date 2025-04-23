#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Level/Actor.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Physics/Actors/RigidBody.h"
#include "PlayerController.h"
#include "Engine/Physics/Colliders/Collider.h"
#include "GameManager.h"

API_CLASS() class GAME_API FloatingMine : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(FloatingMine);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
    void OnDestroy() override;
    // Calls handle death
    void GetShot();
    void OnStart() override;
    // Resets mine
    void OnReset();
    // Handles explosion on collision
    void OnTriggerEnter(PhysicsColliderActor* other);
    // Explodes and deletes itself as necessary
    void HandleDeath();
    bool _awaitingReset = false;

public:
    API_FIELD() bool _existsOnStart;
    API_FIELD() ScriptingObjectReference<Collider> _col;
};
