//
// Created by Valar on 4/25/2020.
//

#ifndef OPENGLANDVULKANPLAYGROUND_SHADER_HPP
#define OPENGLANDVULKANPLAYGROUND_SHADER_HPP

#include <string>

namespace Shader {

    enum class ShaderType {
        VERTEX_SHADER,
        FRAGMENT_SHADER
    };

    class BasicShader {
    public:
//      constructors
        BasicShader(const char* vertex_shader_full_path, const char* fragment_shader_full_path) noexcept;
        BasicShader ( const BasicShader & ) = delete;

//        overloaded operators
        BasicShader& operator= ( const BasicShader& ) = delete;

        unsigned int& get_shader_program_handle();

    private:
        unsigned int m_shader_program_handle;
        static void log_shader_program_error(unsigned int shader_program_handle) noexcept;
        static void log_shader_error(unsigned int shader_handle, ShaderType shader_type) noexcept;
        static std::string get_file_contents(const char* file_name_full_path) noexcept;
    };
}

#endif //OPENGLANDVULKANPLAYGROUND_SHADER_HPP
