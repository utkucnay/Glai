#pragma once
#include <entt/entt.hpp>

namespace Glai::ECS
{
	class SystemBase
	{
	public:
		virtual void Awake()		{}
		virtual void Start()		{}
		virtual void Update()		{}
		virtual void LateUpdate()	{}
	};
}