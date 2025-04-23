#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Core/Collections/Array.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Level/Actor.h"

API_CLASS() class GAME_API MovingEnemy : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(MovingEnemy);

public:
    API_FIELD() Array<ScriptingObjectReference<Actor>> _followPoints; 
    API_FIELD() float _moveSpeed = 1000.0;

    // Handles death
    void SetDestroysSelf(bool destroysSelf);

    // Sets pathing for moving enemies
    void SetFollowPoints(const Array<ScriptingObjectReference<Actor>>& points);

    // Adds a new point to pathing
    void AddFollowPoint(const ScriptingObjectReference<Actor>& newPoint);
private:
    int _currentFollowPointIndex = 0;
    bool _destroysSelf = false;
    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
    void Reset();

    Vector3 _positionOnStart;
};
