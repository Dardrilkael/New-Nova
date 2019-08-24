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
		Camera(glm::vec3 pos = glm::vec3(0.0f), float aspectRatio = 16.f/9.f) :
			 Position(pos), Right({ 1.0f,0.0f,0.0f }), Front({0.0f, 0.0f, -3.0f }), WorldUp({ 0.0f,1.0f,0.0f })
		{
			ViewProjection = glm::mat4(1.0f);
			View = glm::mat4(1.0f);
			Angle = glm::vec3(0.0f, -90.0f, 0.0f);
			Up = glm::vec3(0.0f,1.0f,0.0f);
			Projection = glm::perspective(glm::radians(45.0f), aspectRatio, 0.01f, 100.0f);

			Update();

		}

		void Update() 
		{
			UpdateVector();
			View = glm::lookAt(Position, Position + Front, Up);
			ViewProjection = Projection * View;
		}


		inline float* GetViewProjection() { return &ViewProjection[0][0]; }
		inline float* GetProjection()     { return &Projection[0][0];     }
		inline float* GetView()           { return &View[0][0];           }

		void Displace(glm::vec3 displacement)
		{
			Position += Right * displacement.x; 
			Position += WorldUp    * displacement.y;
			Position += Front * displacement.z;

		}

		void Rotate(glm::vec3 angle)
		{ 
			Angle += angle;
			if (Angle.x > 89.0f)       Angle.x = 89.0f;
			else if (Angle.x < -89.0f) Angle.x = -89.0f;
		}

		void UpdateVector()
		{
			Front.x = cos(glm::radians(Angle.y)) * cos(glm::radians(Angle.x));
			Front.y = sin(glm::radians(Angle.x));
			Front.z = sin(glm::radians(Angle.y)) * cos(glm::radians(Angle.x));
			Front = glm::normalize(Front);
			Right = glm::normalize(glm::cross(Front, WorldUp));
			Up    = glm::normalize(glm::cross(Right, Front));
		}

	private:

		glm::vec3 Position;
		glm::vec3 Right;
		glm::vec3 Front;
		glm::vec3 WorldUp;
		glm::vec3 Angle;
		glm::vec3 Up;

		glm::mat4 ViewProjection;
		glm::mat4 View;
		glm::mat4 Projection;
	};
}