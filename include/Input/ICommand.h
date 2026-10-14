#pragma once
#include "raylib.h"
class Player;

class ICommand {
public:
    // Virtual destructor 
    virtual ~ICommand() = default;

    // The core method every command must implement
    virtual void Execute(Player& target, float deltaTime) = 0;
};