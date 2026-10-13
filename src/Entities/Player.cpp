#include "../include/Entities/Player.h" 

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
}

void Player::draw() const {
    DrawCircle(position.x, position.y, radiusSize, color);
}