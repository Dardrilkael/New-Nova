#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>

namespace Nova
{

	enum PROJECTION
	{
		PERSPECTIVE,
		ORTHO
	};


	class Camera
	{
	public:
		Camera(glm::vec3& pos = glm::vec3(0.0f)) :
			 Position(pos), Right({ 1,0,0 }), Front({0, 0, -3}), WorldUp({ 0,1,0 })
		{
			ViewProjection = glm::mat4(1.0f);
			View = glm::mat4(1.0f);
			Projection = glm::perspective(glm::radians(120.0f), 1024.0f / 720.0f, 0.01f, 100.0f);
		}

		void Update() 
		{
			View = glm::lookAt(Position, Position + Front, WorldUp);
			ViewProjection = Projection * View;
		}


		inline float* GetViewProjection() { return &ViewProjection[0][0]; }
		inline float* GetProjection() { return &Projection[0][0]; }
		inline float* GetView() { return &View[0][0]; }

		void Displace(glm::vec3 displacement) { Position += displacement; }
		void Rotate(glm::vec3 angle) { Front += angle; }

	private:

		glm::vec3 Position;
		glm::vec3 Right;
		glm::vec3 Front;

		glm::vec3 WorldUp;
		glm::mat4 ViewProjection;
		glm::mat4 View;
		glm::mat4 Projection;
	};
}