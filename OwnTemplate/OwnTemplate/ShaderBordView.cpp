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
        // 定数バッファを GPU に設定
        m_ViewModel->SetConstantBufferToGPU();

        // カスタムシェーダを有効に（スコープが有効な間）
        ScopedCustomShader2D shader(m_ViewModel->GetPixelShader());

        // 画面を覆うテクスチャを描く
        Scene::Rect()(m_ViewModel->GetTexture()).draw();
    }
    catch (Error e) {
        Print << e.what();
    }
}