#include "ex_10.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

void ex_10() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_10" };
	win.color(Graph_lib::Color::white);
	
	Graph_lib::Rectangle r1{ Point{30,40}, 100, 30 };
	r1.set_color(Graph_lib::Color::black);
	win.attach(r1);
	Graph_lib::Text t1{ Point {50, 57}, "Point.h" };
	t1.set_color(Graph_lib::Color::black);
	win.attach(t1);

	Graph_lib::Rectangle r2{ Point{30,200}, 160, 70 };
	r2.set_color(Graph_lib::Color::black);
	win.attach(r2);
	Graph_lib::Text t2{ Point {75, 238}, "Graph.h" };
	t2.set_color(Graph_lib::Color::black);
	win.attach(t2);

	Graph_lib::Rectangle r3{ Point{10,350}, 100, 30 };
	r3.set_color(Graph_lib::Color::black);
	win.attach(r3);
	Graph_lib::Text t3{ Point {25, 370}, "Graph.cpp" };
	t3.set_color(Graph_lib::Color::black);
	win.attach(t3);

	Graph_lib::Rectangle r4{ Point{150,300}, 100, 30 };
	r4.set_color(Graph_lib::Color::black);
	win.attach(r4);
	Graph_lib::Text t4{ Point {160, 319}, "Window.cpp" };
	t4.set_color(Graph_lib::Color::black);
	win.attach(t4);

	Graph_lib::Rectangle r5{ Point{180,370}, 160, 70 };
	r5.set_color(Graph_lib::Color::black);
	win.attach(r5);
	Graph_lib::Text t5{ Point {205, 410}, "Simple_window.h" };
	t5.set_color(Graph_lib::Color::black);
	win.attach(t5);

	Graph_lib::Rectangle r6{ Point{90,480}, 160, 70 };
	r6.set_color(Graph_lib::Color::black);
	win.attach(r6);
	Graph_lib::Text t6{ Point {125, 520}, "chapter12.cpp" };
	t6.set_color(Graph_lib::Color::black);
	win.attach(t6);

	Graph_lib::Rectangle r7{ Point{310,170}, 160, 70 };
	r7.set_color(Graph_lib::Color::black);
	win.attach(r7);
	Graph_lib::Text t7{ Point {355, 210}, "Window.h" };
	t7.set_color(Graph_lib::Color::black);
	win.attach(t7);

	Graph_lib::Rectangle r8{ Point{390,265}, 160, 70 };
	r8.set_color(Graph_lib::Color::black);
	win.attach(r8);
	Graph_lib::Text t8{ Point {445, 305}, "GUI.h" };
	t8.set_color(Graph_lib::Color::black);
	win.attach(t8);

	Graph_lib::Rectangle r9{ Point{390,360}, 100, 30 };
	r9.set_color(Graph_lib::Color::black);
	win.attach(r9);
	Graph_lib::Text t9{ Point {415, 379}, "GUI.cpp" };
	t9.set_color(Graph_lib::Color::black);
	win.attach(t9);

	Graph_lib::Rectangle r10{ Point{420,60}, 100, 30 };
	r10.set_color(Graph_lib::Color::black);
	win.attach(r10);
	Graph_lib::Text t10{ Point {440, 80}, "FLTK" };
	t10.set_color(Graph_lib::Color::black);
	win.attach(t10);

	Graph_lib::Rectangle r11{ Point{230,40}, 100, 30 };
	r11.set_color(Graph_lib::Color::black);
	win.attach(r11);
	Graph_lib::Text t11{ Point {247, 57}, "Headers" };
	t11.set_color(Graph_lib::Color::black);
	win.attach(t11);

	Graph_lib::Line l1{ Point{80,70}, Point{110,200} };
	l1.set_color(Graph_lib::Color::black);
	win.attach(l1);

	Graph_lib::Line l2{ Point{110,200}, Point{470, 90} };
	l2.set_color(Graph_lib::Color::black);
	win.attach(l2);

	Graph_lib::Line l3{ Point{80,70}, Point{390,170} };
	l3.set_color(Graph_lib::Color::black);
	win.attach(l3);

	Graph_lib::Line l4{ Point{390,170}, Point{280,70} };
	l4.set_color(Graph_lib::Color::black);
	win.attach(l4);

	Graph_lib::Line l5{ Point{330, 55}, Point{420,75} };
	l5.set_color(Graph_lib::Color::black);
	win.attach(l5);

	Graph_lib::Line l6{ Point{200,300}, Point{390,240} };
	l6.set_color(Graph_lib::Color::black);
	win.attach(l6);

	Graph_lib::Line l7{ Point{390,240}, Point{470, 265} };
	l7.set_color(Graph_lib::Color::black);
	win.attach(l7);

	Graph_lib::Line l8{ Point{390,240}, Point{260,370} };
	l8.set_color(Graph_lib::Color::black);
	win.attach(l8);

	Graph_lib::Line l9{ Point{470, 333}, Point{440, 360} };
	l9.set_color(Graph_lib::Color::black);
	win.attach(l9);

	Graph_lib::Line l10{ Point{170,480}, Point{260,440} };
	l10.set_color(Graph_lib::Color::black);
	win.attach(l10);

	Graph_lib::Line l11{ Point{170,480}, Point{110,270} };
	l11.set_color(Graph_lib::Color::black);
	win.attach(l11);

	Graph_lib::Line l12{ Point{60,350}, Point{110,270} };
	l12.set_color(Graph_lib::Color::black);
	win.attach(l12);

	Graph_lib::Line l13{ Point{440, 240}, Point{470,265} };
	l13.set_color(Graph_lib::Color::black);
	win.attach(l13);

	Graph_lib::Line l14{ Point{400, 170}, Point{320, 70} };
	l14.set_color(Graph_lib::Color::black);
	win.attach(l14);

	win.wait_for_button();
}