#include "ShaderBordView.h"

#include <Siv3D.hpp>
#include "ShaderBordViewModel.h"

void ShaderBordView::Start() {

}

void ShaderBordView::Update() {
    m_ViewModel->OnUpdate();
}

void ShaderBordView::Draw() {

    try{
        // �萔�o�b�t�@�� GPU �ɐݒ�
        m_ViewModel->SetConstantBufferToGPU();

        // �J�X�^���V�F�[�_��L���Ɂi�X�R�[�v���L���Ȋԁj
        ScopedCustomShader2D shader(m_ViewModel->GetPixelShader());

        // ��ʂ𕢂��e�N�X�`����`��
        Scene::Rect()(m_ViewModel->GetTexture()).draw();
    }
    catch (Error e) {
        Print << e.what();
    }
}