#include "ShaderBordViewModel.h"

#include <Siv3D.hpp>

ShaderBordViewModel::ShaderBordViewModel() {
    // �_�~�[�e�N�X�`��
    m_dummyTexture = Texture(U"example/windmill.png");
    
    // �V�F�[�_�t�@�C���� (shader.hlsl �͎����ŗp�Ӂj
    m_shaderFilePath = U"shader" SIV3D_SELECT_SHADER(U".hlsl", U".frag");
    m_fullShaderFilePath = FileSystem::FullPath(m_shaderFilePath);
    m_bindings ={ { U"PSConstants2D", 0 }, { U"ItaPoly", 1 } };
}

void ShaderBordViewModel::OnUpdate() {

    if (m_stopwatch.isStarted() == false)
        m_stopwatch.restart();

    // �萔�o�b�t�@�̒l��ݒ�
    m_constantBuffer->resolution = Scene::Size();
    m_constantBuffer->mouse = Cursor::Pos();
    m_constantBuffer->time = m_stopwatch.ms() / 1000.0f;
}

s3d::Texture ShaderBordViewModel::GetTexture() 
{
    return m_dummyTexture;
}

s3d::PixelShader ShaderBordViewModel::GetPixelShader()
{
	s3d::PixelShader ps(m_shaderFilePath,m_bindings);
    if (!ps)
    {
        throw Error(U"Failed to load a shader file");
    }

	return ps;
}

s3d::FilePath ShaderBordViewModel::GetFilePath() 
{
    return m_fullShaderFilePath;
}

void ShaderBordViewModel::SetConstantBufferToGPU() 
{
    Graphics2D::SetConstantBuffer(ShaderStage::Pixel,1, m_constantBuffer);
}

void ShaderBordViewModel::Reload()
{
    // shader.hlsl ���ύX���ꂽ��
    if (PixelShader tmp{ m_shaderFilePath, m_bindings })
    {
        std::swap(m_pixelShader, tmp);
        m_stopwatch.restart(); // �X�g�b�v�E�H�b�`�� 0 ����J�E���g������
    }
}