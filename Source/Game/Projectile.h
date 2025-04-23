#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Level/Actor.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Physics/Colliders/Collider.h"

API_CLASS() class GAME_API Projectile : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(Projectile);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;

    Vector3 _currentVelocity;

    // Handle physics
    void OnTriggerEnter(PhysicsColliderActor* other);
public:

    // Sets velocity of projectile
    void SetVelocity(Vector3 velocity);

    API_FIELD() ScriptingObjectReference<Collider> _collider;
};
