#pragma once
#include "Log.h"

namespace Nova
{
	enum class MemoryPlace
	{
		Dynamic,
		Static
	};

	enum class BufferType
	{
		Float1 = 1 * 4,
		Float2 = 2 * 4,
		Float3 = 3 * 4,
		Float4 = 4 * 4,
		Mat4 = 4*4*4

	};
	uint8_t GetCountOfData(BufferType type);
	uint8_t GetSizeOfData(BufferType type);
	struct BufferElement { std::string name; BufferType type; bool normalized; };

	class VertexBufferLayout
	{
	public:
		
		VertexBufferLayout(const std::initializer_list<BufferElement>& elements);
		std::vector<BufferElement>::iterator begin() { return m_data.begin(); }
		std::vector<BufferElement>::iterator end() { return m_data.end(); }

		std::vector<BufferElement>::const_iterator begin() const { return m_data.begin(); }
		std::vector<BufferElement>::const_iterator end()  const { return m_data.end(); }
		
	private:
		std::vector<BufferElement> m_data;

	};


	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer(){}
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		static VertexBuffer* Create(float* vertices, uint32_t size, MemoryPlace place = MemoryPlace::Static);
		virtual void addLayout(const VertexBufferLayout& layout) = 0;
	};


	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		inline virtual uint32_t GetCount() const = 0;
		static IndexBuffer* Create(uint32_t* indices, uint32_t size);


	};


	class VertexArray
	{
	public:
		static VertexArray* Create();
		virtual void Bind() = 0;
		virtual void UnBind() = 0;
		virtual void AddBuffer(const std::shared_ptr<VertexBuffer>& vb, const std::shared_ptr<IndexBuffer>& ib) = 0;
		virtual inline const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const = 0;
		virtual inline const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;
	private:
	

	
	};



}