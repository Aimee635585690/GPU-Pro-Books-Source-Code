//
cbuffer Default
{
	float4x3 	matT;
	float 		normScale;
	float 		time;
	float		objFreq;
	float		objAmp;
};

struct VSIn
{
	float4 pos 	: POSITION;
	float3 norm	: NORMAL;
};

struct VSOut
{
	float3 pos 	: POSITION;
	float3 norm	: NORMAL;
};


VSOut main_vs( in VSIn i )
{

	VSOut o;

	i.pos.xyz += i.norm.xyz * normScale;
	i.pos.xyz += sin( i.pos.xyz * objFreq + time  ) * objAmp;	

	o.pos 	= mul( i.pos, matT );
	o.norm	= mul( i.norm, matT );

	return o;
}

DepthStencilState DSS_Disable
{
	DepthEnable = FALSE;
};


DepthStencilState DSS_Default
{
};


technique10 main
{
	pass
	{
		SetVertexShader( CompileShader( vs_4_0, main_vs()) );
		SetGeometryShader( ConstructGSWithSO( CompileShader(vs_4_0, main_vs()), "POSITION.xyz;NORMAL.xyz") );
		SetPixelShader( NULL );

		SetDepthStencilState( DSS_Disable, 0 );
	}

	pass
	{
		SetDepthStencilState( DSS_Default, 0 );
	}
}