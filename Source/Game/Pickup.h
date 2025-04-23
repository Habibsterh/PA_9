#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Core/Delegate.h"
#include "Engine/Content/AssetReference.h"
API_CLASS() class GAME_API Pickup : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(Pickup);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
    void Reset();

    // Handles binding and unbinding
    void OnStart() override;
    void OnDestroy() override;
public:
    API_FIELD() AssetReference<Prefab> _audioSource;

    Delegate<> OnGrabbed;
    API_FIELD() int _type = 0;
    //because enums are f*cked
    //0 is time
    //1 is pistol
    //2 is shotgun
    //3 is win

    // Picks up item and plays appropriate audio
    int Grab();

};
