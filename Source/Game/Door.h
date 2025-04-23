#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Level/Actor.h"
#include "Engine/Audio/AudioSource.h"
#include "Engine/Content/AssetReference.h"

API_CLASS() class GAME_API Door : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(Door);

    // [Script]
void OnStart() override;
void OnDestroy() override;
    void OnUpdate() override;
    bool _isOpening = false;
    float _timeToOpen = 0.6;
public:
    // Plays door opening sound and sets _isOpening to true
    void Open();
    // Resets door
    void Reset();
    API_FIELD() ScriptingObjectReference<Actor> _doorTransform;
    
    API_FIELD() AssetReference<Prefab> _audioSource;

};
