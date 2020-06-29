#pragma once

#include "IView.h"

class ShaderBordViewModel;

class ShaderBordView : public IView {
public:
	ShaderBordView(ShaderBordViewModel* vm)
		:m_ViewModel(vm) {};

	void Start() override;
	void Update() override;
	void Draw() override;
private:
	ShaderBordViewModel* m_ViewModel;
};