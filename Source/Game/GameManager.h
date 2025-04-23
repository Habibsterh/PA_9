#pragma once

#include "Engine/Scripting/Script.h"
#include "Engine/Core/Collections/Array.h"
#include "Engine/Scripting/ScriptingObjectReference.h"
#include "Engine/Core/Delegate.h"
API_CLASS() class GAME_API GameManager : public Script
{
API_AUTO_SERIALIZATION();
DECLARE_SCRIPTING_TYPE(GameManager);

private:
	void OnAwake() override;
	void OnUpdate() override;
	void OnStart() override;
	static GameManager* _instance;

	// The following functions handle the user interface after death
	void ShowDeathScreen();
	void HideDeathScreen();

	// The following functions handle user interface after winning
	void ShowWinScreen();
	void HideWinScreen();

	// The following funcitons handle user interface showing game information
	void ShowInfoText();
	void HideInfoText();
	bool _gameOver = false;
	void UpdateTime();
	int _shotgunAmmo;
	int _pistolAmmo;
public:
	// Adds time to run
	void AddTime(float time);

	// Checks for game ending
	bool IsGameOver();

	// Sets shotgun ammunition quantity
	void SetShotgunAmmo(int shotgunAmmo);

	// Sets pistol ammunition quantity
	void SetPistolAmmo(int pistolAmmo);
	API_FIELD() float _startingTime = 5;

	float _time;
	
	Delegate<> OnReset;

	// Handles game loss
	void Lose();
	static GameManager* GetInstance();
	void ResetGame();

	// Handles game win
	void Win();
	API_FIELD() ScriptingObjectReference<Actor> _UIManager;
};
