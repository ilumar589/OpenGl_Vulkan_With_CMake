//
// Created by eduard.parvu on 4/22/2020.
//

#ifndef OPENGLANDVULKANPLAYGROUND_GPU_DATA_HPP
#define OPENGLANDVULKANPLAYGROUND_GPU_DATA_HPP

#include <array>

namespace GpuData {

    class BasicGpuData {
    public:
        virtual unsigned int& get_vertex_array_object() noexcept ;

    protected:
        unsigned int m_vertex_array_object{};
    };


    class TriangleGpuData : public BasicGpuData {
    public:
        explicit TriangleGpuData(std::array<float,9> data) noexcept;
    };

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
}

#endif //OPENGLANDVULKANPLAYGROUND_GPU_DATA_HPP
