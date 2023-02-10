#pragma once

#define ENG_CORE_ASSERT(ex) spdlog::error(ex); 
#define ENG_CORE_COND_ASSERT(cond,ex) if(cond) spdlog::error(ex); 
#define ENG_CORE_LOG(ex) spdlog::info(ex); 

#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <format>
#include <sstream>
#include <array>
#include <deque>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include "spdlog/spdlog.h"

#include <Windows.h>

namespace Glai
{
	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, class... Tin>
	Ref<T>&& CreateRef(Tin... in) 
	{ 
		return std::move(std::make_shared<T>(in...)); 
	}

	template<typename T, class... Tin>
	Scope<T>&& CreateScope(Tin... in)
	{
		return std::move(std::make_unique<T>(in...));
	}

    template <class T>
    class Singleton
    {
    public:
        using Type = typename std::remove_all_extents<T>::type;

        template <typename ...Args>
        Singleton(Args&& ...args)
        {
            struct StaticObjCreator {
                StaticObjCreator(Scope<Type>& obj_ptr, Args&& ...arguments) {
                    ENG_CORE_COND_ASSERT(obj_ptr.get() != nullptr, "Two Create Instance Singleton")
                    obj_ptr.reset(new Type(std::forward<Args>(arguments)...));
                }
            };
            static StaticObjCreator _creator(instance, std::forward<Args>(args)...);
            ENG_CORE_COND_ASSERT(instance.get() == nullptr, "Don't Create Instance Singleton")
        }
        static Type* getInstance() { return instance.get(); }

        Type* operator->() { return &**this; }
        const Type* operator->() const { return &**this; }
        Type& operator *() { return *instance; }
        const Type& operator *() const { return *instance; }
    private:
        static inline Scope<Type> instance = nullptr;
    };
}