#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include <vector>

namespace myGraph_lib {
	class Chess_board : public Graph_lib::Shape {
	private:
		enum class side{ left, right };
		enum class team;

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

		void set_checkers() {
			for (int i{ 0 }; i < board.size(); ++i) {
				for (int j{ 0 }; j < board.size(); ++j) {
					if (i < 3 and (i % 2 != j % 2)) {
						Point temp{ board[i][j].point(0).x + board[i][j].height() / 2, board[i][j].point(0).y + board[i][j].width() / 2 };
						checkers_white.push_back(new Graph_lib::Circle{ temp, 20 });
					}
					if (i > 4 and (i % 2 != j % 2)) {
						Point temp{ board[i][j].point(0).x + board[i][j].height() / 2, board[i][j].point(0).y + board[i][j].width() / 2 };
						checkers_black.push_back(new Graph_lib::Circle{ temp, 20 });
					}
				}
			}
		}

		bool validation(side sid, team team, int i) {
			if (team == team::black) {
				if (sid == side::left and checkers_black[i].center().x == board[0][0].point(0).x + board[0][0].height() / 2) {
					return false;
				}
				else if (sid == side::right and checkers_black[i].center().x == board[0][b_size-1].point(0).x + board[0][b_size - 1].height() / 2) {
					return false;
				}
				else return true;
			}

			if (team == team::white) {
				if (sid == side::right and checkers_white[i].center().x == board[0][0].point(0).x + board[0][0].height() / 2) {
					return false;
				}
				else if (sid == side::left and checkers_white[i].center().x == board[0][b_size - 1].point(0).x + board[0][b_size - 1].height() / 2) {
					return false;
				}
				else return true;
			}
		}

	public:
		enum class team { black, white };

		Chess_board() {
			set_board();
			set_checkers();
			color();
		}

		void move_right_checker(team team, int i) {
			if (validation(side::right, team, i)) {
				if (team == team::white) {
					if (i < 0 or i > checkers_white.size() - 1) throw runtime_error("uncorrect checker");
					checkers_white[i].move(-50, 50);
				}
				else if (team == team::black) {
					if (i < 0 or i > checkers_black.size() - 1) throw runtime_error("uncorrect checker");
					checkers_black[i].move(50, -50);
				}
				else throw runtime_error("uncorrect team");
			}
			else return;
		}

		void move_left_checker(team team, int i) {
			if (validation(side::left, team, i)) {
				if (team == team::white) {
					if (i < 0 or i > checkers_white.size() - 1) throw runtime_error("uncorrect checker");
					checkers_white[i].move(50, 50);
				}
				else if (team == team::black) {
					if (i < 0 or i > checkers_black.size() - 1) throw runtime_error("uncorrect checker");
					checkers_black[i].move(-50, -50);
				}
				else throw runtime_error("uncorrect team");
			}
			else return;
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