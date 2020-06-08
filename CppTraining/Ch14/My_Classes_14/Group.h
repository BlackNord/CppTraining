#pragma once
#include "../../Stroustruap_libs/Graph.h"

namespace myGraph_lib {
	template <typename T>
	class Group {
	private:
		Graph_lib::Vector_ref<T> vec;
	public:
		Group(const T& _vec) : vec{ _vec } {}

		Group() {}

		Graph_lib::Vector_ref<T> get_info() const {
			return vec;
		}

		void set_info(T inf) {
			vec.push_back(inf);
		}
	};
}