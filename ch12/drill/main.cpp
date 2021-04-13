#include "../../GUI-lib/std_lib_facilities.h"
#include "../../GUI-lib/Graph.h"
#include "../../GUI-lib/Simple_window.h"

int main()
try {

    Point topLeftCorner {100, 100};
    Simple_window win {topLeftCorner, 600, 400, "My window"};

    // 12.7.3 Axis
    Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa);
    win.set_label("Canvas #2");
    win.wait_for_button();
    win.wait_for_button();

    Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
    ya.set_color(Color::blue);
    ya.label.set_color(Color::green);
    win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();

    // 12.7.4 Function
    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};  // sine curve
        // plot sin() in the range [0:100) with (0,0) at (20,150)
        // using 1000 points; scale x values*50, scale y values*50
    sine.set_color(Color::magenta);

    win.attach(sine);
    win.set_label("Canvas #4");
    win.wait_for_button();

    // 12.7.5 Polygon
    sine.set_color(Color::blue);

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.add(Point{350,300});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("Canvas #5");
    win.wait_for_button();

    // 12.7.6 Rectangle
    Rectangle r {Point{200, 200}, 100, 50}; // top left corner, width, height
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 90});
    win.attach(poly_rect);

    win.set_label("Canvas #6");
    win.wait_for_button();

    // 12.7.7 Fill
    r.set_fill_color(Color::yellow);    // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dashdotdot, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Canvas #7");
    win.wait_for_button();

    // 12.7.8
    Text t {Point{150, 150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("Canvas #8");
    win.wait_for_button();

    t.set_font(Font::times_bold);
    t.set_color(Color::yellow);
    t.set_font_size(20);
    win.set_label("Canvas #9");
    win.wait_for_button();

    // 12.7.9 Images
    Image ii {Point{100, 50}, "./kacsa.jpg"};
    win.attach(ii);
    win.set_label("Canvas #10");
    win.wait_for_button();

    ii.move(100, 200);
    win.set_label("Canvas #11");
    win.wait_for_button();

    // More
    Circle c {Point{200, 200}, 50};
    Ellipse e {Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m {Point{100, 200}, 'x'};
    Mark m2 {Point{200, 200}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100, 20}, oss.str()};

    Image cal {Point{225, 225}, "kacsa.jpg"};
    cal.set_mask(Point{40, 40}, 200, 150);

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");
    win.wait_for_button();


    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
} 
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}