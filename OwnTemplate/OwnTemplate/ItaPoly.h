#pragma once

#include "IConstantBuffer.h"

#include <Siv3D/Fwd.hpp>
#include <Siv3D/Vector2D.hpp>
#include <Siv3D/Vector3D.hpp>

// �萔�o�b�t�@
class ItaPoly : public IConstantBuffer
{
public:
	s3d::Float2 resolution;
	s3d::Float2 mouse;

	float time;
	s3d::Float3 _unused; // (16 �o�C�g�̔{���ɂ��낦��j
};