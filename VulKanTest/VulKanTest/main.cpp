//
//  main.cpp
//  VulKanTest
//
//  Created by MinJu Jeong on 26/08/2019.
//  Copyright © 2019 MinJu Jeong. All rights reserved.
//

#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // initialize the VkInstanceCreateInfo structure
    VkInstanceCreateInfo inst_info = {};
    inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    
    VkInstance inst;
    VkResult res;
    
    res = vkCreateInstance(&inst_info, NULL, &inst);
    
    if (res == VK_ERROR_INCOMPATIBLE_DRIVER) {
        fprintf(stderr, "cannot find a compatible Vulkan ICD\n");
        exit(-1);
    }
    else if (res) {
        fprintf(stderr, "unknown error\n");
        exit(-1);
    }
    // else -> success
    printf("Hello Vulkan\n");
    
    vkDestroyInstance(inst, NULL);
    return 0;
}
