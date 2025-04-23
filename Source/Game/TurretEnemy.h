#pragma once

// NOT USED 

#include "Engine/Scripting/Script.h"
#include "Engine/Level/Prefabs/PrefabManager.h"
#include "Engine/Content/AssetReference.h"
API_CLASS() class GAME_API TurretEnemy : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(TurretEnemy);
    
public:

API_FIELD() AssetReference<Prefab> _bulletPrefab;
    // [Script]
private:

    float _timeLastFired;
    float _bulletDelay;
    float _burstDelay;
    float _spreadAngle;

    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
};
