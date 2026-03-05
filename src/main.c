#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

VkInstance instance;

void
createInstance(void)
{
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    if(vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS)
    {
        printf("Failed to create instance\n");
        exit(EXIT_FAILURE);
    }
}

GLFWwindow *window;

void
initWindow(void)
{
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

    vkDestroyInstance(instance, NULL);
}

int
main()
{
    // INIT
    initVulkan();
    initWindow();

    glfwShowWindow(window);

    mainLoop();

    // CLEANUP
    cleanup();

    return EXIT_SUCCESS;
}
