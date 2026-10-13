#pragma once
#include <cmath>
#include "raylib.h" 

class Bullet {
public:
    // Constructor: Initializes the default state
    Bullet(Vector2 position_, Vector2 size_, Vector2 dir, float damage, float speed_, Color color_);

    // Core loop functions
    void update(float deltaTime);

    void draw() const;

    bool isAlive() const { return !dead; };

protected:
    Vector2 position;
    Vector2 size;
    float speed;
    Color color;
    float damage;
    Vector2 dir;
    bool dead = false;
private:
    bool isOutOfBoundries();
};