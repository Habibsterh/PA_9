#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Core/Delegate.h"

API_CLASS() class GAME_API ShotHandler : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(ShotHandler);

    // [Script]
    void OnEnable() override;
    void OnDisable() override;
    void OnUpdate() override;
public:

    // Shoots a shot when shooting
    void TakeShot();
    Delegate<> OnShot;
};
