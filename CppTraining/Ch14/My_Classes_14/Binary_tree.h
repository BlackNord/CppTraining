#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include "../../Ch13/My_Classes/tBox.h"
#include "../../Ch13/My_Classes/Arrow.h"
#include <vector>

namespace myGraph_lib {
	template <typename T>
	class Binary_tree : public Graph_lib::Shape {
	private:
		int levels{ 0 };
		Graph_lib::Vector_ref<myGraph_lib::tBox> nodes;
		Graph_lib::Vector_ref<Graph_lib::Line> lines;
		Graph_lib::Vector_ref<myGraph_lib::Arrow> arrows;

		void build_tree(int rad_circl) {
			int step_x{ 0 }, step_y{ 60 }, count{ 0 }, position{ 650 }, step{ 670 };
			bool next_level = false;

			for (int i{ 0 }; i < levels; ++i) {
				if (i == count * 2) next_level = true;			// *

				nodes.push_back(new myGraph_lib::tBox{ Point{ position + step_x, step_y }, 100, 50, rad_circl, "0" });

				step_x += step;
				if (next_level) {
					position -= 270;
					step_x = 0;
					step_y += 200;
					step -= 170;
					next_level = false;
				}
				count = i;
			}
		}

		template <typename T>
		void build_nets() {
			int count{ 0 };
			string str, old_str;

			for (int i{ 0 }, step{ 0 }; i < levels / 2; ++i, ++step) {
				if (levels % 2 == 0 and i == levels / 2 - 1) {
					count = 2;
				}
				else {
					count = 3;
				}
				
				for (int j{ 1 }; j < count; ++j) {
					
					old_str = nodes[i].get_text();
					if (j % 2 == 1) {
						str = old_str + "l";
					}
					else str = old_str + "r";

					Point p1{ nodes[i].get_point().x + nodes[i].get_weight() / 2, nodes[i].get_point().y + nodes[i].get_height() + nodes[i].get_rad() };
					Point p2{ nodes[i + j + step].get_point().x + nodes[i + j + step].get_weight() / 2, nodes[i + j + step].get_point().y };
					
					nodes[i + j + step].set_text(str);

					lines.push_back(new T{ p1, p2 });
				}
			}

			for (int i{ 0 }; i < lines.size(); ++i) {
				lines[i].set_color(Graph_lib::Color::black);
			}

			for (int i{ 0 }; i < arrows.size(); ++i) {
				arrows[i].set_color(Graph_lib::Color::black);
			}

		}

	public:
		Binary_tree(int _levels) {
			if (_levels >= 0 and _levels <= 7) {
				levels = _levels;
			}
			else throw runtime_error("Wrong size");

			build_tree(20);

			build_nets<T>();
		}

		virtual void draw_lines() const override {
			for (int i{ 0 }; i < nodes.size(); ++i) {
				nodes[i].draw_lines();
			}

			for (int i{ 0 }; i < lines.size(); ++i) {
				lines[i].draw();
			}
		}
	};
}