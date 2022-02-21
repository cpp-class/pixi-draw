#include "raylib.h"
#include "pixiengine.hpp"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    int cur_sec {1};
    int max_sec {4};

    int op1 {8};
    int op2 {6};
    int op3 {2};
    int op4 {1};
    int option {0};

    InitWindow(screen_width, screen_height, "Pixi BitMap Draw");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    std::vector<unsigned char> block1 {
        1,1,1,1,
        1,0,0,1,
        1,0,0,1,
        1,1,1,1,
    };

    std::vector<unsigned char> block2 {
        1,0,0,0,0,1,
        0,1,0,0,1,0,
        0,0,1,1,0,0,
        0,0,1,1,0,0,
        0,1,0,0,1,0,
        1,0,0,0,0,1,
    };

    std::vector<unsigned char> block3 {
        1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,1,
        1,0,1,1,1,1,0,1,
        1,0,1,0,0,0,0,1,
        1,0,1,0,0,0,0,1,
        1,0,1,1,1,1,0,1,
        1,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,
    };

    std::vector<unsigned char> block4 {
        0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,0,
        1,0,0,1,0,0,1,0,
        0,0,0,1,0,0,0,0,
        0,0,0,1,0,0,0,0,
        0,0,0,1,0,0,0,0,
        0,0,0,1,0,0,0,0,
        0,0,1,1,1,0,0,0,
    };





    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyPressed(KEY_SPACE))
        {
            cur_sec++;
            if (cur_sec>max_sec)
            {
                cur_sec = 1;
            }
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            if (cur_sec == 1 && op1<16)
            {
                op1++;
            }

            if (cur_sec == 2 && op2<20)
            {
                op2++;
            }

            if (cur_sec == 3 && op3<2)
            {
                op3++;
            }

            if (cur_sec == 4 && op4<4)
            {
                op4++;
            }
        } else if (IsKeyPressed(KEY_LEFT))
        {
            if (cur_sec == 1 && op1>1)
            {
                op1--;
            }

            if (cur_sec == 2 && op2>1)
            {
                op2--;
            }

            if (cur_sec == 3 && op3>1)
            {
                op3--;
            }

            if (cur_sec == 4 && op4>1)
            {
                op4--;
            }

        }



        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (cur_sec == 1)
            {
                pixi::draw_bitmap(block3, 50, 50, 19, 1, op1, BLACK);
                option = op1;
            }

            if (cur_sec == 2)
            {
                pixi::draw_bitmap(block2, 50, 50, 25, 0, op2, RED);
                option = op2;
            }

            if (cur_sec == 3)
            {
                bool is_circle {op3==1};
                pixi::draw_bitmap(block1, 50, 50, 30, 2, 4, GREEN, is_circle);
                option = op3;
            }

            if (cur_sec == 4)
              {
                  bool is_circle {op4>2};
                  Color pixel_color = BLACK ;
                  Color back_color = Fade(RED, 0.3f);

                  if (op4%2==0)
                  {
                      pixel_color = BLUE;
                      back_color = Fade(GREEN, 0.3f);

                  }

                  pixi::draw_bitmap(block4, 50, 50, 30, 1, 8, pixel_color, back_color, is_circle);
                  option = op4;
              }

            DrawText(TextFormat("[%d/%d] Press space to toggle, Right/Left for options [%d]", cur_sec, max_sec, option), 10, screen_height - 40, 20, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
