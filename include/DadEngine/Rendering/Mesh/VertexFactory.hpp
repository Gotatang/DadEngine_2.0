#ifndef __VERTEX_FACTORY_HPP_
#define __VERTEX_FACTORY_HPP_

#include "../../Core/Core.hpp"

namespace DadEngine::Rendering
{
    class RawMesh;
    struct VertexInput;

	class Vertexfactory
	{

	public:

		static void Create(RawMesh& _InMesh, TArray<float>& _OutData, TArray<VertexInput>& _InVerticesLayout, uint32_t& _OutStride);
	};
}

#endif //__VERTEX_FACTORY_HPP_