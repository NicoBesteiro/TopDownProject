#include "../include/Entities/Player.h" 
#include "raymath.h"  
#include <algorithm>  

// Constructor 
Player::Player(Vector2 position_, float radiusSize_, float speed_, Color color_)
    : position(position_),
    radiusSize(radiusSize_),
    speed(speed_),
    color(color_) {}

void Player::update(float deltaTime) {
    if (IsKeyDown(KEY_D))    position.x += speed * deltaTime;
    if (IsKeyDown(KEY_A))    position.x -= speed * deltaTime;
    if (IsKeyDown(KEY_W))    position.y -= speed * deltaTime;
    if (IsKeyDown(KEY_S))    position.y += speed * deltaTime;
    if (IsKeyPressed(KEY_SPACE))    fireWeapon();

    for (auto& i : bullets) {
        i.update(deltaTime);
    }

    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) {
            return !b.isAlive();
            }),
        bullets.end()
    );
}

void Player::draw() const {
    DrawCircle(position.x, position.y, radiusSize, color);
    for (const auto& i : bullets) {
        if (i.isAlive()) {
            i.draw();
        }
    }
}

void Player::fireWeapon() {
    Vector2 mousePos = GetMousePosition();

    Vector2 dir = Vector2Normalize(Vector2Subtract(mousePos, position));

    bullets.push_back({ position, { 10, 5 }, dir, 1.0, 500.0, YELLOW });
}
