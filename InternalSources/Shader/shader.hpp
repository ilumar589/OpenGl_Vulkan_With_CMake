//
// Created by Valar on 4/20/2020.
//

#ifndef OPENGLANDVULKANPLAYGROUND_SHADER_HPP
#define OPENGLANDVULKANPLAYGROUND_SHADER_HPP

#include <string>
#include <fstream>
#include <glad/glad.h>
#include <iostream>

namespace Shader {

    enum class ShaderType {
        VERTEX_SHADER,
        FRAGMENT_SHADER
    };



    class BasicShader {
    private:
        unsigned int m_vertex_handle;
        unsigned int m_fragment_handle;

        void log_shader_error(unsigned int shader_handle, ShaderType shader_type) noexcept {
            int success;
            char infoLog[512];

            glGetShaderiv(shader_handle, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader_handle, 512, nullptr, infoLog);

                std::string error_message{};
                switch (shader_type) {
                    case ShaderType::VERTEX_SHADER: {
                        error_message.append("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
                        error_message.shrink_to_fit();
                    }break;
                    case ShaderType::FRAGMENT_SHADER: {
                        error_message.append("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
                        error_message.shrink_to_fit();
                    }break;
                }
                std::cout << error_message.c_str() << infoLog << std::endl;
            }
        }

        std::string get_file_contents(const char* filename) noexcept {
            std::ifstream in{filename, std::ios::in | std::ios::binary};
            if (in) {
                std::string contents;
                in.seekg(0, std::ios::end);
                contents.resize(static_cast<unsigned long long int>(in.tellg()));
                in.seekg(0, std::ios::beg);
                in.read(&contents[0], static_cast<long long int>(contents.size()));
                in.close();
                return(contents);
            }

            return std::string {};
        }
    };
}

#endif //OPENGLANDVULKANPLAYGROUND_SHADER_HPP
