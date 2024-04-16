#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <sstream>
#include <iomanip>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char* IMAGE_FILE = "Sri_Yantra_Correct_Colors_Johari_1974.jpg";
int remainingTime = 90;

unsigned char* loadImage(const char* filename, int& width, int& height) {
    int channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);
    if (!data) {
        std::cout << "Failed to load image: " << filename << std::endl;
        return nullptr;
    }
    return data;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int width, height;
    unsigned char* imageData = loadImage(IMAGE_FILE, width, height);
    if (imageData) {
        // Calculate the aspect ratio of the image
        float aspectRatio = static_cast<float>(width) / height;

        // Calculate the viewport dimensions to maintain the aspect ratio
        int viewportWidth, viewportHeight;
        if (width > height) {
            viewportWidth = WINDOW_WIDTH;
            viewportHeight = static_cast<int>(WINDOW_WIDTH / aspectRatio);
        } else {
            viewportWidth = static_cast<int>(WINDOW_HEIGHT * aspectRatio);
            viewportHeight = WINDOW_HEIGHT;
        }

        // Calculate the position to center the image
        int viewportX = (WINDOW_WIDTH - viewportWidth) / 2;
        int viewportY = (WINDOW_HEIGHT - viewportHeight) / 2;

        // Set the viewport to center the image
        glViewport(viewportX, viewportY, viewportWidth, viewportHeight);

        // Set the raster position to the center of the image
        glRasterPos2f(viewportX / static_cast<float>(WINDOW_WIDTH) * 2.0f - 0.1f,
                      viewportY / static_cast<float>(WINDOW_HEIGHT) * 2.0f - 1.0f);

        // Draw the image
        glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, imageData);

        stbi_image_free(imageData);
    }

    // Draw the countdown timer
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << (remainingTime / 60) << ":"
       << std::setfill('0') << std::setw(2) << (remainingTime % 60);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(0.8f, -0.9f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>(ss.str().c_str()));

    glutSwapBuffers();
}

void timer(int value) {
    if (remainingTime > 0) {
        remainingTime--;
        glutPostRedisplay();
        glutTimerFunc(1000, timer, 0);
    }

    if (remainingTime == 0) {
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Image Viewer");

    glewInit();

    glutDisplayFunc(display);
    glutTimerFunc(1000, timer, 0);

    glutMainLoop();

    return 0;
}
