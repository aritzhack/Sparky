#include "sp/sp.h"
#include "IndexBuffer.h"

#include "sp/platform/opengl/GLIndexBuffer.h"
#ifdef SP_DX
#include "sp/platform/directx/DXIndexBuffer.h"
#endif

#include "sp/graphics/API/Context.h"

namespace sp { namespace graphics { namespace API {

	IndexBuffer* IndexBuffer::Create(uint16* data, uint count)
	{
		switch (Context::GetRenderAPI())
		{
			case RenderAPI::OPENGL:		return spnew GLIndexBuffer(data, count);
            #ifdef SP_DX
			case RenderAPI::DIRECT3D:	return spnew D3DIndexBuffer(data, count);
            #endif
		}
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint* data, uint count)
	{
		switch (Context::GetRenderAPI())
		{
			case RenderAPI::OPENGL:		return spnew GLIndexBuffer(data, count);
            #ifdef SP_DX
			case RenderAPI::DIRECT3D:	return spnew D3DIndexBuffer(data, count);
            #endif
		}
		return nullptr;
	}

} } }
