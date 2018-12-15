#include "FramePacket.hpp"
#include "ViewPacket.hpp"
#include "RenderObject.hpp"

namespace DadEngine::Rendering
{
	void FramePacket::AddViewPacket(const ViewPacket& _InViewPacket)
	{
		m_Packets.Add(_InViewPacket);
	}

	void FramePacket::Extract()
	{
		for (ViewPacket& currentView : m_Packets)
		{
			currentView.ExtractObjects(*this);
		}
	}

	bool FramePacket::HasExtracted(RenderObject * _InRenderObject)
	{
		return FALSE;
	}
}