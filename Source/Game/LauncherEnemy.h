#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Content/AssetReference.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Level/Actor.h"

API_CLASS() class GAME_API LauncherEnemy : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(LauncherEnemy);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;

    // Spawns missiles according to spawn timer
    void SpawnMissile();
    float _spawnTimer;
    void Reset();
public:
    API_FIELD() AssetReference<Prefab> _missilePrefab;
    API_FIELD() float _spawnTime;
    API_FIELD() float _startingTime;
};
