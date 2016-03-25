#pragma once
#include "../types/program_shader.h"

#include <oglplus/uniform.hpp>
#include <oglplus/interop/glm.hpp>

class VoxelizationProgram : public ProgramShader
{
    protected:
        struct UniformMaterial
        {
            oglplus::Uniform<glm::vec3> diffuse;
        };
        struct UniformMatrices
        {
            oglplus::Uniform<glm::mat4> model;
        };
    public:
        UniformMatrices matrices;
        UniformMaterial material;
        oglplus::UniformSampler diffuseMap;
        oglplus::Uniform<unsigned int> volumeDimension;
        std::array<oglplus::Uniform<glm::mat4>, 3> viewProjections;

        void ExtractUniforms() override;

        VoxelizationProgram() = default;
        virtual ~VoxelizationProgram();
};
