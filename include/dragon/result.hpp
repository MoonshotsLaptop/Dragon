#pragma once

enum DgResult {
	// Success value. Always set to 0
	DG_SUCCESS = 0,
	// Status Values
#pragma region
#pragma endregion
	// Unoptimal Warnings
#pragma region
#pragma endregion
	// Potentially Code-Breaking Warnings
#pragma region
	DG_VK_EXTENSION_ALREADY_ADDED = 0x800,
	DG_VK_VALIDATION_LAYER_ALREADY_ADDED = 0x801,
	DG_IN_RELEASE_MODE = 0x802,
	DG_NO_GRAPHICS_QUEUE_FOUND = 0x803,
#pragma endregion
	// Fatal Errors
#pragma region
	DG_ENGINE_NOT_INITIALIZED = 0xF00,
	DG_ARGUMENT_IS_NULL = 0xF01,
	DG_SHADER_SOURCE_NOT_FOUND = 0xF02,
	DG_VK_EXTENSION_NOT_FOUND = 0xF03,
	DG_NO_VK_PHYSICAL_DEVICES_FOUND = 0xF04,
#pragma endregion

	DG_NO_VK_SURFACE_FORMATS_AVAILABLE,
	DG_VK_SURFACE_FORMAT_SELECTION_FAILED,
	DG_NO_VK_PRESENT_MODES_AVAILABLE,
	DG_VK_PRESENT_MODE_SELECTION_FAILED,
	DG_VK_VALIDATION_LAYER_NOT_FOUND,
	DG_VK_EXTENT_2D_SELECTION_FAILED,
	DG_VK_COMMAND_BUFFER_FAILED_RECORD_START,
	DG_VK_COMMAND_BUFFER_RECORD_FAILED,
	DG_VK_FENCE_WAIT_FAILED,
	DG_VK_GET_SWAPCHAIN_IMAGES_FAILED,
	DG_VK_ACQUIRE_NEXT_IMAGE_FAILED,
	DG_VK_QUEUE_PRESENT_FAILED,
	DG_VK_QUEUE_SUBMISSION_FAILED,
	DG_VK_INSTANCE_CREATION_FAILED,
	DG_VK_DEBUG_UTILS_INSTANCE_CREATION_FAILED,
	DG_VK_DEVICE_CREATION_FAILED,
	DG_VK_SHADER_MODULE_CREATION_FAILED,
	DG_VK_IMAGE_VIEW_CREATION_FAILED,
	DG_VK_SWAPCHAIN_CREATION_FAILED,
	DG_VK_PIPELINE_CREATION_FAILED,
	DG_VK_RENDER_PASS_CREATION_FAILED,
	DG_VK_GRAPHICS_PIPELINE_CREATION_FAILED,
	DG_VK_FRAMEBUFFER_CREATION_FAILED,
	DG_VK_COMMAND_POOL_CREATION_FAILED,
	DG_VK_COMMAND_BUFFER_CREATION_FAILED,
	DG_VK_SEMAPHORE_CREATION_FAILED,
	DG_VK_FENCE_CREATION_FAILED,
	DG_VK_VERTEX_BUFFER_CREATION_FAILED,
	DG_VK_MEMORY_ALLOCATION_FAILED,
	DG_GLFW_INITIALIZATION_FAILED,
	DG_GLFW_VULKAN_NOT_SUPPORTED,
	DG_GLFW_NO_INSTANCE_EXTENSIONS_FOUND,
	DG_GLFW_WINDOW_NULL_AFTER_CREATION,
	DG_GLFW_WINDOW_SURFACE_CREATION_FAILED,
	DG_WINDOW_INVALID,
	DG_MODEL_INVALID,
	DG_ERROR_UNKNOWN,
	DG_WARNING_UNKNOWN,
	DG_WEAK_PTR_LOCK_FAIL
};