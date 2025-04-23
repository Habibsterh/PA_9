#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Pickup.h"
#include "Engine/Audio/AudioSource.h"
#include "Engine/Content/AssetReference.h"

API_CLASS() class GAME_API Bell : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(Bell);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
    void OnStart() override;
    void OnDestroy() override;
    void Reset();
public:
    API_FIELD() ScriptingObjectReference<Pickup> _pickup;
    API_FIELD() AssetReference<Prefab> _audioSource;
    //Handles interactions with bell
    void Ring();
};
