//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2019 Ryo Suzuki
//	Copyright (c) 2016-2019 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

Texture2D		g_texture0 : register(t0);
SamplerState	g_sampler0 : register(s0);

cbuffer PSConstants2D : register(b0)
{
	float4 g_colorAdd;
	float4 g_sdfParam;
	float4 g_internal;
}

cbuffer ItaPoly : register(b1)
{
	float2 g_resolution;
	float2 g_mouse;
	float  g_time;
}

struct PSInput
{
	float4 position	: SV_POSITION;
	float4 color	: COLOR0;
	float2 uv		: TEXCOORD0;
};

float4 PS(PSInput input) : SV_TARGET
{
	float4 baseColor = float4(0.2, 0.3, 0.5, 1);
	float4 texColor = baseColor; //実際の描画色

	float speed = 0.05;
    if ((1 - input.uv.y) < sin((input.uv.x * 3.14 * 5 + g_time) % 3.14) / 11
		|| (1 - input.uv.y) < sin((input.uv.x * 3.14 * 5 + (g_time + 2)) % 3.14) / 11
		|| (1 - input.uv.y) < sin((input.uv.x * 3.14 * 5 + (g_time + 1)) % 3.14) / 11)
	{
		texColor = float4(0.95, 0.95, 0.95, 1);	
	}
    else if ((1 - input.uv.y) < sin((input.uv.x * 3.14 * 5 + (g_time + 2) * 2) % 3.14) / 10.5)
    {
        texColor = float4(0.8, 0.8, 0.8, 1);		
    }
	
    return texColor;
}
