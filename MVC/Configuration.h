#pragma once

#define FontPath 
//#define FontPath "C:/Windows/Fonts/"
//#define FontPath "resources/fonts/"

#define WindowWidth 600
#define WindowHeight 400

#define Gravity 9.8f
#define AirDrag 1000.f

// Player
#define PlayerX 50
#define PlayerMoveSpeed 5
#define PlayerDamage 20
#define PlayerHealth 150

// Shooting
#define InitAngle 0.0f
#define InitPower 1500
#define AngleStep 3.14159f / 18.f
#define PowerStep 100
#define MaxPower 3000
#define MinPower 500

// Enemies
#define EnemyHP 100
#define EnemyDamage 10
#define BaseEnemySpeed 10.f
#define EnemyAcceleration 60.f

// Difficulty
#define EnemyKillScore 100
#define EnemyCountCoef 1.f/500
#define EnemySpeedCoef 0.015f
