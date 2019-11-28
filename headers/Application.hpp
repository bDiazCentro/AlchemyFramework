#ifndef APPLICATION_H
#define APPLICATION_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include "Object.hpp"
#include "Material.hpp"
#include "VulkanFunctions.hpp"
#include "FrameworkFunctions.hpp"

enum DisplayMode { NORMAL_RENDER, PARTICLE_RENDER };

struct AppSettings
{
	Color background_color;
	string name;
	int window_width, window_height;
	bool debug = false;
	int frameRate;
	DisplayMode display_mode;
	VkPolygonMode polygon_mode = VK_POLYGON_MODE_FILL;
	float lineWidth = 1.0f;
	VkCullModeFlagBits cull_mode = VK_CULL_MODE_BACK_BIT;
	int number_of_descriptors;
};

class Application
{
private:
	AppSettings app_settings;
#pragma region vulkan tutorial variables
	GLFWwindow* window;
	const std::vector<Vertex> vertices = {
		{ { -0.5f, -0.5f, 0.0f },{ 1.0f, 0.0f, 0.0f },{ 0.0f, 0.0f } },
		{ { 0.5f, -0.5f, 0.0f },{ 0.0f, 1.0f, 0.0f },{ 1.0f, 0.0f } },
		{ { 0.5f, 0.5f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 1.0f } },
		{ { -0.5f, 0.5f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } }/*,

		{ { -0.5f, -0.5f, -0.5f },{ 1.0f, 0.0f, 0.0f },{ 0.0f, 0.0f } },
		{ { 0.5f, -0.5f, -0.5f },{ 0.0f, 1.0f, 0.0f },{ 1.0f, 0.0f } },
		{ { 0.5f, 0.5f, -0.5f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 1.0f } },
		{ { -0.5f, 0.5f, -0.5f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } }*/
	};
	const std::vector<Vertex> vertices2 = {
		{ { 0.0f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f } },
		{ { 1.0f, -0.5f, -0.5f },{ 0.0f, 1.0f, 0.0f },{ 1.0f, 0.0f } },
		{ { 1.0f, 0.5f, -0.5f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 1.0f } },
		{ { 0.0f, 0.5f, -0.5f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } }
	
	};

	const std::vector<uint16_t> indices = {
		0, 1, 2, 2, 3, 0/*,
		4, 5, 6, 6, 7, 4*/
	};



	VkInstance instance;
	VkDebugReportCallbackEXT callback;
	VkSurfaceKHR surface;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;

	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkFramebuffer> swapChainFramebuffers;

	VkRenderPass renderPass;
	VkDescriptorSetLayout descriptorSetLayout;
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;

	VkCommandPool commandPool;

	VkImage depthImage;
	VkDeviceMemory depthImageMemory;
	VkImageView depthImageView;

	VkImage textureImage;
	VkDeviceMemory textureImageMemory;
	VkImageView textureImageView;
	VkSampler textureSampler;

	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;
	VkBuffer vertexBuffer2;
	VkDeviceMemory vertexBufferMemory2;
	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;

	VkBuffer uniformBuffer;
	VkDeviceMemory uniformBufferMemory;
	VkBuffer uniformBuffer2;
	VkDeviceMemory uniformBufferMemory2;

	VkDescriptorPool descriptorPool;
	VkDescriptorSet descriptorSet;

	std::vector<VkCommandBuffer> commandBuffers;

	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;

#pragma endregion
	std::string applicationName = "";
	int window_width = 1024;
	int window_height = 768;
	bool up = false, down = false, left = false, right = false;
	float red = 0, green = 0.7, blue = 1.0;
public:
	Object *testObject = new Object("Bruno");
	Object *testObject2 = new Object("Diaz");
	Object *testObject3 = new Object("Martinez");
	Material *testMaterial = new Material("shaders/vert.spv", "shaders/frag.spv");
	Application();
	Application(int windowWidth, int windowHeight, std::string appName);
	Application(int windowWidth, int windowHeight);
	Application::Application(std::string appName);
	int WindowWidth();
	int WindowHeight();
	std::string ApplicationName();
	void AppSetup();
	void Setup();
	void Update();
	void UpdateActualCameraPosition();

#pragma region vulkan tutorial Functions
	void Run();
private:
	void InitWindow(int width, int height);
	void InitVulkan();
	void MainLoop();
	static void OnWindowResized(GLFWwindow* window, int width, int height);
	void RecreateSwapChain();
	void CreateInstance();
	void SetupDebugCallback();
	void CreateSurface();
	void PickPhysicalDevice();
	void CreateLogicalDevice();
	void CreateSwapChain();
	void CreateImageViews();
	void CreateRenderPass();
	void CreateDescriptorSetLayout();
	void CreateGraphicsPipeline();
	void CreateFramebuffers();
	void CreateCommandPool();
	void CreateDepthResources();
	VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
	VkFormat findDepthFormat();
	void CreateTextureImage(const char *filename, Sprites &sp);
	void CreateTextureImageView(Sprites &sp);
	void CreateTextureSampler();
	VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);
	void createImage(uint32_t width, uint32_t height,
		VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties,
		VkImage& image, VkDeviceMemory& imageMemory);
	void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
	void CopyImage(VkImage srcImage, VkImage dstImage, uint32_t width, uint32_t height);
	void CreateVertexBuffer();
	void CreateIndexBuffer();
	void CreateUniformBuffer(Object *obj);
	void CreateDescriptorPool();
	void CreateDescriptorSet(Object *obj);
	void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
		VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	VkCommandBuffer BeginSingleTimeCommands();
	void EndSingleTimeCommands(VkCommandBuffer commandBuffer);
	void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
	void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
	uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	void CreateCommandBuffers();
	void CreateSemaphores();
	void UpdateUniformBuffer();
	void DrawFrame();
	VkShaderModule createShaderModule(const std::vector<char>& code);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	bool IsDeviceSuitable(VkPhysicalDevice device);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	std::vector<const char*> getRequiredExtensions();
	bool checkValidationLayerSupport();
	static std::vector<char> readFile(const std::string& filename);
	void cleanup();
	static VKAPI_ATTR VkBool32 VKAPI_CALL Application::debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, 
		uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData);
	void cleanupSwapChain();
	bool hasStencilComponent(VkFormat format);
	Sprites LoadImageToAssetsManager(const char *filepath);
	void BackgroundColor(Color bg_color);
	void BackgroundColor(float r, float g, float b);

#pragma endregion
};



#endif // !APPLICATION_H