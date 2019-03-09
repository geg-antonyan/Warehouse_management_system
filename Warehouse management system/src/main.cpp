#include "gui/Gui.h"

#include <QtWidgets/QApplication>

#include "customers/Stores.h"

#include "backend/AppObservers.h"
#include "backend/CommandDispatcher.h"
#include "backend/Command.h"

#include "warehouse/Warehouse.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Gui* gui = new Gui;
	CommandDispatcher cm(gui);
	gui->addObserver(UserInterface::CommandEntered, std::make_unique<CommandIssuedOB>(cm));
	registerUiObservers(gui);
	makeProductCatalog(gui);
	makeBoxesCatalog(gui);
	makeWarehouse(gui);
	registerStores(gui);
	commandReigister(gui);
	gui->execute(); 
	return a.exec();
}
