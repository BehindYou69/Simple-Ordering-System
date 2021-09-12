#include <iostream> //for cin and cout
#include <string> //for string
#include <iomanip> //for getw()
#include <cctype> //for tolower()
#include <stdlib.h> //for clear screen
#include <ctime> //for current time
 
using namespace std; //for std::

int main(){
	//logo
	cout << "                             ***             ***       **********         ************** \n" <<
	        "                             ***             ***      ************        ************** \n" <<  
            "                             ***             ***     **          **       ***            \n" <<
		 	"                             ***             ***    **            **      ***            \n" <<
		 	"                             ***             ***   **              **     ***            \n" <<
		 	"                             ***             ***   **              **     ***            \n" <<
		 	"                             ***             ***    **            **      ***            \n" <<
		 	"                             ***             ***     **          **       ***            \n" <<
		 	"                             *******************      **        **        ************** \n" <<
		 	"                             *******************       **      **         ************** \n" <<
		 	"                             ***             ***        **    **                     *** \n" <<
		    "                             ***             ***         **  **                      *** \n" <<
		 	"                             ***             ***          ****                       *** \n" <<
		 	"                             ***             ***           **                        *** \n" <<
		 	"                             ***             ***          ****                       *** \n" <<
		 	"                             ***             ***         **  **                      *** \n" <<
		    "                             ***             ***         **   **           ************* \n" <<
		 	"                             ***             ***        **     **          ************* \n" <<endl; 
    
    char meal; //tpye of meal
    int amount;//amount of meal
    int x = 0; //customer number
    double tax = 0.10; //10% tax
    char nxtcustomer = 'y'; //for the customer number loop
   	int payment = 0; //pay by cash or card

    const string menu[5] = {"Nasi Lemak (N)", "Chicken Rice (C)", "Masala Dosa (M)", "Hamburger (H)", "Fish and Chips (F)"}; //menu array
    int quantity[5] ={0 ,0 ,0 ,0 ,0};  //amount of meal
    int price[5] = {9, 8, 6, 5, 12}; //price of meal

	// current date/time based on current system
   time_t start = time(0);     
   
   // convert now to string form
   char* sdt = ctime(&start);

   //starting time/date
   cout << "Start Time : " << sdt << endl; 
   cout << "-----------------------------------------" << endl;
 
 //loop for customer number
while(nxtcustomer == 'y'){

	//menu
	cout << "                       _________________________________________________________________________\n"<<
            "                      |                              H&S Restaurant 'MENU'                      |\n"<<
            "                      |_________________________________________________________________________|\n"<<
            "                      |Categories Of Meal  |              Description              | Prices(RM) |\n"<<
			"                      |Nasi Lemak     (N)  |A Malay cuisine Dish                   |  RM  9.00  |\n"<<
			"                      |Chicken Rice   (C)  |A Chinese Cuisine Dish                 |  RM  8.00  |\n"<<
			"                      |Masala Dosa    (M)  |A Indian Cuisine Dish                  |  RM  6.00  |\n"<<
			"                      |Hamburger      (H)  |Burger + a tasty Ham                   |  RM  5.00  |\n"<<
			"                      |Fish and Chips (F)  |Fish&Chips 'Popular western dish'      |  RM 12.00  |\n"<<
            "                      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"<<endl;

    //customer number
	cout << "Customer No : " << ++x << endl;
	cout << "-----------------" << endl;
	double total  = 0;  
   	double AmountPaid = 0; 

do{
   

	cout << "Type of Meal N, C, M, H, F (Other = payment): " ; 
    cin >> meal;
    meal = tolower(meal);
    
    
    if(meal == 'n' || meal == 'c' || meal == 'm' || meal == 'h' || meal == 'f'){
    cout << "Quantity : " ;
    

    while((!(cin >> amount)) || amount < 0){

    	cout << "Please Enter a valid number : ";
    	//clear the previous input
    	cin.clear();
    	//discard previous input
    	cin.ignore(123, '\n');

    }
    


   //selection of meal
	switch(meal){

		case 'n':
		quantity[0] += amount;
		total += (amount * 9);
		cout << "Meal Type N : " << amount << " @ RM9.00 = " << fixed << setprecision(2) <<  amount * 9  << "\n" << endl;
		break;

		case 'c':
		quantity[1]+= amount;
		total += (amount * 8);
		cout << "Meal Type C : " << amount << " @ RM8.00 = " << fixed << setprecision(2) << amount * 8 << "\n" << endl;
		break;

		case 'm':
		quantity[2]+= amount;
		total += amount * 6;
		cout << "Meal Type M : " << amount << " @ RM6.00 = " << fixed << setprecision(2) << amount * 6 << "\n" <<  endl;
		break;

		case 'h':
		quantity[3]+= amount;
		total += amount * 5;
		cout << "Meal Type H : " << amount << " @ RM5.00 = " << fixed << setprecision(2) << amount * 5 << "\n" << endl;
		break;

		case 'f':
		quantity[4]+= amount;
		total += amount * 12;
		cout << "Meal Type F : " << amount << " @ RM12.00 = " << fixed << setprecision(2) << amount * 12 << "\n" << endl;
		break;
	} 
	
	//payment
}else if (meal != 'n' || meal != 'c' || meal != 'm' || meal != 'h' || meal != 'f'){
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
		cout << "\nMeal Charges = RM " << total << endl;
		cout << "Add 10% SST  = RM " << total * tax  << endl; 
		cout << "------------------------------" << endl;
		cout << "TOTAL TO PAY = RM " << (total* tax) + total << endl;
		cout << "------------------------------" << endl;
		cout << "Pay by Cash or Card (1/2) : " ;
		

while((!(cin >> payment)) || (payment < 1) || (payment > 2)){
	cout << "Type A Valid Payment Value : ";
	cin.clear();
	cin.ignore(123, '\n');


}

	if(payment == 2){
		cout << "Amount paid  = RM " << (total* tax) + total << endl;
		cout << "Payment Method : Card" << endl;
		cout << "\nThank you for choosing 'H&S Restaurant'." << endl;
		cout << "Each one of your orders is important to us and we truly appreciate you being a repeat customer." << endl;
		cout << "Thank you for remaining a valued customer." << endl;
		cout << "Your loyalty allows us to continue to grow as a business." << endl;
		cout << "Have A Nice Day!!!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	}else if(payment == 1){
	do{
		cout << "Amount paid  = RM ";
		cin >> AmountPaid;
		if(AmountPaid < (total* tax) + total){
			cout << "AmountPaid Not Enough,Please Try Again!" << endl;
		}
	}while(AmountPaid < (total* tax) + total);
		cout << "Change Due   = RM " << AmountPaid - ((total * tax ) + total) << endl;
		cout << "Payment Method : Cash" << endl;
		cout << "\nTHANK YOU FOR CHOOSING OUR RESTAURANT!!!" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		
	}

		}
			 
 
		//nxt customer or no
 }while(meal == 'n' || meal == 'c' || meal == 'm' || meal == 'h' || meal == 'f');

 	 cout << "\nNext customer (Y=yes or N=no) : ";
 	 cin >> nxtcustomer;
 	 cin.clear();
 	 cin.ignore(123,'\n');
 	 nxtcustomer = tolower(nxtcustomer);
 	 while(nxtcustomer != 'y' && nxtcustomer != 'n'){
 	 	 cout << "Input (Y/N) Only,(Y=yes or N=no) : ";
 	 	 cin >> nxtcustomer;
 	 	 cin.clear();
 	 	 cin.ignore(123,'\n');
 		 nxtcustomer = tolower(nxtcustomer);
 	 }
}
system("CLS"); //clear screen
	int totalquantity = 0;
	int totalsales = 0;

	//sales report
	cout << "Daily Meal Sales Report" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Total Number of Customers = " << x << endl;

	cout << "___________________________________________________________" << endl;
	cout << "|                    Meal Sales For Today                  |" <<  endl;
	cout << "|Meal Type             | Quantity | Sold Sales Amount (RM) |" << endl;
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	cout << "|Nasi Lemak (N)        |" << left << setw(10) << quantity[0] << "|" << left << setw(24)<<quantity[0]*price[0]<< "|" << endl;
	cout << "|Chicken Rice (C)      |" << left << setw(10) << quantity[1] << "|" << left << setw(24)<<quantity[1]*price[1]<< "|" << endl;
	cout << "|Masala Dosa (M)       |" << left << setw(10) << quantity[2] << "|" << left << setw(24)<<quantity[2]*price[2]<< "|" << endl;
	cout << "|Hamburger (H)         |" << left << setw(10) << quantity[3] << "|" << left << setw(24)<<quantity[3]*price[3]<< "|" << endl;
	cout << "|Fish and Chips (F)    |" << left << setw(10) << quantity[4] << "|" << left << setw(24)<<quantity[4]*price[4]<< "|" << endl;
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;


	//loop for total quantity and total sales
	for(int i =0; i < sizeof(menu)/sizeof(menu[0]); i++){
		totalquantity += quantity[i];
		totalsales += (quantity[i]*price[i]);

	}
	cout << left << setw(24)  << " Totals "<<  left << setw(11) << totalquantity  << totalsales << endl;
	cout << left << setw(24)  << " ~~~~~~~"<<  left << setw(11) << "~~~~~~~~"  << "~~~~~~~~~" << endl;

	cout << "\nTOTAL SST charges        = RM " << (tax * totalsales) << endl;
	cout << "TOTAL Ringgit collected  = RM " << (tax * totalsales) + totalsales << endl;

	cout << "\nYou are not obligated to win. You are obligated to keep trying to do the best you can every day." << endl;

	//end time/date
	time_t end = time(0);
	char* endt = ctime(&end);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\nEnd time  : " << endt;
	

	return 0;	


}





