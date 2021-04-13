#include "../../GUI-lib/std_lib_facilities.h"
#include "../../GUI-lib/Graph.h"
#include "../../GUI-lib/Simple_window.h"

int main()
try {
    Point topLeftCorner {100, 100};
    Simple_window win {topLeftCorner, 800, 1000, "My Window"};
    win.wait_for_button();

    //--------------------------
    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);
    win.wait_for_button();

    //------------------------------
    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

    win.wait_for_button();

    //------------------------------
    Image cropped {Point{0,300}, "cropped.jpg"};
    Image cropped2 {Point{300,600}, "cropped.jpg"};
    Image cropped3 {Point{500,100}, "cropped.jpg"};

    win.attach(cropped);
    win.attach(cropped2);
    win.attach(cropped3);
    win.wait_for_button();

    //---------------------------------
    Image cropped100 {Point{0,0}, "cropped100.jpg"};
    win.attach(cropped100);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cropped100.move(100, 0);
            win.wait_for_button();
        }
        cropped100.move(-700, 100);
        win.wait_for_button();
    }

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