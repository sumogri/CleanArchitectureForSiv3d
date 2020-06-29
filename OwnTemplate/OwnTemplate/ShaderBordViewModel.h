#pragma once

#include "IViewModel.h"

#include "ItaPoly.h"
#include <Siv3D/Array.hpp>
#include <Siv3D/Texture.hpp>
#include <Siv3D/FileSystem.hpp>
#include <Siv3D/Stopwatch.hpp>
#include <Siv3D/ConstantBuffer.hpp>
#include <Siv3D/PixelShader.hpp>

class ShaderBordViewModel : public IViewModel{
public:
	ShaderBordViewModel();
	void OnUpdate();
	s3d::Texture GetTexture();
	s3d::PixelShader GetPixelShader();
	void SetConstantBufferToGPU();
	s3d::FilePath GetFilePath();
	void Reload();
private:
	s3d::Texture m_dummyTexture;
	s3d::FilePath m_shaderFilePath;
	s3d::FilePath m_fullShaderFilePath;
	s3d::Array<s3d::ConstantBufferBinding> m_bindings;
	s3d::Stopwatch m_stopwatch;
	s3d::ConstantBuffer<ItaPoly> m_constantBuffer;
	s3d::PixelShader m_pixelShader;
};