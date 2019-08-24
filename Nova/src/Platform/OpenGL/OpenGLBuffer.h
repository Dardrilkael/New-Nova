#pragma once 
#include "Nova/Renderer/Buffer.h"

namespace Nova
{
	class OpenGLVertexBuffer: public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size, MemoryPlace place);
		virtual ~OpenGLVertexBuffer();
		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual void addLayout(const VertexBufferLayout& layout) override;

	private:
		uint32_t m_RendererID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
		
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t size);
	
		virtual ~OpenGLIndexBuffer();
		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual uint32_t GetCount() const override { return m_Count; }
	protected:
		
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;

		// Herdado por meio de IndexBuffer
	};

	class OpenGLVertexArray: public VertexArray
	{
	public:
		OpenGLVertexArray();

		// Herdado por meio de VertexArray
		virtual void Bind() override;
		virtual void UnBind() override;
		virtual void AddBuffer(const std::shared_ptr<VertexBuffer>& vb, const std::shared_ptr<IndexBuffer>& ib) override;

	private:
		const std::shared_ptr<VertexBuffer>* m_VertexBuffer;
		const std::shared_ptr<IndexBuffer>* m_IndexBuffer;
		
		uint32_t m_RendererID;

		// Herdado por meio de VertexArray
		virtual inline const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const override { return *m_VertexBuffer; }
		virtual inline const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return *m_IndexBuffer; }
	};
}