#include<iostream>
#include<iomanip>
#include<limits>

using namespace std;

const double miniGweight = 49.9;
const double maxGweight = 50.1;
const double miniCweight = 24.9;
const double maxCweight = 25.1;

const double regulerCprice = 3.0;
const double regulerGprice = 2.0;
const double regulerSprice = 2.0;

const int specialCcount = 1;
const int specialGcount = 2;
const int specialScount = 2;
const double specailPackprice = 10.0;

void checkSack(double& totalwieghht, int& rejectsack)
{
	char contents;
	double weight;
	cout << "Enetr contents you want (C for cement, G for gracel, S for sand): ";
	cin >> contents;
	contents = toupper(contents);

	cout << "Enter wieght in KG: ";
	cin >> weight;

	if (contents != 'C' && contents != 'G' && contents != 'S')
	{
		cout << "Invalid Entry." << endl;
		rejectsack++;
		return;
	}

	if ((contents == 'C' && (weight < miniCweight || weight > maxCweight)) ||
		((contents == 'G' || contents == 'S') && (weight < miniGweight || weight > maxGweight)))
	{
		cout << "Invalid Entry." << endl;
		rejectsack++;
		return;
	}
		
	totalwieghht += weight;

}

void processOrder()
{
	int numSackC = 0, numSackG = 0, numSackS = 0;
	int rejectedSacks = 0, numspecialpack;
	double totalweight = 0.0, regularprice, disprice, totalprice;

	cout << "Enter number of sack for each content." << endl;

	cout << "Number of sack of cement: ";
	cin >> numSackC;
	for (int a = 0; a < numSackC; a++)
	{
		checkSack(totalweight, rejectedSacks);
	}

	cout << "Number of sack for Gravel: ";
	cin >> numSackG;
	for (int b = 0; b < numSackG; b++)
	{
		checkSack(totalweight, rejectedSacks);
	}

	cout << "Number of sack for Sand: ";
	cin >> numSackS;
	for (int c = 0; c < numSackS; c++)
	{
		checkSack(totalweight, rejectedSacks);
	}

	cout << endl;
	cout << "Total Weight of Order: " << totalweight << endl;
	cout << "Number of rejected Sacks: " << rejectedSacks << endl;

	regularprice = numSackC * regulerCprice + numSackG * regulerGprice + numSackS * regulerSprice;

	numspecialpack = min(numSackC / specialCcount, min(numSackG / specialGcount, numSackS / specialScount));

	disprice = numspecialpack * specailPackprice;
	totalprice = regularprice - disprice;

	cout << "Reguler Price: $" << regularprice << endl;
	cout << "Number of special pack: " << numspecialpack << endl;
	cout << "After discount Price: " << totalprice << endl;
	cout << "Saved Amount: " << disprice << endl;

}

int main()
{
	processOrder();
	return 0;
}