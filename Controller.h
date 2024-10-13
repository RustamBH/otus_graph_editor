#pragma once

#include "Model.h"
#include "View.h"
#include <string>


class GraphController
{
public:
    GraphController(std::unique_ptr<View> view, std::unique_ptr<Doc> doc);
    ~GraphController() {};

    void Import(const std::string& path, std::unique_ptr<Doc> doc);
    void Export(const std::string& path, std::unique_ptr<Doc> doc);
    void doMenuAction();

private:
    std::unique_ptr<View> pView;
    std::unique_ptr<Doc> pDoc;
    std::string myPath;
};
