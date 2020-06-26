#pragma once

#include "IView.h"

class ViewConcrete : public IView {
public:
	void Start() override;
	void Update() override;
	void Draw() override;
};