#pragma once
#include "raylib.h" 

class Player {
public:
    // Constructor: Initializes the default state
    Player(Vector2 position_, float radiusSize_, float speed_, Color color_);

    // Core loop functions
    void update(float deltaTime);

    void draw() const;

private:
    // Internal state (encapsulated)
    Vector2 position;
    float radiusSize;
    float speed;
    Color color;
};