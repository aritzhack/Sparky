#include "sp/sp.h"
#include "VertexBuffer.h"

#include "sp/platform/opengl/GLVertexBuffer.h"
#ifdef SP_DX
#include "sp/platform/directx/DXVertexBuffer.h"
#endif

#include "sp/graphics/API/Context.h"

namespace sp { namespace graphics { namespace API {

	VertexBuffer* VertexBuffer::Create(BufferUsage usage)
	{
		switch (Context::GetRenderAPI())
		{
			case RenderAPI::OPENGL:		return spnew GLVertexBuffer(usage);
			#ifdef SP_DX
			case RenderAPI::DIRECT3D:	return spnew D3DVertexBuffer(usage);
			#endif
		}
		return nullptr;
	}

} } }
