// Rotating Ascii Cube
// Ethan Bliss
// October 2021

// Generates a rotating ascii (x) cube in a Windows terminal

#include <chrono>
#include <iostream>
#include <windows.h>
#include "cube.h"
#include "matrix.h"
#include "camera.h"

using namespace std;

const int width = 80;
const int height = 40;
//const double rotation[3] = {0.002, 0.003, 0.001};

// Clear h lines of console window
void clearWindow(int h)
{
    cout << "\r";
    for (int i = 0; i < h - 1; i++)
    {
        cout << "\33[2K\033[A";
    }
    cout << "\33[2K";
}

// Print out the contents of frame to stdout
void printFrame(char **frame, int w, int h)
{
    for (int i = 0; i < h; i++)
        fwrite(frame[i], w, 1, stdout);
}

// Allocate a w x h frame (2d array)
char **allocateFrame(int w, int h)
{
    char **frame = (char **)malloc(h * sizeof(char *));
    for (int i = 0; i < h; i++)
    {
        frame[i] = (char *)calloc(w, sizeof(char));
    }
    return frame;
}

// Free a frame (2d array) of height h
void destroyFrame(char **frame, int h)
{
    for (int i = 0; i < h; i++)
        free(frame[i]);
    free(frame);
}

int main()
{
    // Give console width and height
    string consoleConfig = "MODE CON COLS=" + to_string(width) + " LINES=" + to_string(height);
    system(consoleConfig.c_str());

    // Generate initial arrays
    char **frame = allocateFrame(width, height);
    //double **rotMatrix = createMatrix();

    Camera c = Camera(80, 40);

    auto startTime = chrono::system_clock::now();

    // Main loop (until escape is pressed)
    while (GetAsyncKeyState(VK_ESCAPE) == 0)
    {
        // Find elapsed time
        auto curTime = chrono::system_clock::now();
        auto diffTime = chrono::duration_cast<chrono::milliseconds>(curTime - startTime).count();
        startTime = curTime;
        long value_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count();
        // Rotate depending on time elapsed
        /*rotMatrix = rotationMatrix(rotMatrix,
                               rotation[0] * diffTime,
                               rotation[1] * diffTime,
                               rotation[2] * diffTime); */

        // Render & display
        c.draw_frame(frame, value_ms);
        printFrame(frame, width, height);

        // Wait to clear window so it is visible
        Sleep(5);
        clearWindow(height);
    }

    destroyFrame(frame, height);
    //destroyMatrix(rotMatrix);
    return EXIT_SUCCESS;
}