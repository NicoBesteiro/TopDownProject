#pragma once

#include "ICommand.h"
#include "../Entities/Player.h"

class MoveCommand : public ICommand {
public:
	MoveCommand(Vector2 dir);
	void Execute(Player& target, float deltaTime);
};