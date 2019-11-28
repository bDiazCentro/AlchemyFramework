#include "Material.hpp"

Material::Material()
{
	vertShaderpath = "";
}

Material::Material(std::string vertPath, std::string fragPath)
{
	vertShaderpath = vertPath;
	fragShaderpath = fragPath;
}

void Material::VertShaderPath(std::string path)
{
	vertShaderpath = path;
}

std::string Material::VertShaderPath()
{
	return vertShaderpath;
}

void Material::FragShaderPath(std::string path)
{
	fragShaderpath = path;
}

std::string Material::FragShaderPath()
{
	return fragShaderpath;
}