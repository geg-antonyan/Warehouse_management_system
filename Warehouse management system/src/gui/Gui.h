#ifndef GUI_H
#define GUI_H


#include <QtWidgets/QMainWindow>
#include <QTableWidget>
#include <QCloseEvent>
#include "ui_Gui.h"

#include "../utilites/UserInterface.h"

#include "Form.h"

#include <vector>

class Gui : public QMainWindow, public UserInterface
{
	Q_OBJECT
		
public:
	Gui(QWidget *parent = Q_NULLPTR);
	~Gui();
	void execute();
signals:
	
	void signalPost(QString);
	void signalError(QString);
	void signalTick();
	void signalProcess();

	void signalPrdCatalog();
	void signalBoxCatalog();
	void signalStoreRepos();
	void signalWarehouse();

	void signalStoreOrder();
	void signalCargoStore();
	void signaleExpiredPrd();
	void signalDiscountsRepos();
	void signalCargoWarehouse();
private slots:
	void closeEvent(QCloseEvent* _event);
	
	void on_btnActivateProcess_clicked();
	void on_btnDeactivateProcess_clicked();
	void on_btnStopGenOrders_clicked();
	void on_btnStopProcess_clicked();
	void on_btnSoldProducts_clicked();

	void on_btnStoreOrdBrowse_clicked();
	void on_btnCargoStoreBrowse_clicked();
	void on_btnCargoWarehouseBrowse_clicked();
	void on_btnRackBrowse_clicked();
	
	void on_btnExecDiscount_clicked();
	void on_btnRemoveDiscount_clicked();
	void on_btnChangeDisclount_clicked();
	
	void on_btnRemoveCargoStore_clicked();
	void on_btnRemoveCargoWarehouse_clicked();

	void on_btnConfCargoStore_clicked();
	void on_btnConfCargoWarehouse_clicked();


	void nextWindow();
	void prewWindow();
	void execCommand(QString& _cmd);

	void showErrorMessage(QString);
	void showPostMessage(QString);

	void changeTime();

	void UpdatePrdCatalog();
	void UpdateBoxCatalog();
	void UpdateStoreRepos();
	void UpdateWarehouse();

	void UpdateStoreOrdRepos();
	void UpdateCargoStoresRepos();
	void UpdateExpiredPrd();
	void UpdateDiscountsRepos();
	void UpdateCargoWarehouseRepos();

	void StartProcess();

private:
	void errorMessage(const std::string& m) override;
	void postMessage(const std::string& m) override;

	void PrdCatalogUpdate() override;
	void BoxCatalogUpdate() override;
	void StoresReposUpdate() override;
	void WarehouseUpdate() override;

	void StoreOrdersReposUpdate() override;
	void CargoStoreReposUpdate() override;
	void ExpieredPrdUpdate() override;
	void DiscountsReposUpdate() override;
	void CargoWarehouseReposUpdate() override;

	void tick() override;
	void processStart() override;

	Ui::GuiClass ui;
	bool startProcess;
	QTableWidget* table;

	std::vector<Form*> windows_;
	size_t winIndex_;
};




#endif // !GUI_H

