#include "Controller.h"
#include <iostream>
#include <memory>


GraphController::GraphController(std::unique_ptr<View> view, std::unique_ptr<Doc> doc)
{
	pView = std::move(view);
	pDoc = std::move(doc);
	doMenuAction();
}

void GraphController::Import(const std::string& path, std::unique_ptr<Doc> doc)
{
	myPath = path;
	pDoc = std::move(doc);
}

void GraphController::Export(const std::string& path, std::unique_ptr<Doc> doc)
{
	myPath = path;
	pDoc = std::move(doc);
}


void GraphController::doMenuAction()
{
	// show menu for user
	pView->showMenu();
	
	// user menu item request
	int nItem = pView->getMenuItem();

	switch (nItem)
	{
	case 1:
	{
		std::unique_ptr<Doc> DocPtr{ std::make_unique<Doc>() };
		pDoc = std::move(DocPtr);
		std::cout << "Create a new document" << std::endl;
		break;
	}
	case 2:
	{
		this->Import(pView->setPath(), std::move(pDoc));
		std::cout << "Import a document" << std::endl;
		break;
	}
	case 3:
	{
		this->Export(pView->setPath(), std::move(pDoc));
		std::cout << "Export a document" << std::endl;
		break;
	}
	case 4:
	{
		Point2D point = pView->getPoint();
		Figure fig(point);
		pDoc->save(fig);
		std::cout << "Create a figure in doc" << std::endl;
		break;
	}
	case 5:
	{	
		Point2D point = pView->getPoint();
		auto figure = pView->getFigure(point);
		pDoc->remove(figure);
		std::cout << "Remove a figure from doc" << std::endl;
		break;
	}
	}

	// update view
	pView->showDoc(std::move(pDoc));
	std::cout << std::endl;
}
