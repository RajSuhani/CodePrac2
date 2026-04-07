#include <bits/stdc++.h>
using namespace std;

class Robot {
public:
    int w, h;
    int x, y;
    int dir;   
    int perimeter;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        perimeter = 2 * (w + h) - 4;
    }

    void step(int num) {
        num %= perimeter;

        if(num == 0 && x == 0 && y == 0) {
            dir = 3; 
            return;
        }

        while(num > 0) {
            if(dir == 0) {   
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if(num > 0) dir = 1;
            }
            else if(dir == 1) {   
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if(num > 0) dir = 2;
            }
            else if(dir == 2) {   
                int move = min(num, x);
                x -= move;
                num -= move;
                if(num > 0) dir = 3;
            }
            else {   
                int move = min(num, y);
                y -= move;
                num -= move;
                if(num > 0) dir = 0;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if(dir == 0) return "East";
        if(dir == 1) return "North";
        if(dir == 2) return "West";
        return "South";
    }
};

int main() {
    Robot robot(6, 3);

    robot.step(2);
    robot.step(2);

    vector<int> pos = robot.getPos();
    cout << "Position: " << pos[0] << " " << pos[1] << endl;
    cout << "Direction: " << robot.getDir() << endl;

    robot.step(2);
    robot.step(1);
    robot.step(4);

    pos = robot.getPos();
    cout << "Position: " << pos[0] << " " << pos[1] << endl;
    cout << "Direction: " << robot.getDir() << endl;

    return 0;
}