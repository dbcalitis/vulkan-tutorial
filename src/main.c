#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

GLFWwindow *window;

void
initWindow(void)
{
    if(glfwInit() != GLFW_TRUE)
    {
        printf("GLFW initialization failed\n");
        exit(EXIT_FAILURE);
    }

    // DISPLAY SERVER
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(
            WIDTH, HEIGHT, "Vulkan Triangle", NULL, NULL);

    if(window == NULL)
    {
        printf("Window creation failed \n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

void
initVulkan(void)
{
}

void
mainLoop(void)
{
    printf("Main Loop Start!\n");
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}

void
cleanup(void)
{
    glfwDestroyWindow(window);

    glfwTerminate();
}

int
main()
{
    // INIT
    initVulkan();
    initWindow();

    glfwShowWindow(window);
    glfwSwapBuffers(window);

    mainLoop();

    // CLEANUP
    cleanup();

    return EXIT_SUCCESS;
}
