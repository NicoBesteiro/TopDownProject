#include "../include/Input/MoveCommand.h"

void MoveCommand::Execute(Player& target, float deltaTime) {
    if (IsKeyDown(KEY_D))    target.move({ 1,0 }, deltaTime);
    if (IsKeyDown(KEY_A))    target.move({ -1,0 }, deltaTime);
    if (IsKeyDown(KEY_W))    target.move({ 0,-1 }, deltaTime);
    if (IsKeyDown(KEY_S))    target.move({ 0,1 }, deltaTime);
}