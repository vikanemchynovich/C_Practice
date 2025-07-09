#include<iostream>
#include<fstream>
using namespace std;

struct color { unsigned char r; unsigned char g; unsigned char b; };

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream fff("1.bmp", ios::binary);
    ofstream ggg("rez.bmp", ios::binary);
    if (!fff) { cout << "No file 1.bmp. Can't open\n"; exit(1); }
    if (!ggg) { cout << "   file rez.bmp. Can't create\n"; exit(1); }

    char buf[100];
    color bg, rect;
    int w, h;

    fff.read((char*)&buf, 18);
    ggg.write((char*)&buf, 18);
    fff.read((char*)&w, 4); cout << "w=" << w;
    fff.read((char*)&w, 4); cout << ", h=" << w;
    w = 256; ggg.write((char*)&w, 4);
    h = 256; ggg.write((char*)&h, 4);
    fff.read((char*)&buf, 28);
    ggg.write((char*)&buf, 28);

    cout << "\nbackground color\n";
    int cr, cg, cb;
    cin >> cb;
    cin >> cg;
    cin >> cr;

    bg.r = cr; bg.g = cg; bg.b = cb;
    cout << "\nfigure color\n";

    cin >> cb;
    cin >> cg;
    cin >> cr;

    rect.r = cr; rect.g = cg; rect.b = cb;
    int point_x, point_y, size_width, size_height;
    cout << "\npoint coordinate(x, y)\n";
    cin >> point_x;
    cin >> point_y;
    cout << "\nsize of figure(width, height)\n";
    cin >> size_width;
    cin >> size_height;

    for (int cartesian_y = 0; cartesian_y < h; ++cartesian_y) {
        for (int cartesian_x = 0; cartesian_x < w; ++cartesian_x) {
            if (cartesian_x >= point_x &&
                cartesian_x < point_x + size_width &&
                cartesian_y >= point_y &&
                cartesian_y < point_y + size_height) {
                ggg.write((char*)&rect, sizeof(rect));
            }
            else {
                ggg.write((char*)&bg, sizeof(bg));
            }
        }
    }

    fff.close();
    ggg.close();
    cout << "Image created successfully!\n";
    return 0;
}