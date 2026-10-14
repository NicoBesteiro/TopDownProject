#include "../include/Entities/Player.h"  

// Constructor 
Player::Player(Vector2 position_, float radiusSize_, float speed_, Color color_)
    : position(position_),
    radiusSize(radiusSize_),
    speed(speed_),
    color(color_) {}

void Player::update(float deltaTime) {
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

void Player::move(Vector2 dir, float deltaTime) {
    position.x += dir.x + speed * deltaTime;
    position.y += dir.y + speed * deltaTime;
}

void Player::fireWeapon() {
    Vector2 mousePos = GetMousePosition();

    Vector2 dir = Vector2Normalize(Vector2Subtract(mousePos, position));

    bullets.push_back({ position, { 10, 5 }, dir, 1.0, 500.0, YELLOW });
}
