#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

bool start = true;
string srchNAME;
int ID, editID, Menu, srchID, srchPRC;

//Products function, of type structure.
struct Product{
	int id;
	string name;
	float price;
};

//Initializing vector for product function with DB as a variable name.
vector <Product> DB;

//fuction to add products.
void AddProduct(){
	Product addnew;
	addnew.id = ID;
	cin >> addnew.name;
	cin >> addnew.price;
	DB.push_back(addnew);
	ID++;
	cout << "Product added sucessfully" << endl;
}

//function for editing entered products.
void EditProduct(int ID){
	int option = 0;
//looping.
	for (vector<Product>::iterator begin = DB.begin();
		begin != DB.end();
		begin++)
	{
		if ((begin->id) == ID)
		{
			cout<< "Enter an option to edit\n"
				<< "1. Name \n"
				<< "2. Price " << endl;
			cin >> option;

			switch (option)
			{
			case 1:
			{ cout << "Enter the new Name: " << endl;
			cin >> (begin)->name;
			cout << "Product Renamed succesfully! " << endl ;
			return;}
			case 2:
			{ cout << "Enter the new Price: " << endl;
			cin >> (begin)->price;
			cout << "Product Price updated succesfully! " << endl ;
			return;}
			}
		}
	}
	cout << "The Entered product not found!!" << endl;
	return;
}

//Function to display the databse to console.
void DisplayTheDatabase(){
	for (vector<Product> ::iterator DBase = DB.begin();
	     DBase != DB.end();
		 DBase++){
		cout << "ID: " << (DBase)->id << endl;
		cout << "Name: " << (DBase)->name << endl;
		cout << "Price: " << (DBase)->price << endl;
	    }
	if (DB.empty()){ 
	    cout << "No Product Found! " << endl; 
	    return;
	    }
}

//function to search a product in the vector.
void SearchingProduct(){
	int ProdSearch;
	cout<< "Search with: " << endl
	    << "1. ID: " << endl
		<< "2. Name: " << endl
		<< "3. Price: " << endl;
	cin >> ProdSearch;

//Switching between specification of product.
//For each 'case' the for loop will loop throgh the
//vector to find the matching specification of the 
//product and will print the matching specifications to console.
	switch (ProdSearch){
	case 1: {
	    cout << "Enter ID: " << endl;
		cin >> srchID;
		for (vector<Product>::iterator IDsearch = DB.begin();
			IDsearch != DB.end();
			IDsearch++)
		{
			if ((IDsearch->id) == srchID){
				cout << "ID: " << (IDsearch)->id << endl;
				cout << "Name: " << (IDsearch)->name << endl;
				cout << "Price: " << (IDsearch)->price << endl;
				return;
			}
		}return; }

	case 2: {	cout << "Enter Name: " << endl;
		        cin >> srchNAME;
		for (vector<Product>::iterator Namesearch = DB.begin();
			Namesearch != DB.end();
			Namesearch++)
		{
			if ((Namesearch->name) == srchNAME)
			{
				cout << "ID: " << (Namesearch)->id << endl;
				cout << "Name: " << (Namesearch)->name << endl;
				cout << "Price: " << (Namesearch)->price << endl;
			}
		}return; } 

	case 3: {	cout << "Enter Price: " << endl;
		cin >> srchPRC;
		for (vector<Product>::iterator Pricesearch = DB.begin();
			Pricesearch != DB.end();
			Pricesearch++)
		{
			if ((Pricesearch->price) == srchPRC)
			{
				cout << "ID: " << (Pricesearch)->id << endl;
				cout << "Name: " << (Pricesearch)->name << endl;
				cout << "Price: " << (Pricesearch)->price << endl;
			}
		}
	   return; } }
}

int main()
{
	while (start)
	{//Asking user to choose between several operations.
		cout<< "PRODUCT DATABASE" << endl
			<< "1. Add new product." << endl
			<< "2. Edit product." << endl
			<< "3. View all Products " << endl
			<< "4. Search a product. " << endl
			<< "5. Exit Program" << endl;
//Capturing the entered value and using switch statements to
//pass the value to the appropriate function.
		cin >> Menu;
		switch (Menu){
		case 1: { 
		cout <<"Enter the Name and Price of the product: " << endl;
		AddProduct();
		break; 
		}
		case 2: {
		cout <<"Which product 'ID' do you want to edit?" << endl;
		cin >> editID;
		EditProduct(editID);
		break;
		}
		case 3: {
		DisplayTheDatabase();
		break;
		}
		case 4: {
		SearchingProduct();
		break;
		}
		case 5: {start = false;
		return 0;
		}
      }
		cout << endl;
    }
	system("pause");
	return 0;
}
