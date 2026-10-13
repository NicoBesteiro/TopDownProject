#include "../include/Entities/Bullet.h" 

// Constructor 
Bullet::Bullet(Vector2 position_, Vector2 size_, Vector2 dir_, float damage_, float speed_, Color color_)
    : position(position_),
    size(size_),
    dir(dir_),
    damage(damage_),
    speed(speed_),
    color(color_) {
}

void Bullet::update(float deltaTime) {
    position.x += dir.x * speed * deltaTime;
    position.y += dir.y * speed * deltaTime;

    if (isOutOfBoundries())  dead = true;
}

void Bullet::draw() const {
    float rotation = atan2f(dir.y, dir.x) * (180.0f / PI);
    Rectangle rec = { position.x, position.y, size.x, size.y };
    Vector2 origin = { size.x / 2.0f, size.y / 2.0f };
    DrawRectanglePro(rec, origin, rotation, color);
}

bool Bullet::isOutOfBoundries() {
    return (position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight());
}
