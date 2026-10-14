#pragma once
#include <vector> 
#include "raylib.h" 
#include "Bullet.h" 
#include "raymath.h"  
#include <algorithm> 

class Player {
public:
    // Constructor: Initializes the default state
    Player(Vector2 position_, float radiusSize_, float speed_, Color color_);

    // Core loop functions
    void update(float deltaTime);

    void draw() const;

    void move(Vector2 dir, float deltaTime);

    void fireWeapon();

private:
    Vector2 position;
    float radiusSize;
    float speed;
    Color color;
    std::vector<Bullet> bullets;
};