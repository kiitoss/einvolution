#if !defined(WINDOW)
#define WINDOW

#include <stdbool.h>

#include "../geometry/position.h"
#include "./keyboard.h"
#include "./display.h"
#include "./mouse.h"

#define WIN_WIDTH 600
#define WIN_HEIGHT 600

#define WIN_X 80
#define WIN_Y 80

#define FPS 60


typedef enum {
    MENU,
    GAME, 
    FREE_MODE
} mode;

/**
 * @brief structure of the window
 * 
 */
typedef struct window {
    int height;
    int width;

    int center_x;
    int center_y;

    mode mode;
    
    mouse mouse;
    keyboard key;
} window;


// extern variable
extern window screen;
extern frustum frust;
extern camera cam;
extern world w;

/**
 * @brief Init the parameter of the menu screen
 * 
 */
void Init_Menu_Parameter();

/**
 * @brief Init the parameter of the Game screen
 * 
 */
void Init_Game_Parameter();

/**
 * @brief reshape the window with the good proportion
 * 
 * @param width 
 * @param height 
 */
void reshape(int width, int height);

/**
 * @brief Refresh the display periodically 
 * according to the FPS value (in window.h)
 * 
 * @param v 
 */
void Timer(int v);


#endif // WINDOW