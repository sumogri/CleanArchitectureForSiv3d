#pragma once

class IView {
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};