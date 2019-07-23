#pragma once
#include "Nova/Core.h"

#include "Nova/Layer.h"
#include <vector>

namespace Nova
{

typedef std::vector<Layer*> LayerList;

class NOVA_API LayerStack
{
public:
	LayerStack();
	~LayerStack();

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);

	void PopLayer(Layer* layer);
	void PopOverlay(Layer* overlay);

	LayerList::iterator begin() { return m_Layers.begin(); }
	LayerList::iterator end() { return m_Layers.end(); }

private:
	LayerList m_Layers;
	uint32_t m_LayerIndex;
	




};

}

