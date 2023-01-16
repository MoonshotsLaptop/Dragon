#pragma once

typedef enum DgResult {
	DG_SUCCESS = DG_TRUE,
	// Dragon errors that dragon throws
	DG_ENGINE_NOT_INITIALIZED,
	DG_ARGUMENT_IS_NULL,
	DG_SHADER_SOURCE_NOT_FOUND,
	// Warnings that are potentially unoptimal / could turn into errors if not dealt with
	DG_VK_EXTENSION_ALREADY_ADDED,
	DG_VK_VALIDATION_LAYER_ALREADY_ADDED,
	// Vulkan errors that dragon responds to
	DG_VK_EXTENSION_NOT_FOUND,
	DG_NO_VK_PHYSICAL_DEVICES_FOUND,
	DG_NO_GRAPHICS_QUEUE_FOUND,
	DG_NO_VK_SURFACE_FORMATS_AVAILABLE,
	DG_NO_VK_PRESENT_MODES_AVAILABLE,
	DG_VK_VALIDATION_LAYER_NOT_FOUND,
	DG_IN_RELEASE_MODE,
	// Vulkan objects that failed to initialize throw these
	DG_VK_INSTANCE_CREATION_FAILED,
	DG_VK_DEBUG_UTILS_INSTANCE_CREATION_FAILED,
	DG_VK_DEVICE_CREATION_FAILED,
	DG_SHADER_MODULE_CREATION_FAILED,
	DG_VK_IMAGE_VIEW_CREATION_FAILED,
	DG_VK_SWAPCHAIN_CREATION_FAILED,
	DG_VK_PIPELINE_CREATION_FAILED,
	DG_VK_RENDER_PASS_CREATION_FAILED,
	// GLFW fails and errors
	DG_GLFW_INITIALIZATION_FAILED,
	DG_GLFW_VULKAN_NOT_SUPPORTED,
	DG_GLFW_WINDOW_NULL_AFTER_CREATION,
	DG_GLFW_WINDOW_SURFACE_CREATION_FAILED,

	// General things
	DG_ERROR_UNKNOWN,
	DG_WARNING_UNKNOWN
} DgResult;