
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

const GLint WIDTH=800, HEIGH=600;

int main(void)
{



    if (!glfwInit()){
        printf("glfwInitError");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGH, "Simple example", NULL, NULL);
    if (!mainWindow)
    {
        printf("Error during mainWindow creation");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    int bufferHeight, bufferWidth;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
    glfwMakeContextCurrent(mainWindow);

//    glewExperimental = GL_TRUE;



//    if(!glewInit()) {
//        printf("glewInit error");
//        glfwDestroyWindow(mainWindow);
//        glfwTerminate();
//        return 1;
//    }
//
    glViewport(0,0, WIDTH,HEIGH);

    while(!glfwWindowShouldClose(mainWindow)){
        glfwPollEvents();

        glClearColor(1.0f,0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    exit(EXIT_SUCCESS);
}
 