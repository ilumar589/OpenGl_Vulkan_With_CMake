//
// Created by eduard.parvu on 4/22/2020.
//

#ifndef OPENGLANDVULKANPLAYGROUND_GPU_DATA_HPP
#define OPENGLANDVULKANPLAYGROUND_GPU_DATA_HPP

namespace GpuData {

    class BasicGpuData {
    public:
        virtual unsigned int& get_vertex_buffer_object() noexcept ;

    protected:
        unsigned int m_vertex_buffer_object{};
    };


    class TriangleGpuData : public BasicGpuData {
    public:
        explicit TriangleGpuData(const float* triangle_data,size_t triangle_data_size, unsigned int & vertex_array_object) noexcept;
    };

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
}

#endif //OPENGLANDVULKANPLAYGROUND_GPU_DATA_HPP
