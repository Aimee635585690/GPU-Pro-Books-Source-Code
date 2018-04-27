#include "Precompiled.h"
#include "D3D9FormatMap.h"

#include "Wrap3D\Src\Formats.h"
#include "Wrap3D\Src\Format.h"


namespace Mod
{

	namespace
	{
		typedef D3D9FormatMap::Map::value_type MapEntry;
		template <typename FmtPtr>
		MapEntry Entry( D3DFORMAT fmt, const FmtPtr& ptr )
		{
			if( ptr.null() )
				return MapEntry( fmt, NULL );
			else
				return MapEntry( fmt, static_cast<const Format*>(&*ptr) );
		}
	}

	D3D9FormatMap::D3D9FormatMap( const Formats& formats )
	{
#define MD_INSERT_FORMAT(d3dfmt,fmt) mMap.insert( Entry( d3dfmt, formats.##fmt ));
#define MD_UNSUPPORTED(d3dfmt,fmt)

		const int LINE_GUARD_START = __LINE__ + 3;
		// -- DO NOT ADD UNRELATED LINES --
		MD_INSERT_FORMAT( D3DFMT_A8R8G8B8,		R8G8B8A8_UNORM			) MD_INSERT_FORMAT( D3DFMT_X8R8G8B8,		R8G8B8A8_UNORM		)
		MD_UNSUPPORTED	( D3DFMT_A8R8G8B8,		R8G8B8A8_SNORM			)
		MD_INSERT_FORMAT( D3DFMT_L8,			R8_UNORM				)
		MD_INSERT_FORMAT( D3DFMT_A32B32G32R32F,	R32G32B32A32_FLOAT		)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R32G32B32_FLOAT			)
		MD_INSERT_FORMAT( D3DFMT_G32R32F,		R32G32_FLOAT			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R32G32B32_UINT			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R32G32_UINT				)
		MD_INSERT_FORMAT( D3DFMT_R32F,			R32_FLOAT				)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R32_UINT				)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R32_SINT				)
		MD_INSERT_FORMAT( D3DFMT_A16B16G16R16F,	R16G16B16A16_FLOAT		)
		MD_INSERT_FORMAT( D3DFMT_A16B16G16R16,	R16G16B16A16_UNORM		)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R16G16B16A16_SNORM		)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R16G16B16A16_UINT		)
		MD_INSERT_FORMAT( D3DFMT_G16R16F,		R16G16_FLOAT			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R16G16_SNORM			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R16G16_UNORM			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R16_TYPELESS			)
		MD_INSERT_FORMAT( D3DFMT_R16F,			R16_FLOAT				)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R16_UINT				)
		MD_INSERT_FORMAT( D3DFMT_L16,			R16_UNORM				)
		MD_INSERT_FORMAT( D3DFMT_D16,			D16_UNORM				)
		MD_INSERT_FORMAT( D3DFMT_A8L8,			R8G8_UNORM				)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R8_UINT					)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R8G8B8A8_SINT			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R8G8B8A8_UINT			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R8_SINT					)
		MD_INSERT_FORMAT( D3DFMT_D24S8,			D24_UNORM_S8_UINT		)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		R24G8_TYPELESS			)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		X24_TYPELESS_G8_UINT	)
		MD_INSERT_FORMAT( D3DFMT_D24X8,			R24_UNORM_X8_TYPELESS	)
		MD_INSERT_FORMAT( D3DFMT_DXT1,			BC1_UNORM				)
		MD_INSERT_FORMAT( D3DFMT_DXT3,			BC2_UNORM				)
		MD_INSERT_FORMAT( D3DFMT_DXT5,			BC3_UNORM				)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		BC5_SNORM				)
		MD_UNSUPPORTED	( D3DFMT_UNKNOWN,		BC5_UNORM				)
		// -- DO NOT ADD UNRELATED LINES --
		MD_STATIC_ASSERT( __LINE__ - LINE_GUARD_START == Formats::NUM_FORMATS );

#undef MD_UNSUPPORTED
#undef MD_INSERT_FORMAT
	}

	//------------------------------------------------------------------------

	D3D9FormatMap::~D3D9FormatMap()
	{

	}

	//------------------------------------------------------------------------

	const Format*
	D3D9FormatMap::GetFormat( D3DFORMAT fmt ) const
	{
		Map::const_iterator found = mMap.find( fmt );

		if( found == mMap.end() )
			return NULL;
		else
			return found->second;
	}

}
