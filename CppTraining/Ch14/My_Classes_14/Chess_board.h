#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include <vector>

namespace myGraph_lib {
	class Chess_board : public Graph_lib::Shape {
	private:
		Graph_lib::Vector_ref<Graph_lib::Circle> checkers_white;
		Graph_lib::Vector_ref<Graph_lib::Circle> checkers_black;
		Graph_lib::Vector_ref<Graph_lib::Vector_ref<Graph_lib::Rectangle>> board;
		const int b_size = 8;

		void set_board() {
			int x{ 50 }, y{ 50 };
			for (int i{ 0 }; i < b_size; ++i) {
				board.push_back(new Graph_lib::Vector_ref<Graph_lib::Rectangle>);

				for (int j{ 0 }; j < b_size; ++j) {
					board[i].push_back(new Graph_lib::Rectangle{ Point{ x,y }, 50, 50 });
					x += 50;
				}

				x = 50;
				y += 50;
			}
		}

		void color() {
			for (int i{ 0 }; i < b_size; ++i) {
				for (int j{ 0 }; j < b_size; ++j) {
					if (i % 2 == j % 2) {
						board[i][j].set_color(Graph_lib::Color::white);
						board[i][j].set_fill_color(Graph_lib::Color::white);
					}
					else {
						board[i][j].set_color(Graph_lib::Color::black);
						board[i][j].set_fill_color(Graph_lib::Color::black);
					}
				}
			}
			for (int i{ 0 }; i < checkers_white.size(); ++i) {
				checkers_white[i].set_color(Graph_lib::Color::green);
				checkers_white[i].set_fill_color(Graph_lib::Color::green);
			}
			for (int i{ 0 }; i < checkers_white.size(); ++i) {
				checkers_black[i].set_color(Graph_lib::Color::blue);
				checkers_black[i].set_fill_color(Graph_lib::Color::blue);
			}
		}
	public:
		Chess_board() {
			set_board();
			set_checkers();
			color();
		}

		void set_checkers() {
			for (int i{ 0 }; i < board.size(); ++i) {
				for (int j{ 0 }; j < board.size(); ++j) {
					if (i < 3 and (i % 2 != j % 2)) {
						Point temp{ board[i][j].point(0).x + board[i][j].height()/2, board[i][j].point(0).y + board[i][j].width()/2 };
						checkers_white.push_back(new Graph_lib::Circle{ temp, 20 });
					}
					if (i > 4 and (i % 2 != j % 2)) {
						Point temp{ board[i][j].point(0).x + board[i][j].height() / 2, board[i][j].point(0).y + board[i][j].width() / 2 };
						checkers_black.push_back(new Graph_lib::Circle{ temp, 20 });
					}
				}
			}
		}

		virtual void draw_lines() const override {
			for (int i{ 0 }; i < board.size(); ++i) {
				for (int j{ 0 }; j < board.size(); ++j) {
					board[i][j].draw_lines();
				}
			}
			for (int i{ 0 }; i < checkers_white.size(); ++i) {
				checkers_white[i].draw_lines();
			}
			for (int i{ 0 }; i < checkers_black.size(); ++i) {
				checkers_black[i].draw_lines();
			}
		}
	};
}