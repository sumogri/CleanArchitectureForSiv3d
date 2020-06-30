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
	/*
	//RGBシフト
	float2 ra = g_texture0.Sample(g_sampler0, input.uv + float2(0, 0.0)).ra;
	float2 ga = g_texture0.Sample(g_sampler0, input.uv).ga;
	float2 ba = g_texture0.Sample(g_sampler0, input.uv + float2(0, 0.0)).ba;

	float a = (ra.y + ga.y + ba.y) / 3;
	float4 texColor = float4(ra.x, ga.x, ba.x, a);

	return (texColor * input.color) + g_colorAdd;
	*/

	/*
	// 時間で対角線動かす
	float4 texColor = float4(1,1,1,1);
	float speed = 0.01;
	if(input.uv.x + input.uv.y <= speed * g_time){
		texColor = float4(0,0,0,1);
	}	
	return texColor;
	*/

	//色混ぜ
	//return float4(1,0,0,0.5) + g_texture0.Sample(g_sampler0, input.uv);

	// 円
	/*
	float4 texColor = float4(0.5,0.5,0.5,0);
	float2 center = float2(400,300);
	float2 dist = input.position.xy - center;
	
	if (length(dist) < 200){
		texColor = float4(0,0,0,1);
	}	
	return texColor;	
	*/
	float4 baseColor = float4(0.5, 0.5, 0.5, 0);
	float4 texColor = baseColor; //実際の描画色

	//たまを降らす
	/*
	float4 borlColor = float4(1, 1, 1, 1);
	float2 centerRoot = float2(100, 10);
	for (int i = 0; i < 10; i++)
	{
		float2 center = centerRoot + float2(100 * i , 0);
		center += float2(0, 100) * g_time % 600;
		float2 dist = input.position.xy - center;
		float radius = 10;
	
		if (length(dist) < radius)
		{
			texColor = borlColor;
		}
	}*/
	
	float speed = 0.05;
    if ( (1 - input.uv.y)  < sin((input.uv.x * 3.14 * 5 + g_time) % 3.14) / 6
		|| (1 - input.uv.y) < sin((input.uv.x * 3.14 * 5 + (g_time + 2)) % 3.14) / 6
		|| (1 - input.uv.y) < sin((input.uv.x * 3.14 * 5 + (g_time + 1)) % 3.14) / 6
		|| (1 - input.uv.y) < sin((input.uv.x * 3.14 * 5 + (g_time + 2) * 2) % 3.14) / 6
		|| (1 - input.uv.y) < 0.05)
	{
		texColor = float4(1, 1, 1, 1);	
	}	
	
	return texColor;
}
