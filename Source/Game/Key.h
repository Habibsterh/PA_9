#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Door.h"
API_CLASS() class GAME_API Key : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(Key);

    // [Script]

    // Opens door using key
    void Open();
    void OnStart() override;
    void OnDestroy() override;
public:
    API_FIELD() ScriptingObjectReference<Door> _door;
    
};
