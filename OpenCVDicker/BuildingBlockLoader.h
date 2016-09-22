#pragma once
#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include "BuildingBlock.hpp"
class BuildingBlockLoader
{
public:
	BuildingBlockLoader();
	~BuildingBlockLoader();
	std::vector<BuildingBlock> loadBlocks(std::vector<std::string> filenames);
	std::vector<BuildingBlock> loadIcons();
private:
};

