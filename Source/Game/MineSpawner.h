#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Content/AssetReference.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
API_CLASS() class GAME_API MineSpawner : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(MineSpawner);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
    float _spawnTimer;

    // Spawn mine according to spawn timer
    void SpawnMine();
    

public:
    API_FIELD() AssetReference<Prefab> _minePrefab;
    API_FIELD() ScriptingObjectReference<Actor> _mineTarget;
    API_FIELD() float _moveSpeed = 500;
    API_FIELD() float _spawnTime = 0;
    API_FIELD() float _spawnEarly = 0;
};
