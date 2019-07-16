#pragma once
#include "Input.h"

namespace Nova
{

class WindowsInput :
	public Input
{
	// Herdado por meio de Input
	virtual bool Impl_IsKeyPressed(int key) override;
	virtual bool Impl_IsMouseButtonPressed(int button) override;
	virtual std::pair<float, float> Impl_GetMousePos() override;
	virtual float Impl_GetMouseXPos() override;
	virtual float Impl_GetMouseYPos() override;


};

}


