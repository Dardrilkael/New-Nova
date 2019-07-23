#include "novapch.h"
#include "Nova/LayerStack.h"


namespace Nova
{

	
	LayerStack::LayerStack():
		m_LayerIndex(0)
	{

	}

	LayerStack::~LayerStack()
	{
		for (auto layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerIndex, layer);
		layer->OnUpdate();
		m_LayerIndex++;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->OnAttach();

	}

	void LayerStack::PopLayer(Layer* layer)
	{
		LayerList::iterator it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerIndex, layer);
		if (it != m_Layers.end())
		{
			layer->OnDetach();
			m_Layers.erase(it);
			m_LayerIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		LayerList::iterator it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerIndex, overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();
			m_Layers.erase(it);
		}

	}

}