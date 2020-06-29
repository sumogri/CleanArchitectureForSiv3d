#pragma once

#include "IView.h"
#include "DirectoryWatchViewModel.h"

class DirectoryWatchView : public IView {
public:
	DirectoryWatchView(DirectoryWatchViewModel* vm)
		:m_viewModel(vm) {}

	void Start() override;
	void Update() override;
	void Draw() override;
private:
	DirectoryWatchViewModel* m_viewModel;
};