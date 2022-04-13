#include "../../../inc/systems/window/window.h"

/**
 * @brief Handle mouse events
 * 
 * @param x 
 * @param y 
 */
void Mouse(int x, int y) {
    
    screen.mouse.pos = set_position(x, y, 0);

    screen.mouse.dx = screen.center_x - get_x(screen.mouse.pos);
    screen.mouse.dy = screen.center_y - get_y(screen.mouse.pos);

    cam.yaw_angle = screen.mouse.dx / 1000.0;
    cam.pitch_angle = screen.mouse.dy / 1000.0;

    yaw(&cam, cam.yaw_angle);
    pitch(&cam, cam.pitch_angle);

    glutPostRedisplay();
}