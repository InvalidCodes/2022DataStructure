#include"LinkList.h"

int main() {
	int choice = 1;
	OrdLinkList<int> list;
	int l, e;

	while (choice != 0) {
		cout << endl << "******* Hurry up and check me! ***************" ;
		cout << endl << "******* 1. Create a LinkList(InsertSort) *****" ;
		cout << endl << "******* 2. Display LinkList ******************";
		cout << endl << "******* 3. QuickSort *************************" ;
		cout << endl << "******* 4. Insert an element *****************" ;
		cout << endl << "******* 5. Delete an element *****************" ;
		cout << endl << "******* 0. Quit ******************************" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Please enter the array (enter 0 to end typing): ";
			cin >> l;
			while (l != 0) {
				list.Insert(l);
				cin >> l;
			}
			break;
		case 2:
			list.Display();
			break;
		case 3:
			list.QuickSort();
			list.Display();
			break;
		case 4:
			cout << "Please enter an element you want to insert: ";
			cin >> e;
			list.Insert(e);
			break;
		case 5:
			cout << "Please enter the element you want to delete: ";
			cin >> e;
			list.Delete(e);
			break;
		}
	}
	system("pause");
	return 0;
	

}